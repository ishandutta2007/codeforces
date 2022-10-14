#include <bits/stdc++.h>
#define maxn 300010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,dp[maxn][2],c[maxn],ans;
vector<int> g[maxn];

void dfs(int u,int p){
    for( auto v : g[u] )
        if( v != p ){
            dfs(v,u);
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    if( c[u] == 1 ) dp[u][0]++;
    if( c[u] == 2 ) dp[u][1]++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> c[i];

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    for(int i=2; i<=n; i++){
        if( dp[1][0] - dp[i][0] == 0 && dp[1][1] - dp[i][1] == dp[1][1] )
            ans++;
        if( dp[1][0] - dp[i][0] == dp[1][0] && dp[1][1] - dp[i][1] == 0 )
            ans++;
    }

    cout << ans << '\n';

    return 0;
}