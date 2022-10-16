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
ll a, b, t;
long double f(ll q) {
    long double ret = (long double) a * q / (2 * q + 1);
    ret += (long double) b * (q + 1) / (2 * q + 1);
    return ret;
}

void solve() {
    cin >> b >> a >> t;
    if((a + b) >= 2 * t) {
        cout << 2 << endl;
        return;
    }
    ll ok = 0;
    ll ng = 1e9;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid) >= t) ok = mid;
        else ng = mid;
    }
    long double err = abs((long double)(a+b) / 2 - t);
    ll ans = 2;
    for(ll i = ok - 1; i <= ok + 1; i++) {
        if(i < 0) continue;
        if(chmin(err, abs(f(i) - t))) {
            ans = 2 * i + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}