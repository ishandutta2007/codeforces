#include <bits/stdc++.h>

using namespace std;

const int C = 205;
const int N = 1005;

int n;
int f[C][N];

bool dfs(int d, int i) {
    if (d == n) {
        int tot = 0;
        for (int i = 0; i < n; i++) tot += f[n][i] * f[n][i];
        int a = sqrt(tot);
        if (a * a != tot) return false;
        return true;
    }
    for (; i <= 4; i++) {
        f[n][d] = i;
        if (dfs(d + 1, i)) return true;
        ;
    }
    return false;
}

void foo() {
    if (!dfs(0, 1)) cout << "no" << endl;
}

int main() {
    for (int i = 1; i <= 100; i++) {
        n = i;
        foo();
    }
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (j) cout << " ";
            cout << f[x][i] * f[y][j];
        }
        cout << endl;
    }
    return 0;
}