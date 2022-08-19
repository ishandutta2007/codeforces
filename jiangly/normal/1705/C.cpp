#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, c, q;
    std::cin >> n >> c >> q;
    
    std::string s;
    std::cin >> s;
    
    std::vector<i64> len(c + 1);
    len[0] = n;
    std::vector<i64> l(c), r(c);
    for (int i = 0; i < c; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
        len[i + 1] = len[i] + r[i] - l[i];
    }
    
    while (q--) {
        i64 k;
        std::cin >> k;
        k--;
        
        for (int j = c - 1; j >= 0; j--) {
            if (k >= len[j]) {
                k += l[j] - len[j];
            }
        }
        std::cout << s[k] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}