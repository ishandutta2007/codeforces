// lg
#include <iostream>
#include <vector>
int t, n, d;
std::vector<int> parent, a;
std::vector<std::vector<int>> ver;
void solve() {
    std::cin >> n >> d;
    parent.resize(n);
    int sum = n * (n - 1) / 2;
    if (d > sum) {
        std::cout << "NO\n";
        return;
    }
    a.assign(n, 1);
    for (int i = n - 1, j = 1; i > j; --i) {
        if (i - j < sum - d) {
            --a[i];
            ++a[j];
            sum -= i - j;
            if (a[j] == (1 << j))
                ++j;
        } else {
            --a[i];
            ++a[i - (sum - d)];
            sum = d;
            break;
        }
    }
    if (sum != d) {
        std::cout << "NO\n";
        return;
    }
    ver.assign(n, {});
    ver[0].push_back(0);
    int num = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            ver[i].push_back(num);
            parent[num] = ver[i - 1][j / 2];
            ++num;
        }
    }
    std::cout << "YES\n";
    for (int i = 1; i < n; ++i)
        std::cout << parent[i] + 1 << " \n"[i == n - 1];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}