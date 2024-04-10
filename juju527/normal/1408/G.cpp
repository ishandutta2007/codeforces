//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1505,mod=998244353;
int n;
int a[maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
struct edge{
	int u,v,w;
	bool operator <(edge i)const{return w<i.w;}
}buf[maxn*maxn];
int tot;
vec e[2*maxn];
int f[2*maxn],cnt[2*maxn],siz[2*maxn];
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
int dfsnum,mn[2*maxn];
vec trans[maxn];
int dp[maxn][maxn];
void dfs(int x){
	mn[x]=1e9;
	if(x<=n)mn[x]=++dfsnum;
	for(auto y:e[x])dfs(y),mn[x]=min(mn[x],mn[y]);
	if(cnt[x]==siz[x]*(siz[x]-1)/2)trans[mn[x]].eb(mn[x]+siz[x]-1);
	return ;
}
int main(){
    int len=0;
	n=read();tot=n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)buf[++len]=(edge){i,j,a[i][j]};
	sort(buf+1,buf+len+1);
	for(int i=1;i<=2*n;i++)f[i]=i,siz[i]=(i<=n);
	for(int i=1;i<=len;i++){
		int u=find(buf[i].u),v=find(buf[i].v);
		if(u==v){cnt[u]++;continue;}
		f[u]=f[v]=++tot;
		siz[tot]+=siz[u],siz[tot]+=siz[v];
		cnt[tot]++,cnt[tot]+=cnt[u],cnt[tot]+=cnt[v];
		e[tot].eb(u),e[tot].eb(v);
	}
	dfs(tot);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(auto k:trans[i+1])
				add(dp[k][j+1],dp[i][j]);
	for(int i=1;i<=n;i++)printf("%d ",dp[n][i]);
	puts("");
    return 0;
}