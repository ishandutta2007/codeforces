#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 600+7;
const int MAXN = 1e9+7;
int E[N][N],dist[N][N],act[N][N];
vector<pair<int,int> > Q[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j)
            dist[i][j] = MAXN,E[i][j] = -1;
        dist[i][i] = 0;
    }
    for(int i = 1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v] = dist[v][u] = E[u][v] = E[v][u] = w;
    }
    for(int k = 1;k<=n;++k){
        for(int a = 1;a<=n;++a){
            for(int b = 1;b<=n;++b){
                dist[a][b] = min(dist[a][b],dist[a][k]+dist[b][k]);
            }
        }
    }
    int q;
    cin>>q;
    for(int i = 1;i<=q;++i){
        int u,v,L;
        cin>>u>>v>>L;
        Q[u].push_back({v,L});
    }
    for(int u = 1;u<=n;++u){
        for(int x = 1;x<=n;++x){
            int mx = -MAXN;
            for(auto [v,L]:Q[u]){
                L-=dist[v][x];
                mx = max(mx,L);
            }

            for(int y = 1;y<=n;++y){
                if (E[x][y]==-1)
                    continue;
                if (E[x][y]+dist[y][u]<=mx){
                    act[x][y] = act[y][x] = 1;
                }
            }

        }
    }
    int res = 0;
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j)
            res+=act[i][j];
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}