#include <iostream>
#include <map>
int t, n, l, r;
std::string s;
std::map<std::pair<int, int>, int> pos;
void solve() {
    std::cin >> n >> s;
    l = r = -1;
    pos = {{{0, 0}, 0}};
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            --x;
        } else if (s[i] == 'R') {
            ++x;
        } else if (s[i] == 'U') {
            ++y;
        } else {
            --y;
        }
        if (pos.count({x, y}) == 1) {
            int p = pos[{x, y}];
            if (l == -1 || i + 1 - p < r - l) {
                l = p;
                r = i + 1;
            }
        }
        pos[{x, y}] = i + 1;
    }
    if (l == -1) {
        std::cout << -1 << "\n";
    } else {
        std::cout << l + 1 << " " << r << "\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}