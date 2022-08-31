#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1111;

char grid[N][N];
bool solve(int n, int a, int b) {
    if (a != 1 && b != 1) return false;
    if (b != 1) {
        if (!solve(n, b, a)) return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] ^= i != j;
            }
        }
        return true;
    }

    assert(b == 1);
    if (a == 1 && (n == 2 || n == 3)) return false;

    for (int i = --a; i + 1 < n; i++) {
        grid[i][i + 1] = grid[i + 1][i] = 1;
    }
    return true;
}

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (solve(n, a, b)) {
        puts("YES");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) grid[i][j] += '0';
            grid[i][n] = 0;
            printf("%s\n", grid[i]);
        }
    } else {
        puts("NO");
    }
}