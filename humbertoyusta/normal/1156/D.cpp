#include<bits/stdc++.h>
#define int long long
#define maxn 200005
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int n, dp[2][maxn][2], ans;
vector<ii> g[maxn];

void dfs(int u,int p){

    for( auto v : g[u] )
        if( v.f != p )
            dfs(v.f,u);

    dp[0][u][0] = 1;
    dp[1][u][1] = 1;

    for( auto v : g[u] )
        if( v.f != p ){

            if( v.s == 0 ){
                ans += dp[0][u][0] * ( dp[1][v.f][0] + dp[1][v.f][1] );
                ans += dp[0][v.f][0] * ( dp[1][u][0] + dp[1][u][1] );
            }
            if( v.s == 1 ){
                ans += ( dp[0][u][0] + dp[0][u][1] ) * dp[1][v.f][1];
                ans += ( dp[0][v.f][0] + dp[0][v.f][1] ) * dp[1][u][1];
            }

            if( v.s == 0 ){
                dp[0][u][0] += dp[0][v.f][0];
                dp[1][u][0] += dp[1][v.f][0] + dp[1][v.f][1];
            }
            if( v.s == 1 ){
                dp[0][u][1] += dp[0][v.f][0] + dp[0][v.f][1];
                dp[1][u][1] += dp[1][v.f][1];
            }
        }

}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dfs(1,1);

    cout << ans << '\n';

    return 0;
}