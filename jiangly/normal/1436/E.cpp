#include <bits/stdc++.h>

struct Fenwick {
    int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n, n) {}
    void modify(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i)
            if (v < a[i - 1]) a[i - 1] = v;
    }
    int preMin(int x) {
        int ans = n;
        for (int i = x; i; i &= i - 1)
            if (a[i - 1] < ans) ans = a[i - 1];
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n), lst(n + 1, -1), pre(n);
    std::vector<bool> e(n + 2);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    Fenwick fen(n + 1);
    for (int i = 0; i <= n; ++i) fen.modify(i, lst[i]);
    for (int i = 0; i <= n; ++i)
        if (lst[i] != n - 1 && fen.preMin(i) > lst[i]) e[i] = true;
    for (int i = n - 1; i >= 0; --i) {
        fen.modify(a[i], pre[i]);
        if (pre[i] != i - 1 && fen.preMin(a[i]) > pre[i]) e[a[i]] = true;
    }
    int ans = 0;
    while (e[ans]) ++ans;
    std::cout << ans + 1 << "\n";
    
    return 0;
}