#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
const ll mod = 998244353;
ll dp1[3005][3005];
ll dp[3005][3005];
ll ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    for(int i = 0; i <= T.size(); i++) {
        dp1[i][i] = 1;
    }
    for(int delta = 1; delta <= T.size(); delta++) {
        for(int i = 0; i + delta <= T.size(); i++) {
            int j = i + delta;
            if(S[delta-1] == T[i]) {
                dp1[i][j] += dp1[i+1][j];
                dp1[i][j] %= mod;
            }
            if(S[delta-1] == T[j-1]) {
                dp1[i][j] += dp1[i][j-1];
                dp1[i][j] %= mod;
            }
        }
    }
    /*
    for(int i = 0; i <= S.size(); i++) {
        dp[i][i] += dp1[0][i];
    }
    */
    for(int i = 0; i < S.size(); i++) {
        if(T.size() >= i) dp[i][i] = dp1[T.size() - i][T.size()];
        else dp[i][i] = 0;
        for(int j = 0; j <= T.size(); j++) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
            if(j == 0) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            }
            if(j < T.size() and T[T.size() - 1 - j] == S[i]) {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= mod;
            }
        }
        ans += dp[i][T.size()];
        ans %= mod;
    }
    dp[S.size()][S.size()] = dp1[0][S.size()];
    ans += dp[S.size()][T.size()];
    ans %= mod;
    /*
    for(int i = 0; i <= S.size(); i++) {
        for(int j = 0; j <= T.size(); j++) {
            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    */
    cout << ans << endl;
    return 0;
}