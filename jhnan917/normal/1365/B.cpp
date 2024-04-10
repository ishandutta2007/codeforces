#include <bits/stdc++.h>

using namespace std;

int n;
int A[505], B[505];
bool solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", A + i);
    int C[2] = {};
    bool inc = 1;
    for (int i = 1; i <= n; i++) scanf("%d", B + i), C[B[i]]++, inc &= A[i - 1] <= A[i];
    return inc || C[0] && C[1];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) printf(solve() ? "Yes\n" : "No\n");
    return 0;
}