#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a, b, c, n;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &n);
    int res = 0;
    FO(i,0,n) {
        int x; scanf("%d", &x);
        if (b < x && x < c) res++;
    }
    printf("%d\n", res);
}