#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
struct Data {
    int mx;
    int mn;
    int add;
    Data(int mx = 0, int mn = 0, int add = 0) : mx(mx), mn(mn), add(add) {}
};
Data operator+(const Data &a, const Data &b) {
    return Data(std::max(a.mx, a.add + b.mx), std::min(a.mn, a.add + b.mn), a.add + b.add);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        std::vector<Data> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                a[i] = Data(1, 0, 1);
            } else {
                a[i] = Data(0, -1, -1);
            }
        }
        std::vector<Data> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = a[i] + suf[i + 1];
        }
        while (m--) {
            int l, r;
            std::cin >> l >> r;
            l--;
            auto v = pre[l] + suf[r];
            std::cout << v.mx - v.mn + 1 << "\n";
        }
    }
    return 0;
}