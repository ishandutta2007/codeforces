#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

int main()
{

    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int> > ans(n, vector<int>(m));
    vector<vector<pii> > a(n, vector<pii>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = mp(i, j);
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            cin >> i;
            --i;
            pii p = a[i][0];
            for (int j = 0; j < m - 1; ++j) {
                a[i][j] = a[i][j + 1];
            }
            a[i].back() = p;
        } else if (type == 2) {
            int j;
            cin >> j;
            --j;
            pii p = a[0][j];
            for (int i = 0; i < n - 1; ++i) {
                a[i][j] = a[i + 1][j];
            }
            a[n - 1][j] = p;
        } else {
            int i, j, x;
            cin >> i >> j >> x;
            --i, --j;
            ans[a[i][j].first][a[i][j].second] = x;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}