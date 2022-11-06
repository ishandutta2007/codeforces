#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
const int N=100005,N2=2000000;
int n,m,r,lust,dfn[N],d[N],l[N],c,a[N],tre[N2],tot,root[N],lson[N2],rson[N2],lis[N];
vector<int> e[N];
bool cmp(int a,int b){
	return d[a]<d[b];
}
int rd(){
	int a=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
	return a;
}
void out(int a){//printf("out %d\n",a);
	int x[10],t=0;
	while(a)x[t++]=a%10,a/=10;
	while(t--)putchar(x[t]^48);
	putchar('\n');
}
void dfs(int v,int dep){
	dfn[v]=++c;
	d[v]=dep;
	for(int i=0;i<e[v].size();i++){
		int u=e[v][i];
		if(!dfn[u])dfs(u,dep+1);
	}
	l[v]=c;
}
void add(int l,int r,int x,int v,int c1,int &c2){
	c2=++tot,tre[c2]=min(tre[c1],v);
	if(l==r)return;
	if(x<=mid)rson[c2]=rson[c1],add(l,mid,x,v,lson[c1],lson[c2]);
	else lson[c2]=lson[c1],add(mid+1,r,x,v,rson[c1],rson[c2]);
}
int query(int l,int r,int L,int R,int c){
	if(r<L||R<l)return 1<<30;
	if(L<=l&&r<=R)return tre[c];
	return min(query(l,mid,L,R,lson[c]),query(mid+1,r,L,R,rson[c]));
}
int main(){
	//freopen("input.txt","r",stdin);
	tre[0]=1<<30;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b),e[b].push_back(a);
	}
	dfs(r,1);
	for(int i=1;i<=n;i++)lis[i]=i;sort(lis+1,lis+n+1,cmp);
	for(int i=1;i<=n;i++){int j=lis[i];add(1,n,dfn[j],a[j],root[i-1],root[i]);}
	for(int i=1;i<=n;i++)lis[i]=d[lis[i]];
	//for(int i=1;i<=n;i++)printf("%d\n",root[i]);
	//for(int i=0;i<=tot;i++)printf("%d : %d %d %d\n",i,tre[i],lson[i],rson[i]);
	scanf("%d",&m);
	while(m--){
		int a=(rd()+lust)%n+1,b=(rd()+lust)%n;
		//printf("a=%d b=%d\n",a,b);
		//printf("query %d %d %d\n",dfn[a],l[a],upper_bound(lis+1,lis+n+1,d[a]+b)-lis-1);
		out(lust=query(1,n,dfn[a],l[a],root[upper_bound(lis+1,lis+n+1,d[a]+b)-lis-1]));
	}
	return 0;
}