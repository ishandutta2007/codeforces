#include <cstdio>
#include <algorithm>

int n,head[200001],nxt[400001],b[400001],k,dep[200001],K;
bool vis[200001];
int sum[200001];
struct point{
	int dep,size,ord;
}num[200001];
bool cmp(point a,point b){
	return (a.dep-a.size)>(b.dep-b.size);
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	num[x].dep=num[f].dep+1;
	num[x].size=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			num[x].size+=num[b[i]].size;
		}
}
long long fin;
void getans(int x,int f){
	sum[x]=sum[f]+(!vis[x]);
	if(vis[x])fin+=sum[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getans(b[i],x);
		}
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	for(int i=1;i<=n;i++)num[i].ord=i;
	dfs(1,0);
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=K;i++)vis[num[i].ord]=1;
	getans(1,0);
	printf("%lld\n",fin);
}