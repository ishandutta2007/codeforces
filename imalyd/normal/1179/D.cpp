#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll sqr(int x){return ((ll)x)*x;}
inline void cmin(ll &a,ll b){if(a>b)a=b;}
const int N=500005;
const ll inf=1000000000000000000ll;
int sz[N],vis[N],s2[N],szq[N<<1];
ll seq[N<<1],mn[N][2],dp[N],nn,ans;
int n2,n;
vector<int>e[N];
void dfs(int v,int f){
	int u,i,j,tot=0,t2=0;
	sz[v]=1;
	for(i=0;i<e[v].size();++i){
		u=e[v][i];
		if(u!=f){
			dfs(u,v);
			sz[v]+=sz[u];
		}
	}
	dp[v]=sqr(sz[v]);
	for(i=0;i<e[v].size();++i){
		u=e[v][i];
		if(u!=f){
			if(vis[sz[u]]==v){
				if(dp[u]<=mn[sz[u]][0]){
					mn[sz[u]][1]=mn[sz[u]][0];
					mn[sz[u]][0]=dp[u];
				}else cmin(mn[sz[u]][1],dp[u]);
			}else{
				s2 [++t2]=sz[u];
				vis[sz[u]]=v;
				mn [sz[u]][0]=dp[u];
				mn [sz[u]][1]=inf  ;
			}
			cmin(dp[v],dp[u]+sqr(sz[v]-sz[u]));
		}
	}
	for(i=1;i<=t2;++i){
		{szq[++tot]=s2[i];seq[tot]=mn[s2[i]][0]+((ll)s2[i])*(s2[i]-n2);}
		if(mn[s2[i]][1]!=inf)
		{szq[++tot]=s2[i];seq[tot]=mn[s2[i]][1]+((ll)s2[i])*(s2[i]-n2);}
	}
	for(i=1;i<=tot;++i)cmin(ans,nn+seq[i]);
	for(i=1;i< tot;++i)for(j=tot;j>i;--j)cmin(ans,nn+seq[i]+seq[j]+((ll)szq[i])*(szq[j]<<1));
}
int main(){
	int i,v,u;
	scanf("%d",&n);n2=n<<1;ans=nn=sqr(n);
	for(i=1;i<n;++i){
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1,0);
	printf("%I64d",nn-((n+ans)>>1));
	return 0;
}