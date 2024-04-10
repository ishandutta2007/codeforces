#include <bits/stdc++.h>

using i64 = long long;

bool isprime[100];

void solve() {
    int k;
    std::cin >> k;
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < k; i++) {
        if (!isprime[s[i] - '0']) {
            std::cout << "1\n";
            std::cout << s[i] << "\n";
            return;
        }
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (!isprime[(s[i] - '0') * 10 + s[j] - '0']) {
                std::cout << "2\n";
                std::cout << s[i] << s[j] << "\n";
                return;
            }
        }
    }
    
    assert(false);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::fill(isprime + 2, isprime + 100, true);
    for (int i = 2; i < 100; i++) {
        for (int j = 2 * i; j < 100; j += i) {
            isprime[j] = false;
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}