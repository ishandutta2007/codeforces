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

ll f(ll a, ll b, ll x, ll y, ll n) {
    ll d = max(0LL, a - x);
    chmin(d, n);
    a -= d;
    n -= d;
    d = max(0LL, b - y);
    chmin(d, n);
    b -= d;
    n -= d;
    return a * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ans = INF;
        chmin(ans, f(a, b, x, y, n));
        chmin(ans, f(b, a, y, x, n));
        cout << ans << endl;
    }
    return 0;
}