#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=19;
int n,m;
int a[M];
int s[1<<18],g[M][M],vis[1<<18],in[M],p[1<<18],dp[1<<18],h[1<<18];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		s[1<<(--u)]+=w;
		s[1<<(--v)]-=w;
		g[u][v]=1;
	}
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				g[i][j]|=g[i][k]&g[k][j];
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(g[i][j])h[1<<i]|=1<<j;
		}
	}
	for(int t=0;t<1<<n;++t){
		dp[t]=-1e9;
		for(int i=0;i<n;++i){
			if(t>>i&1){
				h[t]|=h[1<<i];
				if(t!=1<<i)s[t]+=s[1<<i];
				for(int j=0;j<n;++j){
					if(t>>j&1){
						if(g[i][j]||g[j][i])vis[t]=1;
					}
				}
			}
		}
	}
	memset(p,-1,sizeof(p));
	p[0]=0;
	dp[0]=0;
	for(int i=1;i<1<<n;++i){
		for(int j=i;j;j=(j-1)&i){
			if(vis[j]==0&&(h[j]&i)==h[j]&&dp[i]<dp[i^j]&&p[i^j]!=-1){
				dp[i]=dp[i^j];
				p[i]=i^j;
			}
		}
		dp[i]+=s[i];
	}
	vector<int>ans;
	for(int u=(1<<n)-1;u;u=p[u]){
		ans.eb(u^p[u]);
	}
	reverse(ans.begin(),ans.end());
	int k=0;
	for(auto o:ans){
		for(int i=0;i<n;++i){
			if(o>>i&1)a[i]=k;
		}
		k++;
	}
	for(int i=0;i<n;++i)cout<<a[i]<<" \n"[i==n-1];
	return 0;
}