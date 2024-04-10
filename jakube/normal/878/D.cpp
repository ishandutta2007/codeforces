#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;
    vector<bitset<4096>> v(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4096; j++) {
            v[i][j] = (j >> i) & 1;
        }
    }

    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(k, {0, 0}));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[j][i].first;
            a[j][i].second = i;
        }
    }
    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
    }

    for (int Q = 0; Q < q; Q++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1) {
            v.push_back(v[x] | v[y]);
        }
        if (t == 2) {
            v.push_back(v[x] & v[y]);
        }
        if (t == 3) {
            int mask = 0;
            for (auto p : a[y]) {
                mask |= 1 << p.second;
                if (v[x][mask]) {
                    cout << p.first << '\n';
                    break;
                }
            }
        }
    }
}