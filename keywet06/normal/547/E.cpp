#include <bits/stdc++.h>

using int64 = long long;

const int C = 26;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;
    std::cin >> n >> q;
    std::vector<std::string> s(n);
    struct Node {
        int Fa;
        int Son[C];
        Node() { Fa = -1, memset(Son, 0xff, sizeof(Son)); }
        Node(int gFa) : Fa(gFa) { memset(Son, 0xff, sizeof(Son)); }
        inline int &operator[](const size_t x) { return Son[x]; }
    };
    std::vector<Node> Trie(1);
    std::vector<int> Fin(n);
    for (int i = 0, u; i < n; ++i) {
        std::cin >> s[i];
        for (char &ch : s[i]) ch -= 'a';
        u = 0;
        for (char ch : s[i]) {
            if (Trie[u][ch] == -1) {
                Trie[u][ch] = Trie.size();
                Trie.emplace_back(u);
            }
            u = Trie[u][ch];
        }
        Fin[i] = u;
    }
    size_t m = Trie.size();
    std::queue<int> Que;
    std::vector<int> Fail(m);
    Que.push(0), Fail[0] = -1;
    while (!Que.empty()) {
        int u = Que.front();
        Que.pop();
        for (int i = 0, v; i < C; ++i) {
            if (Trie[u][i] == -1) continue;
            v = Fail[u];
            while (v != -1 && Trie[v][i] == -1) v = Fail[v];
            Fail[Trie[u][i]] = v == -1 ? 0 : Trie[v][i];
            Que.push(Trie[u][i]);
        }
    }
    std::vector<std::vector<int> > To(m);
    for (int i = 1; i < m; ++i) To[Fail[i]].push_back(i);
    std::vector<int> Dfn(m), End(m);
    size_t DCnt = 0;
    using DfsType = std::function<void(int)>;
    DfsType Dfs = [&](int u) {
        Dfn[u] = ++DCnt;
        for (int v : To[u]) Dfs(v);
        End[u] = DCnt;
    };
    Dfs(0);
    std::vector<int64> S(m + 2);
    auto Add = [&](int u, int64 x) {
        while (u < S.size()) S[u] += x, u += u & -u;
    };
    auto TSum = [&](int u) {
        int64 Ret = 0;
        while (u) Ret += S[u], u &= u - 1;
        return Ret;
    };
    auto Query = [&](int u) { return TSum(End[u]) - TSum(Dfn[u] - 1); };
    std::vector<int64> Ans(q);
    std::vector<std::vector<std::pair<int, int> > > Q(n);
    std::vector<int> Pot(q);
    for (int i = 0, l, r, k; i < q; ++i) {
        std::cin >> l >> r >> k, --l, --r, Pot[i] = --k;
        if (l) Q[l - 1].emplace_back(i, -1);
        Q[r].emplace_back(i, 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int u = Fin[i]; u != -1; u = Trie[u].Fa) {
            Add(Dfn[u], 1);
        }
        for (auto [k, o] : Q[i]) Ans[k] += o * Query(Fin[Pot[k]]);
    }
    for (int i = 0; i < q; ++i) std::cout << Ans[i] << '\n';
    return 0;
}