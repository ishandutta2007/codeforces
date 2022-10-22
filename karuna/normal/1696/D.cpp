#include <bits/stdc++.h>
using namespace std;

const int M = 3e5 + 10;
const int INF = 1e9 + 10;

int n, A[M];
vector<int> G[M];

struct SEG {
    int X[M << 2], N[M << 2];

    void init(int lo, int hi, int idx) {
        if (lo == hi) {
            X[idx] = N[idx] = A[lo]; return;
        }
        init(lo, lo + hi >> 1, idx << 1);
        init(1 + (lo + hi >> 1), hi, idx << 1 | 1);
        X[idx] = max(X[idx << 1], X[idx << 1 | 1]);
        N[idx] = min(N[idx << 1], N[idx << 1 | 1]);
    }
    pair<int, int> query(int a, int b, int lo, int hi, int idx) {
        if (b < lo || a > hi) return { -INF, INF };
        if (a <= lo && hi <= b) return { X[idx], N[idx] };
        auto [x1, n1] = query(a, b, lo, lo + hi >> 1, idx << 1);
        auto [x2, n2] = query(a, b, 1 + (lo + hi >> 1), hi, idx << 1 | 1);
        return { max(x1, x2), min(n1, n2) };
    }
} S;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    S.init(1, n, 1);
    set<int> St;
    vector<pair<int, int>> I;
    for (int i = 1; i <= n; i++) {
        I.emplace_back(A[i], i);
    }
    sort(I.begin(), I.end());
    for (int i = 0; i < I.size(); i++) {
        auto [x, j] = I[i];
        auto it = St.lower_bound(j);
        auto r = (it == St.end() ? n : ((*it) - 1));
        auto [mx, mn] = S.query(j, r, 1, n, 1);

        if (x != mx) {
            G[x].push_back(mx);
            G[mx].push_back(x);
        }
        St.insert(j);
    }
    St.clear();
    for (int i = (int)I.size() - 1; i >= 0; i--) {
        auto [x, j] = I[i];
        auto it = St.lower_bound(j);
        auto r = (it == St.end() ? n : ((*it) - 1));
        auto [mx, mn] = S.query(j, r, 1, n, 1);

        if (x != mn) {
            G[x].push_back(mn);
            G[mn].push_back(x);
        }
        St.insert(j);
    }
    queue<int> Q; Q.push(A[1]);
    vector<int> Dist(n + 1, -1); Dist[A[1]] = 0;
    while (!Q.empty()) {
        auto v = Q.front(); Q.pop();
        for (int x : G[v]) {
            if (Dist[x] == -1) {
                Dist[x] = Dist[v] + 1;
                Q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    cout << Dist[A[n]] << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}