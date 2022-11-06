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

struct card {
    int a, b, c, d, id, pos;

    card () {};
    card (int _a, int _b, int _c, int _d, int _id) : a(_a), b(_b), c(_c), d(_d), id(_id), pos(_id) {};

    bool operator< (const card &x) const {
        if (a == x.a) return id < x.id;
        return a < x.a;
    }
};

card miny (const card &x, const card &y) {
    return x.b < y.b ? x : y;
}

const int N = 1 << 17;
card tree[2 * N];
int dist[N], prv[N];

void remove(int i) {
    i += N;
    tree[i].b = INF;
    i /= 2;
    while (i) {
        tree[i] = miny(tree[2 * i], tree[2 * i + 1]);
        i /= 2;
    }
}

card get(int r) {
    card ans = card(INF, INF, INF, INF, INF);
    r += N;
    while (r > 1) {
        if (r % 2) {
            --r;
            ans = miny(ans, tree[r]);
        }
        r /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        int _a, _b, _c, _d;
        cin >> _a >> _b >> _c >> _d;
        tree[N + i] = card(_a, _b, _c, _d, i);
    }
    sort(tree + N, tree + N + n);
    forn(i, 0, n) tree[N + i].pos = i;
    ford(i, 1, N) tree[i] = miny(tree[2 * i], tree[2 * i + 1]);
    forn(i, 0, n) dist[i] = INF;
    vector<tuple<int, int, int>> q;
    forn(i, 0, n) if (tree[i + N].a == 0 && tree[i + N].b == 0) {
        q.eb(tree[i + N].c, tree[i + N].d, tree[i + N].id);
        dist[tree[i + N].id] = 1;
        prv[tree[i + N].id] = -1;
        remove(i);
    }
    for (int step = 2; !q.empty(); ++step) {
        vector<tuple<int, int, int>> nq;
        for (auto p : q) {
            int x, y, prv_id;
            tie(x, y, prv_id) = p;
            int r = upper_bound(tree + N, tree + N + n, card(x, 0, 0, 0, INF)) - (tree + N);
            while (1) {
                card fnd = get(r);
                if (fnd.b > y) break;
                remove(fnd.pos);
                dist[fnd.id] = step;
                prv[fnd.id] = prv_id;
                nq.eb(fnd.c, fnd.d, fnd.id);
            }
        }
        q = nq;
    }
    if (dist[n - 1] == INF) {
        cout << "-1\n";
        return 0;
    }
    cout << dist[n - 1] << '\n';
    vector<int> path;
    int i = n - 1;
    while (i != -1) {
        path.eb(i);
        i = prv[i];
    }
    reverse(all(path));
    for (int j : path) cout << 1 + j << ' ';
}