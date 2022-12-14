#include <bits/stdc++.h>

using namespace std;

int n;
int A[200005], B[200005];
int P[200005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", A + i);
    for (int i = 1; i <= n; i++) scanf("%d", B + i);
    for (int i = 1; i <= n; i++) P[A[i]] = i, A[i] = 0;
    for (int i = 1; i <= n; i++) {
        int j = P[B[i]];
        A[(i - j + n) % n]++;
    }
    printf("%d\n", *max_element(A, A + n));
    return 0;
}