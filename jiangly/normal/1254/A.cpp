#include <bits/stdc++.h>
using namespace std;
char g(int x) {
    if (x < 10)
        return x + '0';
    if (x < 36)
        return 'a' + x - 10;
    return 'A' + x - 36;
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        total += count(s[i].begin(), s[i].end(), 'R');
    }
    vector<int> f(k);
    for (int i = 0; i < k; ++i) {
        f[i] = total / (k - i);
        total -= f[i];
    }
    int c = 0;
    vector<vector<char>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            a[i][i % 2 == 0 ? j : m - j - 1] = g(c);
            if (s[i][i % 2 == 0 ? j : m - j - 1] == 'R') {
                --f[c];
                if (f[c] == 0 && c != k - 1)
                    ++c;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (char c : a[i])
            cout << c;
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}