//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
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

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;

#define next ajksdslk

vector<int> a[228];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "00") a[0].pb(x);
        else if (s == "01") a[1].pb(x);
        else if (s == "10") a[10].pb(x);
        else a[11].pb(x);
    }

    sort(all(a[0]));
    sort(all(a[1]));
    sort(all(a[10]));
    sort(all(a[11]));

    ll ans = 0;
    int ca = 0, cb = 0, ctot = 0;

    while (!a[11].empty()) {
        ans += a[11].back();
        ca++; cb++; ctot++;
        a[11].pop_back();
    }

    while (!a[1].empty() && !a[10].empty()) {
        ans += a[1].back();
        ans += a[10].back();
        a[1].pop_back();
        a[10].pop_back();
        ca++; cb++; ctot += 2;
    }

    vector<pair<int, int> > rest;
    while (!a[1].empty()) { rest.pb(mp(a[1].back(), 1)); a[1].pop_back(); }
    while (!a[10].empty()) { rest.pb(mp(a[10].back(), 10)); a[10].pop_back(); }
    while (!a[0].empty()) { rest.pb(mp(a[0].back(), 0)); a[0].pop_back(); }

    sort(all(rest));
    reverse(all(rest));

    for (auto p : rest) {
        int nca = ca + (p.second == 10);
        int ncb = cb + (p.second == 1);
        int nctot = ctot + 1;
        if (2 * nca >= nctot && 2 * ncb >= nctot) {
            ca = nca;
            cb = ncb;
            ctot = nctot;
            ans += p.first;
        }
    }

    cout << ans << endl;

    return 0;
}