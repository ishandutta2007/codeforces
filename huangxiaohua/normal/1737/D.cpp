#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll f[505][505],g[505][505],d[505][505];
bool vis[505];

vector<int> v[505];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			v[i].clear();
			for(j=1;j<=n;j++){
				f[i][j]=g[i][j]=1e18;
			}
		}
		for(i=1;i<=m;i++){
			ll l,r,w;
			cin>>l>>r>>w;
			if(f[l][r]>1e17){
				v[l].push_back(r);
				v[r].push_back(l);
			}
			f[l][r]=min(f[l][r],w);
			f[r][l]=min(f[r][l],w);
			g[l][r]=min(g[l][r],w);
			g[r][l]=min(g[r][l],w);
		}
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(i=1;i<=n;i++){
			memset(d[i],-1,sizeof(d[i]));
			queue<int> q;
			q.push(i);
			d[i][i]=0;
			while(!q.empty()){
				k=q.front();q.pop();
				for(auto j:v[k]){
					if(d[i][j]==-1){
						d[i][j]=d[i][k]+1;
						q.push(j);
					}
				}
			}
		}
		ll res=f[1][n];
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(g[i][j]>1e17)continue;
				for(k=1;k<=n;k++){
					ll sb=min(d[i][k],d[j][k])+d[1][k]+d[n][k]+2;
					//printf("NMSL%d %d %d %d\n",i,j,k,sb);
					sb=min({sb,d[1][i]+d[n][j]+1,d[1][j]+d[n][i]+1});
					res=min(res,sb*g[i][j]);
				}
			}
		}
		cout<<res<<'\n';
	}
}