#include <bits/stdc++.h>
using namespace std;

// Preorder Euler Tour
// 
struct PreorderEulerTour {
    int V; // # of vertices of tree
    int root;
    std::vector<std::vector<int>> edges;
    std::vector<int> subtree_begin, subtree_end;
    std::vector<int> vis_order;

    void _build_dfs(int now, int prv) {
        subtree_begin[now] = vis_order.size();
        vis_order.push_back(now);
        for (auto nxt : edges[now])
            if (nxt != prv) _build_dfs(nxt, now);
        subtree_end[now] = vis_order.size();
    }
    PreorderEulerTour() = default;
    PreorderEulerTour(const std::vector<std::vector<int>> &to, int root) : V(to.size()), root(root), edges(to) {
        assert(root >= 0 and root < V);
        subtree_begin.resize(V);
        subtree_end.resize(V);
        _build_dfs(root, -1);
    }
};

class MosAlgorithm {
    static const int INF = 1 << 30;
    int nmin, nmax;

public:
    std::vector<std::pair<int, int>> ranges;
    MosAlgorithm() : nmin(INF), nmax(-INF) {}

    void add_range(int l, int r) {
        assert(l <= r);
        nmin = std::min(nmin, l);
        nmax = std::max(nmax, r);
        ranges.emplace_back(l, r);
    }
    template <typename F1, typename F2, typename F3, typename F4, typename F5> void run(F1 AddRight, F2 AddLeft, F3 RemoveRight, F4 RemoveLeft, F5 Query) {
        const int Q = ranges.size();
        if (!Q) return;
        const int nbbucket = std::max(1, std::min<int>(nmax - nmin, sqrt(Q)));
        const int szbucket = (nmax - nmin + nbbucket - 1) / nbbucket;
        std::vector<int> qs(Q);
        std::iota(qs.begin(), qs.end(), 0);
        std::sort(qs.begin(), qs.end(), [&](int q1, int q2) {
            int b1 = (ranges[q1].first - nmin) / szbucket, b2 = (ranges[q2].first - nmin) / szbucket;
            if (b1 != b2)
                return b1 < b2;
            else {
                return (b1 & 1) ? (ranges[q1].second > ranges[q2].second) : (ranges[q1].second < ranges[q2].second);
            }
        });

        int l = ranges[qs[0]].first, r = l;
        for (auto q : qs) {
            while (r < ranges[q].second) AddRight(r++);
            while (l > ranges[q].first) AddLeft(--l);
            while (r > ranges[q].second) RemoveRight(--r);
            while (l < ranges[q].first) RemoveLeft(l++);
            assert(l == ranges[q].first and r == ranges[q].second);
            Query(q);
        }
    }
    template <typename F1, typename F3, typename F5> void run(F1 Add, F3 Remove, F5 Query) { run(Add, Add, Remove, Remove, Query); }
};

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M, v, k, a, b;
    cin >> N >> M;
    vector<int> C(N);
    for (auto &c : C) cin >> c;
    vector<vector<int>> to(N);
    for (int m = 0; m < N - 1; m++) {
        cin >> a >> b, a--, b--;
        to[a].push_back(b), to[b].push_back(a);
    }
    const PreorderEulerTour et(to, 0);
    vector<int> color2cnt(101010), num_c(101010), K, ret(M);
    MosAlgorithm mo;
    while (M--) cin >> v >> k, mo.add_range(et.subtree_begin[v - 1], et.subtree_end[v - 1]), K.emplace_back(k);

    auto add = [&](int i) -> void { num_c[++color2cnt[C[et.vis_order[i]]]]++; };
    auto remove = [&](int i) -> void { num_c[color2cnt[C[et.vis_order[i]]]--]--; };
    auto solve = [&](int q) -> void { ret[q] = num_c[K[q]]; };

    mo.run(add, remove, solve);
    for (auto x : ret) cout << x << '\n';
}