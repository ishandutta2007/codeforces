 #include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// #include <algorithm>
using namespace std;

#define f first
#define s second
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

const int maxn = (int) 3e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;
const int inf = 2e9;

int main() {
    int t;
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> cnt;

    int ok = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            ok--;
        } else if (cnt[a[i]] == 1) {
            ok++;
        }
    }

    int diff = cnt.size();

    // cout << ok << ' ' << diff << endl;

    if (ok == diff) {
        cout << 0;
        return 0;
    }

    int res = n;
    for (int i = 0; i < n; i++) {
        int oldok = ok;
        for (int j = i; j < n; j++) {
            if (cnt[a[j]] == 2) {
                ok++;
            }
             cnt[a[j]]--;

             if (ok == diff) {
                 res = min(res, j - i + 1);
             }
        }
        ok = oldok;
        for (int j = i; j < n; j++)
            cnt[a[j]]++;
    }
    cout << res;
    return 0;
}