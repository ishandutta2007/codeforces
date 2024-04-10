//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

const int N = 207;
const int INF = 1E9;
vector<pair<int,int> > G[N];
int dist[N][N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=n;++j)
            if (i!=j)
                dist[i][j] = INF;
    for(int i = 1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        dist[u][v] = dist[v][u] = w;
    }
    for(int k = 1;k<=n;++k)
        for(int i = 1;i<=n;++i)
            for(int j = 1;j<=n;++j)
                dist[i][j] = min(dist[i][k]+dist[j][k],dist[i][j]);
    ld res = INF;
    for(int i = 1;i<=n;++i){
        int r = 0;
        for(int j = 1;j<=n;++j)
            r = max(r,dist[i][j]);
        res = min(res,ld(r));
    }
    for(int u = 1;u<=n;++u){
        for(int v = 1;v<=n;++v){
            set<pair<int,int> > A,B;
            for(int i = 1;i<=n;++i){
                A.insert({dist[u][i],i});
            }
            while(!A.empty()){
                int i = A.rbegin()->second;
                A.erase(*A.rbegin());
                B.insert({dist[v][i],i});
                int val1 = 0,val2 = 0;
                if (!A.empty())
                    val1 = A.rbegin()->first;
                if (!B.empty())
                    val2 = B.rbegin()->first;
                // val1+x == val2+w-x -> x*2 = val2-val1+w
                ld x = min(ld(dist[u][v]),ld(val2-val1+dist[u][v])/2.0);
                res = min(res,max(x+ld(val1),ld(val2)+dist[u][v]-x));
            }
        }
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}