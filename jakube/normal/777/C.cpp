#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> b(n);
    vector<int> last(m, 0);
    for (int i = 0; i < n; i++) {
        int best = numeric_limits<int>::max();

        for (int j = 0; j < m; j++) {
            if (i && v[i][j] < v[i-1][j])
                last[j] = i;
            best = min(best, last[j]);
        }

        b[i] = best;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        if (l-1 < b[r-1])
            cout << "No\n";
        else 
            cout << "Yes\n";
    }
}