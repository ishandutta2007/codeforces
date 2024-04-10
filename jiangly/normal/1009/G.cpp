#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
std::string s;
int n, m;
std::vector<int> cnt, tot, f;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s >> m;
    n = s.length();
    tot.resize(64);
    for (char c : s)
        for (int i = 0; i < 64; ++i)
            if (i >> (c - 'a') & 1)
                ++tot[i];
    f.assign(n, 63);
    for (int i = 0; i < m; ++i) {
        int pos;
        std::cin >> pos;
        --pos;
        std::string t;
        std::cin >> t;
        int x = 0;
        for (char c : t)
            x |= 1 << (c - 'a');
        f[pos] = x;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 64; ++j)
            if ((j & f[i]) == f[i])
                --tot[j];
    if (*min_element(tot.begin(), tot.end()) < 0) {
        std::cout << "Impossible\n";
        return 0;
    }
    s.clear();
    for (int i = 0; i < n; ++i) {
        for (int c = 0; ; ++c) {
            if ((f[i] >> c & 1) && [&]() {
                for (int j = 0; j < 64; ++j)
                    if (tot[j] + ((j & f[i]) == f[i]) - (j >> c & 1) < 0)
                        return false;
                return true;
            }()) {
                for (int j = 0; j < 64; ++j)
                    tot[j] += ((j & f[i]) == f[i]) - (j >> c & 1);
                s += c + 'a';
                break;
            }
        }
    }
    std::cout << s << "\n";
    return 0;
}