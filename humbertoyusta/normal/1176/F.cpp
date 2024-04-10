#include <bits/stdc++.h>
#define maxn 200005
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,m,u,v;
ll dp[maxn][11];
vector<ll> g[maxn][4];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    memset( dp , -50 , sizeof(dp) );
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        cin >> m;

        for(int j=1; j<=3; j++)
            g[i][j].clear();
        for(int j=1; j<=m; j++){
            cin >> u >> v;
            g[i][u].push_back(v);
        }
        for(int j=1; j<=3; j++){
            stable_sort(g[i][j].begin(),g[i][j].end());
            reverse(g[i][j].begin(),g[i][j].end());
        }
    }

    for(int i=1; i<=n; i++){

        for(int j=0; j<10; j++){

            dp[i][j] = dp[i-1][j];

            if( !g[i][1].empty() )
                dp[i][j] = max( dp[i][j] , dp[i-1][(j+10-1)%10] + g[i][1][0] + g[i][1][0] * ( j == 0 ) );

            if( !g[i][2].empty() )
                dp[i][j] = max( dp[i][j] , dp[i-1][(j+10-1)%10] + g[i][2][0] + g[i][2][0] * ( j == 0 ) );

            if( !g[i][3].empty() )
                dp[i][j] = max( dp[i][j] , dp[i-1][(j+10-1)%10] + g[i][3][0] + g[i][3][0] * ( j == 0 ) );

            if( g[i][1].size() >= 2 )
                dp[i][j] = max( dp[i][j] , dp[i-1][(j+10-2)%10] + g[i][1][0] + g[i][1][1] + max( g[i][1][0] , g[i][1][1] ) * ( j <= 1 ) );

            if( !g[i][1].empty() && !g[i][2].empty() )
                dp[i][j] = max( dp[i][j] , dp[i-1][(j+10-2)%10] + g[i][1][0] + g[i][2][0] + max( g[i][1][0] , g[i][2][0] ) * ( j <= 1 ) );

            if( g[i][1].size() >= 3 )
                dp[i][j] = max( dp[i][j] , dp[i-1][(j+10-3)%10] + g[i][1][0] + g[i][1][1] + g[i][1][2] + max( g[i][1][0] , max( g[i][1][1] , g[i][1][2] ) ) * ( j <= 2 ) );
        }

    }

    ll ans = -inf;
    for(int i=0; i<10; i++)
        ans = max( ans , dp[n][i] );
    cout << ans << '\n';

    return 0;
}