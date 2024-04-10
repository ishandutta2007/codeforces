#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int c;
    std::cin >> c;
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    std::vector<i64> suma(n + 1);
    for (int i = 0; i < n; i++) {
        suma[i + 1] = suma[i] + a[i];
    }
    
    std::vector<int> res(n + 1);
    res[0] = c;
    for (int i = 0; i < n; i++) {
        res[i + 1] = a[i] <= res[i] ? res[i] - a[i] : res[i];
    }
    
    for (int x = 1, i = n; x <= c; x++) {
        while (i > 0 && a[i - 1] < x) {
            i--;
        }
        if (res[i] < x) {
            continue;
        }
        int cur = res[i] - x;
        int pos = i;
        while (pos < n) {
            int np = std::upper_bound(suma.begin() + pos, suma.end(), suma[pos] + cur) - suma.begin() - 1;
            cur -= suma[np] - suma[pos];
            pos = std::lower_bound(a.begin() + np, a.end(), cur, std::greater<>()) - a.begin();
        }
        if (cur > 0) {
            std::cout << x << "\n";
            return 0;
        }
    }
    
    std::cout << "Greed is good\n";
    
    return 0;
}