//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 1e7+10;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const int pp = 41;
#define next ajksdslk


int n;

ll le, ri;
ull x, y, z, b1, b2;

ull mod = (1ULL << 32);

ll a[maxn];
int sz = 0;

const ll llinf = (ll) 4e18 + 100;

void solve() {
    cin >> n >> le >> ri >> x >> y >> z >> b1 >> b2;
    sz = 0;
    auto add = [&](ll x) {
        a[++sz] = x;
    };

    add(ll(b1) % (ri - le + 1) + le);
    add(ll(b2) % (ri - le + 1) + le);
    for (int i = 3; i <= n; i ++) {
        ull b3 = (b1 * x + b2 * y + z) % mod;
        add(ll(b3) % (ri - le + 1) + le);
        b1 = b2;
        b2 = b3;
    }

    ll curMin = mod;
    ll ans = llinf;

    for (int i = 1; i <= n; i ++) {
        if (a[i] >= 0) {
            if (curMin < a[i]) upmin(ans, curMin * a[i]);
        }
        upmin(curMin, a[i]);
    }

    ll curMax = -mod;
    for (int i = n; i >= 1; i --) {
        if (a[i] <= 0) {
            if (curMax > a[i]) upmin(ans, curMax * a[i]);
        }
        upmax(curMax, a[i]);
    }
    if (ans == llinf) {
        cout << "IMPOSSIBLE\n";
    } else  cout << ans << "\n";

}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while ( t -- ) {
        solve();
    }
    return 0;
}