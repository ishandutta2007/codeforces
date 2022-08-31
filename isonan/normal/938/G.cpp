#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

int n,m,tot,L[400001];
struct edge{
	int u,v,val;
}num[400001];
int Base[31],time[31],tem[31];
int f[200001],Xor[200001],rank[200001];
int q[2][200001];
int find(int x){return f[x]?find(f[x]):x;}
int val(int x){return f[x]?val(f[x])^Xor[x]:0;}
int stk[3][200001],top;
void merge(int a,int b,int v){
	if(rank[a]>rank[b])std::swap(a,b);
//	printf("merge %d %d %d\n",a,b,v);
	++top;
	stk[0][top]=rank[b];
	stk[1][top]=a;
	stk[2][top]=b;
	rank[b]=std::max(rank[b],rank[a]+1);
	f[a]=b;
	Xor[a]=v;
}
void rollback(){
	f[stk[1][top]]=0;
	rank[stk[2][top]]=stk[0][top];
	--top;
}
void insert(int x,int t){
//	printf("insert %d %d\n",x,t);
	for(int i=29;~i;--i)
		if(x&(1<<i)){
			if(Base[i])x^=Base[i];
			else{
				Base[i]=x,time[i]=t;
				return;
			}
		}
}
std::vector<edge>se[4000001];
void add(int root,int l,int r,int el,int er,edge e){
	if(el>r||er<l)return;
	if(el<=l&&er>=r)return se[root].push_back(e);
	add(root<<1,l,(l+r)>>1,el,er,e);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,e);
}
int getmx(int x){
	for(int i=29;~i;--i)
		if((x^Base[i])<x)x^=Base[i];
	return x;
}
void solve(int root,int l,int r){
	int last=top;
	for(int i=0;i<se[root].size();i++){
		int u=find(se[root][i].u),v=find(se[root][i].v);
		int x=val(se[root][i].u)^val(se[root][i].v)^se[root][i].val;
//		printf("%d %d %d\n",se[root][i].u,se[root][i].v,se[root][i].val);
		if(u==v){
			insert(x,root);
		}
		else{
			merge(u,v,x);
		}
	}
	if(l==r){
		if(q[0][l]){
//			printf("%d %d %d\n",find(q[0][l]),val(q[0][l]),val(q[1][l]));
			printf("%d\n",getmx(val(q[0][l])^val(q[1][l])));
		}
	}
	else{
		solve(root<<1,l,(l+r)>>1);
		solve(root<<1|1,((l+r)>>1)+1,r);
	}
	while(top>last)rollback();
	for(int i=0;i<30;i++)if(time[i]==root)Base[i]=0;
}
std::map<std::pair<int,int>,int>map;
int main(){
////	freopen("in.txt","r",stdin);
////	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		++tot;
		scanf("%d%d%d",&num[tot].u,&num[tot].v,&num[tot].val);
		map[std::make_pair(num[tot].u,num[tot].v)]=tot;
		L[tot]=1;
	}
	int q;
	scanf("%d",&q);
	for(int i=1,opt,x,y;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			++tot;
			scanf("%d%d%d",&num[tot].u,&num[tot].v,&num[tot].val);
			map[std::make_pair(num[tot].u,num[tot].v)]=tot;
			L[tot]=i;
		}
		else if(opt==2){
			scanf("%d%d",&x,&y);
			int &p=map[std::make_pair(x,y)];
			add(1,1,q,L[p],i-1,num[p]);
			L[p]=-1;
		}
		else{
			scanf("%d%d",&::q[0][i],&::q[1][i]);
		}
	}
	for(int i=1;i<=tot;i++)if(~L[i])add(1,1,q,L[i],q,num[i]);
	solve(1,1,q);
}