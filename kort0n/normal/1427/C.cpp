#include <bits/stdc++.h>
//#include <atcoder/all>
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
ll R, N;
ll t[100050], x[100050], y[100050];
ll dp[100050];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    t[0] = 0;
    x[0] = 1;
    y[0] = 1;
    cin >> R >> N;
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    ll maxi = -INF;
    for(int i = 1; i <= N; i++) {
        if(i >= 1000) {
            chmax(maxi, dp[i-1000]);
        }
        dp[i] = -INF;
        chmax(dp[i], maxi + 1);
        for(int j = max(i - 1000, 0); j < i; j++) {
            if(abs(x[j] - x[i]) + abs(y[j] - y[i]) > t[i] - t[j]) continue;
            chmax(dp[i], dp[j] + 1);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}