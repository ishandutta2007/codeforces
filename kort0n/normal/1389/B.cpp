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
//const ll mod = 1000000007;
ll dp[105000][7];
void solve() {
    ll N, K, Z;
    cin >> N >> K >> Z;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= Z; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for(int k = 0; k <= Z; k++) {
        for(int i = 0; i < N; i++) {
            if(i < N - 1) chmax(dp[i+1][k], dp[i][k] + a[i+1]);
            if(i > 0 and k < Z) {
                chmax(dp[i-1][k+1], dp[i][k] + a[i-1]);
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        for(ll k = 0; k <= Z; k++) {
            ll num = i + 2 * k;
            if(num != K) continue;
            chmax(ans, dp[i][k]);
        }
    }
    cout << ans + a[0] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}