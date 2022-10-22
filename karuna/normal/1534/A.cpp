#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 55;

int n, m; string S[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            string T; cin >> T;
            S[i] = "." + T;
        }
        int f = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (S[i][j] != '.') {
                int x = (i + j) & 1;
                if (S[i][j] == 'R') {
                    if (f == -1) f = x;
                    else if (f != x) f = -2;
                }
                else {
                    if (f == -1) f = !x;
                    else if (f == x) f = -2;
                }
                if (f == -2) break;
            }
            if (f == -2) break;
        }
        if (f == -2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (f == -1) f = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (f == ((i + j) & 1)) cout << 'R';
                else cout << 'W';
            }
            cout << '\n';
        }
    }
}