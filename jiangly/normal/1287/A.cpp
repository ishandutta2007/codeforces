#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int t, n;
std::string s;
std::vector<int> a;
void solve() {
    std::cin >> n >> s;
    a.resize(n);
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'A') {
            a[i] = 0;
        } else if (s[i - 1] == 'A') {
            a[i] = 1;
        } else if (a[i - 1] > 0) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = 0;
        }
    }
    std::cout << *std::max_element(a.begin(), a.end()) << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}