#include <queue>
#include <cstdio>
#include <algorithm>

std::priority_queue<int>heap[2000001];
int New[2000001],n,orig[200001],lim,L[100001],R[100001],mn[2000001];
struct point{
	int x,ord,t;
}num[200001];
bool del[100001],ans[100001];
int fin=1;
bool cmp(point a,point b){return (a.x<b.x)||(a.x==b.x&&a.t>b.t);}
void maintain(int x){while(!heap[x].empty()&&del[heap[x].top()])heap[x].pop();}
void pushup(int x){
	New[x]=std::max(New[x<<1],New[x<<1|1]);
	mn[x]=std::min(mn[x<<1],mn[x<<1|1]);
	maintain(x);
	if(!heap[x].empty()){
		int now=heap[x].top();
		if(now>New[x]&&ans[now])New[x]=0;
		else if(now>mn[x]&&!ans[now])New[x]=std::max(New[x],now);
		mn[x]=std::max(mn[x],now);
	}
}
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		heap[root].push(x);
		pushup(root);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
void chk(int root,int l,int r,int el,int er){
//	printf("chk %d %d %d %d %d\n",root,l,r,el,er);
	if(el>r||er<l)return;
	if(el<=l&&er>=r)return pushup(root);
	chk(root<<1,l,(l+r)>>1,el,er);
	chk(root<<1|1,((l+r)>>1)+1,r,el,er);
	pushup(root);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1,x1,y1,x2,y2;i<=n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		num[(i<<1)-1]=(point){x1,i,1};
		num[i<<1]=(point){x2,i,-1};
		orig[(i<<1)-1]=L[i]=y1;
		orig[i<<1]=R[i]=y2;
	}
	std::sort(orig+1,orig+(n<<1)+1);
	lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
	for(int i=1;i<=n;i++)L[i]=std::lower_bound(orig+1,orig+lim+1,L[i])-orig,R[i]=std::lower_bound(orig+1,orig+lim+1,R[i])-orig-1;
//	for(int i=1;i<=n;i++)printf("%d %d\n",L[i],R[i]);
//	printf("%d\n",lim);
	std::sort(num+1,num+(n<<1)+1,cmp);
	for(int i=1;i<=n<<1;i++){
		int v=num[i].ord;
		if(num[i].t==1)add(1,1,lim,L[v],R[v],v);
		else del[v]=1,chk(1,1,lim,L[v],R[v]);
		if((i==(n<<1))||num[i].x!=num[i+1].x)
			while(New[1]){
				++fin;
				int u=New[1];
//				printf("%d\n",u);
				ans[u]=1;
				chk(1,1,lim,L[u],R[u]);
			}
	}
	printf("%d\n",fin);
}
//4
//0 0 1 2
//0 0 2 1
//0 1 2 2
//1 0 2 2