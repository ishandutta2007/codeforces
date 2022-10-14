#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 205;

int n, m, ok = 1;
int w[MAXN][MAXN], col[MAXN];
vector <int> v[MAXN];

void dfs (int x, int flg) {
    col[x] = flg;
    for (auto sus : v[x]) {
        if (col[sus] == 0) {
            dfs(sus, 3 - flg);
        } else {
            if (col[sus] == col[x]) ok = 0;
        }
    }
}

void floyd_warshall () {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (w[i][k] + w[k][j] < w[i][j]) w[i][j] = w[i][k] + w[k][j];
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) w[i][j] = 1e9;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, tip;
        cin >> a >> b >> tip;
        v[a].push_back(b);
        v[b].push_back(a);
        if (tip == 0) {
            w[a][b] = w[b][a] = 1;
        } else {
            w[a][b] = 1; w[b][a] = -1;
        }
    }
    dfs(1, 1);
    floyd_warshall();
    for (int i = 1; i <= n; i++) {
        if (w[i][i] < 0) ok = 0;
    }
    if (!ok) {
        cout << "NO";
    } else {
        cout << "YES\n";
        int mx = -1e9, a = -1, b = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (w[i][j] > mx) {
                    mx = w[i][j];
                    a = i; b = j;
                }
            }
        }
        cout << mx << endl;
        for (int i = 1; i <= n; i++) {
            cout << w[a][i] << " ";
        }
    }
    return 0;
}