#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector s(3, std::vector<std::string>(n));
    std::map<std::string, int> cnt;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> s[i][j];
            cnt[s[i][j]]++;
        }
    }
    
    std::vector<int> score(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt[s[i][j]] == 1) {
                score[i] += 3;
            } else if (cnt[s[i][j]] == 2) {
                score[i] += 1;
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        std::cout << score[i] << " \n"[i == 2];
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