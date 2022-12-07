#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 55;
int w[N + N];
char a[N][N], b[N][N];

int fath(int x) {
    if (w[x] == x) return w[x];
    w[x] = fath(w[x]);
    return w[x];
}
void un(int x, int y) {
    w[fath(x)] = fath(y);
}

int main() {
    int n, m;
    cin >> n >> m;
    scanf("\n");
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    for (int i = 0; i < n + m; ++i) {
        w[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '#') continue;
            un(i, n + j);
        }
    }

    memset(b, '.', sizeof(b));

    for (int cls = 0; cls < n + m; ++cls) {
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i < n; ++i) {
            if (fath(i) == cls) {
                rows.push_back(i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (fath(n + i) == cls) {
                cols.push_back(i);
            }
        }

        for (int col : cols) {
            for (int row : rows) {
                b[row][col] = '#';
            }
        }
    }
    bool cool = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cool &= (a[i][j] == b[i][j]);
        }
    }
    if (cool) puts("Yes");
    else puts("No");

    return 0;
}