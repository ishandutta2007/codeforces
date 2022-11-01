#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int cst(int n) {
    int res = 1;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) res = n/i;
    }
    return res;
}

int f[50];

int main() {
    f[1] = 2e9;
    FO(i,2,50) {
        f[i] = cst(i);
        FO(j,2,i-1) f[i] = min(f[i], f[j]+f[i-j]);
    }
    int n; scanf("%d", &n);
    if (n < 50) printf("%d\n", f[n]);
    else if (cst(n) == 1) puts("1"); // only case when 1
    else if (n % 2 == 0 || cst(n-2) == 1) puts("2");
    else puts("3");
}