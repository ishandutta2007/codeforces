#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int cache[30005][1200];
int f[30005];
int d;

int solve(int i, int j) {
    if (i >= 30003) return 0;
    if (j <= 0) return 0;
    if (cache[i][j-d + 600] != -1) return cache[i][j-d + 600];
    int res = f[i];
    res += max(max(solve(i+j,j), solve(i+j-1,j-1)), solve(i+j+1,j+1));
    return cache[i][j-d + 600] = res;
}

int main() {
    memset(cache, -1, sizeof cache);
    int n;
    scanf("%d %d", &n, &d);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        f[x]++;
    }
    printf("%d\n", solve(d,d));
}