// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n[4];
int a[4][150005];
set<int> bad[4][150005];
int d[4][150005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n[0] >> n[1] >> n[2] >> n[3];
    for (int i=0; i<4; i++) {
        for (int j=0; j<n[i]; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=1; i<4; i++) {
        int sz;
        cin >> sz;
        while (sz--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            bad[i][y].insert(x);
        }
    }

    for (int j=0; j<n[0]; j++) d[0][j] = a[0][j];

    for (int i=1; i<4; i++) {
        vector<pair<int, int>> pr(n[i-1]);
        for (int j=0; j<n[i-1]; j++) pr[j] = {d[i-1][j], j};
        sort(begin(pr), end(pr));
        for (int j=0; j<n[i]; j++) {
            d[i][j] = 1e9;
            for (auto [val, idx] : pr) {
                if (bad[i][j].count(idx)) continue;
                d[i][j] = val + a[i][j];
                break;
            }
        }
    }

    int sol = 1e9;
    for (int i=0; i<n[3]; i++) sol = min(sol, d[3][i]);
    if (sol > 9e8) sol = -1;
    cout << sol << '\n'; 
}