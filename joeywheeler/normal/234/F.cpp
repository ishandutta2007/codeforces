#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 210
#define MAX_A 40010

#define INFTY 2000000000

using namespace std;

int n;
int h[MAX_N];
int hcum[MAX_N];
int A, B;
int c[2][MAX_A][2];

void input() {
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 0; i < n; i++) {
        scanf("%d", h+i);
        hcum[i+1] = hcum[i] + h[i];
    }
}

int cost(int i, int prev, int col) {
    if (i == 0 || prev == col) {
        return 0;
    } else {
        return min(h[i], h[i-1]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    for (int i = n-1; i >= 0; i--) {
        for (int p = 0; p <= 1; p++) {
            for (int a = 0; a <= A; a++) {
                int b = A+B - a - hcum[i];
                c[i&1][a][p] = INFTY;
                if (a >= h[i]) {
                    c[i&1][a][p] = min(c[i&1][a][p], cost(i, p, 0) + c[(i+1)&1][a-h[i]][0]);
                }
                if (b >= h[i]) {
                    c[i&1][a][p] = min(c[i&1][a][p], cost(i, p, 1) + c[(i+1)&1][a][1]);
                }
            }
        }
    }
    printf("%d\n", c[0][A][0] >= INFTY ? -1 : c[0][A][0]);
}