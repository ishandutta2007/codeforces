#include <bits/stdc++.h>

const int N = 500005;

int n, z;
int x[N], y[N];

std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i].first, a[i].second = i;
    sort(a, a + n);
    int need = n - (n + 2) / 3;
    for (int i = n - need; i < n; ++i) {
        if (z % 2 == 0) {
            x[a[i].second] = z / 2, y[a[i].second] = a[i].first - z / 2;
        } else {
            x[a[i].second] = a[i].first - z / 2, y[a[i].second] = z / 2;
        }
        ++z;
    }
    for (int i = 0; i < n - need; ++i) {
        x[a[i].second] = 0, y[a[i].second] = a[i].first;
    }
    std::cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) std::cout << x[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) std::cout << y[i] << " \n"[i == n - 1];
    return 0;
}