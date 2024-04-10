#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int x[1001][1001], mi[1001][1001], ma[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> x[i][j];
                if(i && j) {
                    mi[i][j] = min(mi[i-1][j], mi[i][j-1]) + x[i][j];
                    ma[i][j] = max(ma[i-1][j], ma[i][j-1]) + x[i][j];
                }
                else if(i) {
                    mi[i][j] = mi[i-1][j] + x[i][j];
                    ma[i][j] = ma[i-1][j] + x[i][j];
                }
                else if(j) {
                    mi[i][j] = mi[i][j-1] + x[i][j];
                    ma[i][j] = ma[i][j-1] + x[i][j];
                }
                else {
                    mi[i][j] = ma[i][j] = x[i][j];
                }
            }
        }
        if((n+m) % 2 == 0) {
            cout << "NO\n";
        }
        else if(mi[n-1][m-1] <= 0 && ma[n-1][m-1] >= 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}