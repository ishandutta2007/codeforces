#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int cntR = std::count(s.begin(), s.end(), 'R');
        int cntP = std::count(s.begin(), s.end(), 'P');
        int cntS = std::count(s.begin(), s.end(), 'S');
        int mx = std::max({cntR, cntP, cntS});
        char c = (mx == cntR) ? 'P' : (mx == cntP) ? 'S' : 'R';
        std::cout << std::string(s.length(), c) << "\n";
    }
    return 0;
}