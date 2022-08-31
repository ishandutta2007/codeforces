#include <bits/stdc++.h>

using i64 = long long;

bool cmp(const std::string &a, const std::string &b) {
    if (a.empty()) {
        return false;
    }
    if (b.empty()) {
        return true;
    }
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector F(256, std::string()), T(F), E(F);
    F[240] = "x";
    F[204] = "y";
    F[170] = "z";
    
    for (int _ = 0; _ < 20; _++) {
        for (int i = 0; i < 256; i++) {
            if (!E[i].empty()) {
                F[i] = std::min(F[i], '(' + E[i] + ')', cmp);
            }
            if (!F[i].empty()) {
                F[i ^ 255] = std::min(F[i ^ 255], '!' + F[i], cmp);
            }
            T[i] = std::min(T[i], F[i], cmp);
            for (int j = 0; j < 256; j++) {
                if (!T[i].empty() && !F[j].empty()) {
                    T[i & j] = std::min(T[i & j], T[i] + '&' + F[j], cmp);
                }
            }
            E[i] = std::min(E[i], T[i], cmp);
            for (int j = 0; j < 256; j++) {
                if (!E[i].empty() && !T[j].empty()) {
                    E[i | j] = std::min(E[i | j], E[i] + '|' + T[j], cmp);
                }
            }
        }
    }
    
    int t;
    std::cin >> t;
    while (t--) {
        int mask = 0;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < 8; i++) {
            mask |= (s[i] - '0') << i;
        }
        std::cout << E[mask] << "\n";
    }
    
    return 0;
}