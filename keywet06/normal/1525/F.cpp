#include <bits/stdc++.h>

using namespace std;

const int N = 543;
const long long INF = (long long)(1e18);

struct Matching {
    int n1, n2;
    vector<set<int>> g;
    vector<int> mt, used;

    void init() { mt = vector<int>(n2, -1); }

    int kuhn(int x) {
        if (used[x] == 1) return 0;
        used[x] = 1;
        for (auto y : g[x])
            if (mt[y] == -1 || kuhn(mt[y]) == 1) {
                mt[y] = x;
                return 1;
            }
        return 0;
    }

    int calc() {
        init();
        int sum = 0;
        for (int i = 0; i < n1; i++) {
            used = vector<int>(n1, 0);
            sum += kuhn(i);
        }
        return sum;
    }

    void remove_vertex(int v, bool right) {
        if (right) {
            for (int i = 0; i < n1; i++) g[i].erase(v);
        } else
            g[v].clear();
    }

    void add_edge(int x, int y) { g[x].insert(y); }

    Matching(){};
    Matching(int n1, int n2) : n1(n1), n2(n2) { g.resize(n1); };
};

int n, m, k;
long long dp[N][N];
int p[N][N];
vector<int> g[N];
long long x[N], y[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
    }
    for (int i = 0; i < k; i++) cin >> x[i] >> y[i];

    Matching mt(n, n);
    for (int i = 0; i < n; i++)
        for (auto j : g[i]) mt.add_edge(i, j);
    int cnt = mt.calc();
    int cur = cnt;
    vector<int> seq;
    while (cur > 0) {
        int idx = 0;
        for (int i = 0; i < n; i++) {
            Matching mt2 = mt;
            mt2.remove_vertex(i, false);
            if (mt2.calc() < cur) idx = i + 1;
            mt2 = mt;
            mt2.remove_vertex(i, true);
            if (mt2.calc() < cur) idx = -(i + 1);
        }
        assert(idx != 0);
        seq.push_back(idx);
        mt.remove_vertex(abs(idx) - 1, idx < 0);
        cur--;
    }
    reverse(seq.begin(), seq.end());
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= cnt; j++) dp[i][j] = -INF;
    dp[0][cnt] = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= cnt; j++) {
            if (dp[i][j] == -INF) continue;
            for (int z = 0; z <= j; z++) {
                if (i + 1 + z >= n) continue;
                int t = j - z;
                long long add = max(0ll, x[i] - t * y[i]);
                if (dp[i + 1][z] < dp[i][j] + add) {
                    dp[i + 1][z] = dp[i][j] + add;
                    p[i + 1][z] = j;
                }
            }
        }
    cur = max_element(dp[k], dp[k] + cnt + 1) - dp[k];
    vector<int> res;
    for (int i = k; i > 0; i--) {
        res.push_back(0);
        for (int j = p[i][cur] - 1; j >= cur; j--) res.push_back(seq[j]);
        cur = p[i][cur];
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto x : res) cout << x << " ";
    cout << endl;
}