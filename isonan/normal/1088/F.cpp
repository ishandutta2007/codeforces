#include <cstdio>
#include <algorithm>
using std::min;

int fa[500001][21],n,head[500001],nxt[1000001],b[1000001],k,mn;
long long ans,a[500001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	if(f){
		long long tem=a[f];
		int p=f;
		fa[x][0]=f;
		for(int i=1;i<=20;i++){
			fa[x][i]=fa[fa[x][i-1]][i-1];
			if(fa[x][i])tem=min(tem,a[fa[x][i]]*(i+1));
			else tem=min(tem,a[mn]*(i+1));
		}
		ans+=tem+a[x];
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(!mn||a[mn]>a[i])mn=i;
	}
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	dfs(mn,0);
	printf("%lld\n",ans);
}