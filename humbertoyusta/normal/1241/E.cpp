#include<bits/stdc++.h>
#define int long long
#define maxn 500005
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int tc, n, dp[maxn][2], k;
vector<ii> g[maxn];
vector<pair<int,ii>> V;

void dfs(int u,int p){

    for( auto v : g[u] )
        if( v.f != p )
            dfs(v.f,u);

    if( g[u].size() == 1 && u != 1 ) return;

    V.clear();
    for( auto v : g[u] )
        if( v.f != p ){
            V.push_back({(dp[v.f][0]+v.s)-dp[v.f][1],{dp[v.f][0]+v.s,dp[v.f][1]}});
        }
    stable_sort( V.begin() , V.end() );
    reverse( V.begin() , V.end() );

    int cnt = 0;
    for(int i=0; i<V.size(); i++){
        if( cnt < k && V[i].f >= 0 ){
            dp[u][1] += V[i].s.f;
            cnt++;
        }
        else{
            dp[u][1] += V[i].s.s;
        }
    }

    cnt = 0;
    for(int i=0; i<V.size(); i++){
        if( cnt < k - 1 && V[i].f >= 0 ){
            dp[u][0] += V[i].s.f;
            cnt++;
        }
        else{
            dp[u][0] += V[i].s.s;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

  //  freopen("a.in","r",stdin);

    cin >> tc;
    while( tc-- ){

        cin >> n >> k;

        for(int i=1; i<=n; i++){
            g[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }

        for(int i=1; i<n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        dfs(1,1);

        cout << max( dp[1][0] , dp[1][1] ) << '\n';
    }

    return 0;
}