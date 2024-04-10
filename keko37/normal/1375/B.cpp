#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 305;

int t, n, m;
int a[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ok (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int f (int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny)) cnt++;
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        bool moze = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int br = f(i, j);
                if (br < a[i][j]) moze = 0;
                while (a[i][j] < br) a[i][j]++;
            }
        }
        if (moze) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << a[i][j] << " ";
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}