#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int A[MAXN + 1];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n, c = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            if (A[i] < 0) {
                A[i] = -A[i];
                c++;
            }
        }
        for (int i = 0; i < c; i++)
            A[i] = -A[i];
        puts(is_sorted(A, A + n) ? "YES" : "NO");
    }
    return 0;
}