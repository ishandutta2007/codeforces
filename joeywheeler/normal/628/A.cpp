#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, b, p;
int x, y;

int main() {
    scanf("%d %d %d", &n, &b, &p);
    y = n*p;
    while (n > 1) {
        int k = 1;
        while (k*2 <= n) k *= 2;
        k /= 2;
        x += (2*b+1)*k;
        n -= k;
    }
    printf("%d %d\n", x, y);
}