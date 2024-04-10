// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int a[1005][1005];
bool v[1005][1005];

vector<int> sol;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!v[i][j]) {
                v[i][j] = 1;
                int cnt = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();

                    auto go = [&](int ii, int jj) {
                        if (!v[ii][jj]) {
                            v[ii][jj] = 1;
                            q.push({ii, jj});
                            cnt++;
                        }
                    };

                    if ((a[x][y] & 8) == 0) go(x-1, y);
                    if ((a[x][y] & 4) == 0) go(x, y+1);
                    if ((a[x][y] & 2) == 0) go(x+1, y);
                    if ((a[x][y] & 1) == 0) go(x, y-1);
                }

                sol.push_back(cnt);
            }
        }
    }

    sort(begin(sol), end(sol), greater<int>());
    for (int x : sol) cout << x << ' ';
    cout << '\n';
}