#include <bits/stdc++.h>

using int64 = long long;

int n, x, y, o;

int64 v;

std::string s;
std::priority_queue<std::pair<int, int> > q;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> s, n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++o;
        if (s[i] == ')') --o;
        if (s[i] == '?') {
            std::cin >> x >> y;
            s[i] = ')', --o, q.push(std::make_pair(y - x, i)), v += y;
        }
        if (o < 0) {
            if (q.empty()) return std::cout << -1 << std::endl, 0;
            v -= q.top().first, s[q.top().second] = '(', q.pop(), ++++o;
        }
    }
    if (o) return std::cout << -1 << std::endl, 0;
    std::cout << v << std::endl << s << std::endl;
    return 0;
}