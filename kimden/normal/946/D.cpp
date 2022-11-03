#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    vector<vector<int>> v(n);
    const int INF = 500000000;//m + 9;
    vector<vector<int>> mintimeofkpairs(n, vector<int>(m + 1, INF));
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '1'){
                v[i].push_back(j);
            }
        }
        cnt += (int)v[i].size();
        mintimeofkpairs[i][0] = 0;
        for(int j = 0; j < v[i].size(); ++j){
            for(int u = j; u < v[i].size(); ++u){
                mintimeofkpairs[i][u - j + 1] = min(mintimeofkpairs[i][u - j + 1], v[i][u] - v[i][j] + 1);
            }
        }
    }
   /* for(int i = 0; i < n; ++i){
        for(int j = 0; j <= m; ++j){
            cerr << mintimeofkpairs[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;*/
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
        for(int kold = 0; kold <= k; ++kold){
            for(int deltak = 0; deltak + kold <= k && deltak <= v[i].size(); ++deltak){
                int o = mintimeofkpairs[i][(int)v[i].size() - deltak];
                if(o < INF)
                    dp[i + 1][kold + deltak] = min(dp[i + 1][kold + deltak], dp[i][kold] + o);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= k; ++i){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;



}