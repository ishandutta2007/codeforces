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

void solve() {
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    for(ll i = 1; i * i <= x; i++) {
        ll lb = (i + 2) * i;
        ll ub = (x / i) * i;
        chmin(ub, (y + 1) * i);
        if(lb > ub) continue;
        ans += (ub - lb) / i + 1;
        //cerr << i << " " << ub << " " << lb << endl;
    }
    cout << ans << endl;
}
//a = (b + 1) * i

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}