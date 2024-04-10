#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[55][55];
int R[55], C[55];
bool solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= max(n, m); i++) R[i] = C[i] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        scanf("%d", A[i] + j);
        if (A[i][j]) R[i] = C[j] = 1;
    }
    int r = 0, c = 0;
    for (int i = 1; i <= n; i++) if (!R[i]) r++;
    for (int i = 1; i <= m; i++) if (!C[i]) c++;
    return min(r, c) & 1; 
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) printf(solve() ? "Ashish\n" : "Vivek\n");
    return 0;
}