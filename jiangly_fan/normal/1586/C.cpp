#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for (auto&s : vs) cin >> s;
    vector<int> p(m);
    for (int i = 0; i + 1 < n; i += 1)
        for (int j = 1; j < m; j += 1)
            if (vs[i][j] == 'X' and vs[i + 1][j - 1] == 'X')
                p[j] = 1;
    for (int i = 1; i < m; i += 1)
        p[i] += p[i - 1];
    int q;
    for (cin >> q; q; q -= 1) {
        int x1, x2;
        cin >> x1 >> x2;
        cout << (p[x2 - 1] - p[x1 - 1] ? "NO\n" : "YES\n");
    }
    return 0;
}