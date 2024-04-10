#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int c[305], l[305];

int fl(int x) {
    int r = 1;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) {
            r *= i;
            while (x%i==0) x /= i;
        }
    }
    if (x != 1) r *= x;
    return r;
}

int gcd(int a, int b) {
    return a?gcd(b%a,a):b;
}

map<int,int> cache[305];

int dp(int i, int g) {
    if (g == 1) return 0;
    if (i == n) return 1e9;
    if (cache[i].count(g)) return cache[i][g];
    int res = 1e9;
    res = min(res, c[i] + dp(i+1, gcd(g,l[i])));
    res = min(res, dp(i+1, g));
    return cache[i][g] = res;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", l+i);
    FO(i,0,n) scanf("%d", c+i);
    FO(i,0,n) l[i] = fl(l[i]);
    int r = dp(0,0);
    if (r > 8e8) r = -1;
    printf("%d\n", r);
}