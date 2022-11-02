#include <bits/stdc++.h>

const int B = 30;
const int C = 2;
const int D = 4;
const int W[D] = {1, 3, 0, 2};

struct Trie {
    Trie *ch[C];
    int vals[D];
    Trie() {
        for (int i = 0; i < C; ++i) ch[i] = nullptr;
        std::fill(vals, vals + D, 0);
    }
};

int T, n;

void Insert(Trie *u, int x, int a, int b, int val) {
    if (x < 0) return;
    int c1 = bool(a & 1 << x), c2 = bool(b & 1 << x), o = 2 * c1 + c2;
    u->vals[o] = std::max(u->vals[o], val);
    o = (c1 ^ c2);
    if (!u->ch[o]) u->ch[o] = new Trie();
    Insert(u->ch[o], x - 1, a, b, val);
}

int Get(Trie *u, int x, int a, int b) {
    if (x < 0 || !u) return 0;
    int c1 = bool(a & 1 << x), c2 = bool(b & 1 << x), o = 2 * c1 + c2, Res = u->vals[W[o]];
    o = (c1 ^ c2);
    Res = std::max(Res, Get(u->ch[o], x - 1, a, b));
    return Res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        Trie *root = new Trie();
        int Res = 0;
        for (int i = 0, a; i < n; ++i) {
            std::cin >> a;
            int Con = Get(root, B - 1, a, i) + 1;
            Res = std::max(Res, Con);
            Insert(root, B - 1, a, i, Con);
        }
        std::cout << Res << '\n';
    }
    return 0;
}