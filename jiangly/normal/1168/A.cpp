#include <bits/stdc++.h>

constexpr int N = 3e5;

int n, m;
int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        bool ok = true;
        int lst = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= lst) {
                if (lst - a[i] > mid) {
                    ok = false;
                    break;
                }
            } else if (lst - a[i] + m > mid) {
                lst = a[i];
            }
        }
        if (ok) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    std::cout << l << "\n";
    
    return 0;
}