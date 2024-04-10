#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    std::string s;
    std::cin >> s;
    
    if (std::count(s.begin(), s.end(), 'A') != a + c + d) {
        std::cout << "NO\n";
        return;
    }
    int n = s.length();
    
    int curc = 0, curd = 0;
    
    std::vector<int> all, ab, ba;
    
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && s[j + 1] != s[j]) {
            j++;
        }
        int t = j - i;
        if (t % 2 == 0) {
            all.push_back(t / 2);
        } else if (s[i] == 'A') {
            ab.push_back((t + 1) / 2);
        } else {
            ba.push_back((t + 1) / 2);
        }
        i = j;
    }
    
    std::sort(all.begin(), all.end(), std::greater());
    std::sort(ab.begin(), ab.end(), std::greater());
    std::sort(ba.begin(), ba.end(), std::greater());
    
    for (auto x : ab) {
        curc += x;
    }
    for (auto x : ba) {
        curd += x;
    }
    for (auto x : all) {
        int t = std::min(std::max(0, c - curc), x);
        curc += t;
        curd += x - t;
    }
    for (auto x : ab) {
        if (curc > c) {
            curc--;
            x--;
            int t = std::min(curc - c, x);
            curc -= t;
            curd += t;
        }
    }
    for (auto x : ba) {
        if (curd > d) {
            curd--;
            x--;
            int t = std::min(curd - d, x);
            curd -= t;
            curc += t;
        }
    }
    if (curc >= c && curd >= d) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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