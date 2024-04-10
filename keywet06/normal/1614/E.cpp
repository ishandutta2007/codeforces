#include <bits/stdc++.h>

struct Node {
    Node *l, *r;
    int sum = 0;
    Node() : l(nullptr), r(nullptr), sum(0) {}
};

int getSum(Node *t, int l, int r, int x) {
    if (x <= l || t == nullptr) return 0;
    if (x >= r) return t->sum;
    int m = (l + r) / 2;
    return getSum(t->l, l, m, x) + getSum(t->r, m, r, x);
}

void erase(Node *&t, int l, int r, int k) {
    if (t == nullptr) t = new Node();
    ++t->sum;
    if (r - l == 1) return;
    int m = (l + r) / 2;
    int sl = m - l - (t->l == nullptr ? 0 : t->l->sum);
    if (k < sl) {
        erase(t->l, l, m, k);
    } else {
        erase(t->r, m, r, k - sl);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    Node *t = new Node;
    int v = 0, LAns = 0;
    for (int i = 0; i < n; i++) {
        int T;
        std::cin >> T;
        int k;
        std::cin >> k;
        if (T >= v) {
            erase(t, 0, 1 << 30, T - v);
        } else {
            --v;
        }
        if (T > v) erase(t, 0, 1 << 30, T - 1 - v++);
        while (k--) {
            int x;
            std::cin >> x;
            x = (x + LAns) % 1000000001;
            std::cout << (LAns = v + x - getSum(t, 0, 1 << 30, x)) << '\n';
        }
    }
    return 0;
}