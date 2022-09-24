#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


struct segtree {
    int N;
    vector<int> t;

    segtree() {}
    segtree(int n) {
        N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, 0);
    }

    int get(int l, int r) {
        int res = 0;
        l += N;
        r += N;
        while (l <= r) {
            if (l % 2 == 1) res = max(res, t[l]);
            if (r % 2 == 0) res = max(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    void upd(int x, int y) {
        x += N;
        t[x] = max(t[x], y);
        while (x > 1) {
            x >>= 1;
            t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
    }
};

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<pair<int, int>, int>> ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &ed[i].first.first, &ed[i].first.second, &ed[i].second);
            ed[i].first.first--;
            ed[i].first.second--;
            ed[i].second++;
        }

        vector<vector<int>> w(n);
        for (int i = 0; i < m; i++) {
            w[ed[i].first.first].push_back(ed[i].second);
            w[ed[i].first.second].push_back(ed[i].second);
        }
        for (int i = 0; i < n; i++) {
            sort(w[i].begin(), w[i].end());
            w[i].resize(unique(w[i].begin(), w[i].end()) - w[i].begin());
        }

        vector<segtree> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = segtree(w[i].size());
        }

        for (int i = 0; i < m; i++) {
            int v = ed[i].first.first;
            int to = ed[i].first.second;
            int cw = ed[i].second;

            int id1 = lower_bound(w[v].begin(), w[v].end(), cw) - w[v].begin();
            int x = t[v].get(0, id1 - 1);

            int id2 = lower_bound(w[to].begin(), w[to].end(), cw) - w[to].begin();
            t[to].upd(id2, x + 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, t[i].get(0, w[i].size() - 1));

        cout << ans << endl;
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}