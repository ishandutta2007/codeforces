#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

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

const int N = 3e5 + 10;
vector<tuple<int, int, int>> q[N];

int tree[4 * N];
int to_push[4 * N];

void push(int v) {
    tree[v] += to_push[v];
    if (v >= 2 * N) return;
    to_push[2 * v] += to_push[v];
    to_push[2 * v + 1] += to_push[v];
    to_push[v] = 0;
}

void _add(int v, int l, int r, int lb, int rb, int val) {
    if (l < lb) l = lb;
    if (r > rb) r = rb;
    if (l >= r) return;
    assert(v < 4 * N);
    if (l == lb && r == rb) {
        to_push[v] += val;
        return;
    }
    push(v);
    int mid = (lb + rb) / 2;
    _add(2 * v, l, r, lb, mid, val);
    _add(2 * v + 1, l, r, mid, rb, val);
    tree[v] = max(tree[2 * v] + to_push[2 * v], tree[2 * v + 1] + to_push[2 * v + 1]);
}

void add(int l, int r, int val) {
    _add(1, l, r, 0, N, val);
}

int _get(int v, int lb, int rb) {
    if (lb + 1 == rb) return lb;
    assert(v < 4 * N);
    push(v);
    int mid = (lb + rb) / 2;
    if (tree[v] == tree[2 * v] + to_push[2 * v])
        return _get(2 * v, lb, mid);
    else
        return _get(2 * v + 1, mid, rb);
}

pair<int, int> get() {
    int ix = _get(1, 0, N);
    return {tree[1], ix};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<int> l(n), v(n), r(n);
    forn(i, 0, n) {
        cin >> l[i] >> v[i] >> r[i];
        q[l[i]].eb(v[i], r[i] + 1, 1);
        q[v[i] + 1].eb(v[i], r[i] + 1, -1);
    }
    int ans = -1, L = -1, R = -1;
    forn(_, 0, N) {
        for (auto p : q[_]) {
            int x, y, z;
            tie(x, y, z) = p;
            add(x, y, z);
        }
        if (!q[_].empty()) {
            pair<int, int> x = get();
            if (x.fs > ans) {
                ans = x.fs;
                L = _;
                R = x.sn;
            }
        }
    }
    cout << ans << '\n';
    //cout << L << ' ' << R << '\n';
    forn(i, 0, n)
        if (l[i] <= L && L <= v[i] && v[i] <= R && R <= r[i])
            cout << i + 1 << ' ';
}