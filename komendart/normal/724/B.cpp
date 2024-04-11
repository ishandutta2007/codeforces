#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;

int n, m;
int a[maxn][maxn];

void check() {
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != j + 1) cnt++;
        }
        if (cnt > 2) return;
    }
    cout << "YES\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) swap(a[k][i], a[k][j]);
            check();
            for (int k = 0; k < n; k++) swap(a[k][i], a[k][j]);
        }
    }

    cout << "NO\n";
}