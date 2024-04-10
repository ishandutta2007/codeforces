#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 55;

int t, n, m;
char c[MAXN][MAXN];

bool ok (int tip) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') continue;
            if ((i + j) % 2 == tip) {
                if (c[i][j] == 'R') return 0;
            } else {
                if (c[i][j] == 'W') return 0;
            }
        }
    }
    return 1;
}

void ispis (int tip) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == tip) cout << "W"; else cout << "R";
        }
        cout << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }
        if (ok(0)) {
            cout << "YES\n";
            ispis(0);
        } else if (ok(1)) {
            cout << "YES\n";
            ispis(1);
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}