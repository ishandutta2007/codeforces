#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

vector <int> graf[N+5];

int ima[N+5];
int dp[N+5][N+5];

void dfs(int v, int p, int d){
    ima[d]++;
    for(auto c : graf[v]) if(c != p) dfs(c, v, d+1);
}

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) graf[i].clear();
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    if(k == 2){
        cout << n*(n-1)/2 << "\n";
        return;
    }
    for(int i=1; i<=n; i++) dp[i][0] = 1;
    int res = 0;
    for(int root=1; root<=n; root++){
        for(auto c : graf[root]){
            dfs(c, root, 1);
            for(int i=1; i<=n; i++){
                for(int j=n; j>=1; j--){
                    dp[i][j] = add(dp[i][j], mul(ima[i], dp[i][j-1]));
                }
            }
            for(int i=1; i<=n; i++) ima[i] = 0;
        }
        for(int i=1; i<=n; i++) res = add(res, dp[i][k]);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = 0;
            }
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}