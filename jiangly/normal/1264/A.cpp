#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    vector<int> c;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && p[i] == p[j])
            ++j;
        c.push_back(j - i);
    }
    int g = c[0], s = 0, b = 0;
    int i = 1;
    while (s <= g && i < c.size()) {
        s += c[i];
        ++i;
    }
    if (s <= g || s + g > n / 2) {
        g = s = b = 0;
    } else {
        while (i < c.size() && g + s + b + c[i] <= n / 2) {
            b += c[i];
            ++i;
        }
        if (b <= g)
            g = s = b = 0;
    }
    cout << g << " " << s << " " << b << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}