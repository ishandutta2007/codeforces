#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;
vector<int> p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        int x;
        cin >> x;
        p[x].eb(i);
    }
    vector<int> o;
    int cur = -1;
    forn(i, 0, N) {
    //cerr << "qw\n";
        if (p[i].empty()) continue;
        int fst = 0;
        int sz = (int)p[i].size();
        forn(j, 0, sz)
            if (p[i][j] > cur) {
                fst = j;
                break;
            }
        forn(j, fst, sz)
            o.eb(p[i][j]);
        forn(j, 0, fst)
            o.eb(p[i][j]);
        cur = o.back();
    }
    //forn(i, 0, n) cerr << o[i] << ' ';
    ordered_set S;
    forn(i, 0, n) S.insert(i);
    assert(o.size() == n);
    ll ans = o[0] + 1;
    //cerr << ans << '\n';
    forn(i, 1, n) {
        int step = S.order_of_key(o[i]) - S.order_of_key(o[i - 1]);
        if (step < 0) step += (int)S.size();
        ans += step;
        //cerr << step << '\n';
        S.erase(o[i - 1]);
    }
    cout << ans << '\n';
    /*
    S.insert(1);
    S.insert(3);
    cout << S.order_of_key(2) << '\n';
    cout << *S.find_by_order(1) << '\n';*/
}