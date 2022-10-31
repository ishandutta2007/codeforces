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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 1e6+10;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const int pp = 41;
#define next ajksdslk

int n;

int a[maxn], b[maxn];
int p[maxn];

int main() {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int m; scanf ("%d", &m);
        int ans = 0;
        b[i] = m;
        while (m --) {
            int x; scanf("%d", &x);
            upmax(ans, x);
        }
        a[i] = ans;
        p[i] = i;
    }

    sort(p + 1, p + 1 + n, [&](int i, int j) {
        if (a[i] == a[j]) {
            return b[i] < b[j];
        }
        return a[i] > a[j];
    });

    ll ans = 0;
    int p0 = p[1];
    for (int i = 2; i <= n; i ++) {
        int p = ::p[i];
        ans += 1ll * (a[p0] - a[p]) * b[p];
    }
    cout << ans << '\n';
    return 0;
}