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

void solve() {
    ll m, d, w;
    cin >> m >> d >> w;
    ll n = min(m, d);
    ll g = __gcd(d-1, w);
    w /= g;
    ll largenum = n % w;
    if(largenum == 0) largenum = w;
    ll smallnum = w - largenum;
    ll largeval = (n + w - 1) / w;
    ll smallval = largeval - 1;
    ll ans = 0;
    //cerr << largenum << " " << smallnum << " " << largeval << " " << smallval << endl;
    ans += largenum * (largeval - 1) * largeval / 2;
    ans += smallnum * (smallval - 1) * smallval / 2;
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