#include <cstdio>
#include <vector>
#include <algorithm>
 
int n,m,k,q,edg[500001][4];
int f[50000001],rnk[50000001],stk[7000001][3],top,cnt,col[500001],Q[500001][3];
int find(int x){return f[x]?find(f[x]):x;}
std::vector<int>vec[2000001];
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
//		printf("add %d %d %d\n",l,r,x);
		vec[root].push_back(x);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
void add(int c,int l,int r,int e){
	add(1,1,q,l,r,e);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(rnk[u]>rnk[v])std::swap(u,v);
	if(u==v)return;
//	printf("merge %d %d\n",u,v);
	++top;
	stk[top][0]=v;
	stk[top][1]=u;
	stk[top][2]=rnk[v];
	f[u]=v;
	rnk[v]=std::max(rnk[v],rnk[u]+1);
}
void rollback(){
	rnk[stk[top][0]]=stk[top][2];
//	printf("rollback %d %d\n",stk[top][0],stk[top][1]);
	f[stk[top][1]]=0;
	--top;
}
void Que(int root,int l,int r){
//	printf("start %d %d %d %d\n",root,l,r,top);
	int cnt=top;
	while(!vec[root].empty()){
		int x=vec[root].back();
		vec[root].pop_back();
		int a=edg[x][0]+(n<<1)*(col[x]-1),b=edg[x][1]+(n<<1)*(col[x]-1);
//		printf("%d %d %d %d %d %d %d %d %d %d %d\n",root,l,r,num[u].e,num[u].c,find(a),find(b),a,b,u,col[x]);
		merge(a,b+n);
		merge(b,a+n);
	}
	if(l==r){
		int x=Q[l][0];
		int a=edg[x][0]+(n<<1)*(Q[l][1]-1),b=edg[x][1]+(n<<1)*(Q[l][1]-1);
		if(find(a)==find(b)){
			puts("NO");
			if(col[x])add(col[x],l+1,Q[l][2],x);
		}
		else{
			puts("YES");
//			for(int j=1;j<l;j++){
//				if(Q[j][2]<l)continue;
//				int x=Q[j][0];
//				if(col[x]){
//					int a=edg[x][0]+(n<<1)*(col[x]-1),b=edg[x][1]+(n<<1)*(col[x]-1);
////					if(find(a)!=find(b+n))printf("%d %d %d\n",x,a,b);
//				}
//			}
			col[x]=Q[l][1];
			add(col[x],l+1,Q[l][2],x);
		}
//		printf("%d %d %d %d %d %d %d %d %d %d %d\n",root,l,r,num[u].e,num[u].c,find(a),find(b),a,b,u,col[x]);
//		printf("end %d %d %d %d\n",root,l,r,top);
		while(top>cnt)rollback();
		return;
	}
	Que(root<<1,l,(l+r)>>1);
	Que(root<<1|1,((l+r)>>1)+1,r);
	while(top>cnt)rollback();
//	printf("end %d %d %d %d\n",root,l,r,top);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=m;i++)scanf("%d%d",&edg[i][0],&edg[i][1]);
	for(int i=1,e,c;i<=q;i++){
		scanf("%d%d",&e,&c);
		Q[i][0]=e;
		Q[i][1]=c;
		if(edg[e][2])Q[edg[e][3]][2]=i-1;
		edg[e][3]=i;
		edg[e][2]=c;
	}
	for(int i=1;i<=m;i++)if(edg[i][2])Q[edg[i][3]][2]=q;
	Que(1,1,q);
	return 0;
}