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
ll N;
const ll MAX = 60;
ll ans = INF;
ll dp[300010][61];
ll a[301000];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= MAX; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j <= MAX; j++) {
            if(j + a[i] / 1000 <= MAX) {
                chmin(dp[i+1][j+a[i]/1000], dp[i][j] + a[i]);
            }
            ll delta = min(j, a[i] / 100);
            chmin(dp[i+1][j-delta], dp[i][j] + a[i] - 100 * delta);
        }
    }
    ll ans = INF;
    for(int i = 0; i <= MAX; i++) {
        chmin(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}