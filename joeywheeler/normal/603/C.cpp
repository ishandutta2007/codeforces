#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int f[1000];

int g(int n) {
    if (n < 10) return f[n];
    if (n%2 == 1) return 0;
    int t0 = 0;
    while (n%2 == 0) {
        t0++;
        n /= 2;
    }
    return (n == 1 && t0%2 == 0) || (n == 3 && t0%2 == 1) || (n != 1 && n != 3 && t0%2 == 0) ? 2 : 1;
}

int F(int n) {
    if (n <= 2) return n;
    else return !(n%2);
}

int main() {
    FO(i,1,100) {
        for (f[i] = 0; ;f[i]++) {
            if (f[i] != f[i-1] && (i%2 || f[i] != f[i/2])) break;
        }
    }
    int n, k; scanf("%d%d", &n, &k);
    int r = 0;
    FO(i,0,n) {
        int a; scanf("%d", &a);
        if (k&1) r ^= g(a);
        else r ^= F(a);
    }
    printf(r ? "Kevin\n" : "Nicky\n");
}