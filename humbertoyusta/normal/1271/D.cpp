#include<bits/stdc++.h>
#define maxn 5005
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n, m, K, dp[maxn][maxn], a[maxn], b[maxn], c[maxn], pg[maxn];
vector<int> g[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> m >> K;

    for(int i=1; i<=n; i++)
        cin >> a[i] >> b[i] >> c[i];

    b[0] = K;

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        pg[v] = max( pg[v] , u );
    }
    for(int i=1; i<=n; i++)
        pg[i] = max( pg[i] , i );

    for(int i=1; i<=n; i++){
        g[pg[i]].push_back(i);
    }

    for(int i=0; i<=n+1; i++)
        fill( dp[i] , dp[i] + maxn , -inf );

    dp[0][0] = 0;
    for(int i=1; i<=n+1; i++){
        for(int j=a[i]; j<=maxn-5; j++)
            if( j - b[i-1] >= 0 ){
                dp[i][j] = max( dp[i][j] , dp[i-1][j-b[i-1]] );
            }
        for( auto j : g[i-1] )
            for(int k=a[i]; k<=maxn-5; k++){
                dp[i][k] = max( dp[i][k] , dp[i][k+1] + c[j] );
            }
    }

    int ans = -1;
    for(int i=0; i<=maxn-5; i++)
        ans = max( ans , dp[n+1][i] );
    cout << ans << '\n';

    return 0;
}