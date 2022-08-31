#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
    Node *ch[2];
    Node() : ch{} {}
};
int n;
long long ans;
std::vector<int> a;
Node *rt;
void dfs(Node *p, int d, int l, int r) {
    if (d == 0)
        return;
    if (p -> ch[0] == nullptr)
        return dfs(p -> ch[1], d - 1, l, r);
    if (p -> ch[1] == nullptr)
        return dfs(p -> ch[0], d - 1, l, r);
    int m = l;
    while (~a[m] >> (d - 1) & 1)
        ++m;
    dfs(p -> ch[0], d - 1, l, m);
    dfs(p -> ch[1], d - 1, m, r);
    ans += 1 << (d - 1);
    int mn = 1 << (d - 1);
    for (int i = l; i < m; ++i) {
        Node *q = p -> ch[1];
        int val = 0;
        for (int j = d - 2; j >= 0; --j) {
            int c = a[i] >> j & 1;
            if (q -> ch[c] == nullptr) {
                c ^= 1;
                val += 1 << j;
            }
            q = q -> ch[c];
        }
        mn = std::min(mn, val);
    }
    ans += mn;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    rt = new Node;
    for (int i = 0; i < n; ++i) {
        auto p = rt;
        for (int j = 29; j >= 0; --j) {
            int d = a[i] >> j & 1;
            if (p -> ch[d] == nullptr)
                p -> ch[d] = new Node;
            p = p -> ch[d];
        }
    }
    dfs(rt, 30, 0, n);
    std::cout << ans << "\n";
    return 0;
}