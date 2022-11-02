#include <bits/stdc++.h>

std::vector<int> SG(200 + 1);

int getSG(int n) {
    while (n > 200) n -= 34;
    return SG[n];
}

int n;

std::string s;

void Solve() {
    std::cin >> n >> s;
    int Rc = std::count(s.begin(), s.end(), 'R'), Bc = n - Rc;
    if (Rc > Bc) return void(std::cout << "Alice\n");
    if (Rc < Bc) return void(std::cout << "Bob\n");
    int Ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            int j = i;
            while (j < n - 1 && s[j] != s[j + 1]) ++j;
            Ans ^= getSG(j - i), i = j;
        }
    }
    if (Ans) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    SG[0] = 0;
    for (int i = 1; i <= 200; ++i) {
        std::set<int> s;
        for (int j = 0; j < i; ++j) s.insert(SG[std::max(0, j - 1)] ^ SG[std::max(0, i - j - 2)]);
        while (s.count(SG[i])) ++SG[i];
    }
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}