#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1 << 17;

int l[2 * N], r[2 * N];
int vals[N];

void upd(int i, int _l, int _r) {
    i += N;
    l[i] = _l;
    r[i] = _r;
    i /= 2;
    while (i) {
        l[i] = l[2 * i] + l[2 * i + 1];
        r[i] = r[2 * i] + r[2 * i + 1];
        int c = min(l[2 * i], r[2 * i + 1]);
        l[i] -= c;
        r[i] -= c;
        i /= 2;
    }
}

int find(int i, int pos) {
    //cerr << i << ' ' << pos << '\n';
    if (pos < 0) return -1;
    if (pos >= l[i]) return -1;
    if (i >= N) return vals[i - N];
    int c = min(l[2 * i], r[2 * i + 1]);
    int from_l = l[2 * i] - c;//, from_r = l[2 * i + 1];
    if (pos < from_l) return find(2 * i, pos);
    else return find(2 * i + 1, pos - from_l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    ordered_set<pair<int, int>> p;
    forn(i, 0, m) {
        int pos, tp;
        cin >> pos >> tp;
        --pos;
        if (tp == 0) {
            upd(pos, 0, 1);
        } else {
            int val;
            cin >> val;
            upd(pos, 1, 0);
            vals[pos] = val;
        }
        int ones = l[1];
        cout << find(1, ones - 1) << '\n';
    }
}