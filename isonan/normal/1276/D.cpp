#include <cstdio>
#include <vector>
#include <algorithm>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
std::pair<int,int>tem[200001];
int n,head[200001],nxt[400001],b[400001],k=1,f[200001][3],top,g[200010][2],h[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)dfs(b[i],x);
	top=0;
	int time=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)tem[++top]=std::make_pair(i,b[i]);
		else time=i;
	std::sort(tem+1,tem+top+1);
	g[0][0]=g[top+1][1]=1;
	for(int i=1;i<=top;i++)g[i][0]=mul(g[i-1][0],add(f[tem[i].second][0],f[tem[i].second][1]));
	for(int i=top;i;i--)g[i][1]=mul(g[i+1][1],h[tem[i].second]);
	f[x][1]=-1;
	for(int i=1;i<=top;i++){
		if(time>tem[i].first)f[x][0]=add(f[x][0],mul(mul(g[i-1][0],f[tem[i].second][2]),g[i+1][1]));
		else f[x][2]=add(f[x][2],mul(mul(g[i-1][0],f[tem[i].second][2]),g[i+1][1]));
	}
	h[x]=add(add(f[x][0],f[x][2]),g[top][0]);
	f[x][2]=add(f[x][2],g[top][0]);
	f[x][1]=1;
	for(int i=1;i<=top;i++)
		if(time>tem[i].first)f[x][1]=mul(f[x][1],add(f[tem[i].second][0],f[tem[i].second][1]));
		else f[x][1]=mul(f[x][1],h[tem[i].second]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	printf("%d\n",h[1]);
}