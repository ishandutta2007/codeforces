#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a);i<(b);i++)
#define sz(v) int(v.size())

using namespace std;

int f(int x) {
    if (x == 0) return 1;
    else {
        int u = x % 10;
        if (u == 0) return f(x/10);
        else return f(x/10) * u;
    }
}

int g[1000005];
int h[1000005][10];

int main() {
    fo(i,1,10) g[i] = i;
    fo(i,10,1000004) {
        assert(f(i) < i);
        g[i] = g[f(i)];
    }
    fo(i,1,1000004) h[i+1][g[i]] = 1;
    fo(i,1,1000005) fo(j,0,10) 
        h[i][j] += h[i-1][j];
    int q; scanf("%d", &q);
    fo(_,0,q) {
        int l, r, k; scanf("%d %d %d", &l, &r, &k);
        r++;
        printf("%d\n", h[r][k] - h[l][k]);
    }
}