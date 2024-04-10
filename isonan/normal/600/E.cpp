#include <cstdio>
#include <algorithm>
using namespace std;

int lson[8000001],rson[8000001],mx[8000001];
int head[100001],nxt[200001],b[200001],k,n,root[100001],c[100001];
long long sum[8000001],cnt,ans[100001];
int push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void pushup(int rt){
    mx[rt]=max(mx[lson[rt]],mx[rson[rt]]);
    sum[rt]=0;
    if(mx[rt]==mx[lson[rt]])sum[rt]+=sum[lson[rt]];
    if(mx[rt]==mx[rson[rt]])sum[rt]+=sum[rson[rt]];
}
int merge(int a,int b,int l,int r){
	if(!a||!b)return a|b;
	if(l==r){
		mx[a]+=mx[b];
		sum[a]=l;
		return a;
	}
	lson[a]=merge(lson[a],lson[b],l,(l+r)>>1);
	rson[a]=merge(rson[a],rson[b],((l+r)>>1)+1,r);
	pushup(a);
	return a;
}
void add(int &pos,int l,int r,int e){
	if(!pos)pos=++cnt,lson[pos]=rson[pos]=0;
	if(l==r){
		mx[pos]=1;
		sum[pos]=e;
		return;
	}
	if((l+r)>>1>=e)add(lson[pos],l,(l+r)>>1,e);
	else add(rson[pos],((l+r)>>1)+1,r,e);
	pushup(pos);
}
void dfs(int x,int f){
	add(root[x],1,n,c[x]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			root[x]=merge(root[x],root[b[i]],1,n);
		}
	ans[x]=sum[root[x]];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s); 
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%I64d ",ans[i]);
}