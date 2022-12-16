#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char board[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        int out = 0;
        for (int j = 0; j < m; j++) {
            if (board[n-1][j] == 'D') out++;
        }
        for (int i = 0; i < n; i++) {
            if (board[i][m-1] == 'R') out++;
        }
        cout << out << endl;
    }
}