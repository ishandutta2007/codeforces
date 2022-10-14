#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, m;
int lo[MAXN], hi[MAXN];
int sol[MAXN][MAXN];
vector <int> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            v[i].clear();
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                v[i].push_back(x);
                sort(v[i].begin(), v[i].end());
            }
            lo[i] = 0; hi[i] = m - 1;
        }
        for (int i = 0; i < m; i++) {
            int mn = 1e9, row = -1;
            for (int j = 0; j < n; j++) {
                if (v[j][lo[j]] < mn) {
                    mn = v[j][lo[j]];
                    row = j;
                }
            }
            for (int j = 0; j < n; j++) {
                if (j == row) {
                    sol[j][i] = v[j][lo[j]];
                    lo[j]++;
                } else {
                    sol[j][i] = v[j][hi[j]];
                    hi[j]--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << sol[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}