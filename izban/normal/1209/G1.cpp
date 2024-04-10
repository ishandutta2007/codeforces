#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

void print(vector<int> a) {
    for (int x : a) printf("%d\n", x);
}

struct dsu {
    int n;
    vector<int> p;
    vector<int> sz;

    dsu(vector<int> _sz) {
        sz = _sz;
        n = sz.size();
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    }
    bool uni(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return 0;
        if (sz[v] > sz[u]) swap(v, u);
        p[v] = u;
        return 1;
    }
};

int solve(vector<int> a) {
    int n = a.size();

    const int N = *max_element(a.begin(), a.end()) + 1;

    vector<int> cnt(N);
    for (int x : a) cnt[x]++;

    vector<pair<int, int>> pos(N);
    for (int i = 0; i < n; i++) {
        pos[a[i]].second = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        pos[a[i]].first = i;
    }

    vector<pair<pair<int, int>, int>> vct;
    for (int i = 0; i < N; i++) {
        if (cnt[i] > 0) {
            vct.push_back({pos[i], i});
        }
    }
    sort(vct.begin(), vct.end());

    dsu d(cnt);

    int cur = -1;
    for (auto o : vct) {
        if (cur != -1 && o.first.first <= pos[cur].second) {
            d.uni(cur, o.second);
        }
        if (cur == -1 || o.first.second > pos[cur].second) {
            cur = o.second;
        }
    }

    int ans = n;
    for (int i = 0; i < N; i++) if (d.get(i) == i) ans -= d.sz[i];
    return ans;
}

vector<int> solve(vector<int> a, vector<pair<int, int>> b) {
    vector<int> ans;
    ans.push_back(solve(a));
    for (auto o : b) {
        a[o.first] = o.second;
        ans.push_back(solve(a));
    }
    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<pair<int, int>> b(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &b[i].first, &b[i].second);
            b[i].first--;
        }

        print(solve(a, b));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}