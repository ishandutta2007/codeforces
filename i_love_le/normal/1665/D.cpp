#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 100;

//ll Q = 536870912 + 1;

ll ask(ll a, ll b) {
    assert(a <= 2e9);
    assert(b <= 2e9);
    assert(a != b);
    cout << "? " << a << " " << b << endl;
    ll x;// = gcd(Q + a, Q + b);
    cin >> x;
    return x;
}

void solve() {
    ll x = 0;
    for (ll i = 0; i < 29; ++i) {
        ll b = 1ll << i;
        ll t = (b * 2 - x);
        ll w = (b * 4 - x);
        ll r = ask(t, w) % (b * 2);
        if (r == 0) {
            continue;
        }
        assert(r == b);
        x |= b;
    }
    // gcd(x * 2, x * 3)
    if (ask(1, (x | (1ll << 29)) + 2) == (x | (1ll << 29)) + 1) {
        x |= 1ll << 29ll;
    }
    cout << "! " << x << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}