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
ll N, M, K;
ll dp[5050][5050];
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b % 2) ret = ret * a % mod;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    dp[0][0] = 1;
    for(ll i = 0; i < K; i++) {
        for(int j = K; j >= 0; j--) {
            dp[i+1][j] += j * dp[i][j];
            dp[i+1][j+1] += (N - j) * dp[i][j];
            dp[i+1][j] %= mod;
            dp[i+1][j+1] %= mod;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= K; i++) {
        ll tmp = dp[K][i];
        ll minv = beki(M, mod - 2);
        tmp *= beki(minv, i);
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}