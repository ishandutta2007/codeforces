#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;

int b[2000005];

void ba(int i, int v) {
    //printf("%d: %d\n", i, v);
    for (i++; i < 2000005; i += i&-i) b[i] += v;
}

int bs(int i) {
    int r = 0;
    for (i++; i > 0; i -= i&-i) r += b[i];
    return r;
}

int main() {
    scanf("%d %d", &n, &k);
    long long nr = 1;

    k = min(k, n-k);
    int x = 0;
    FO(z,0,n) {
        nr++;
        int y = (x + k) % n;
        //printf("%d-%d\n", x+k-1, x);
        nr += bs(x+k-1) - bs(x);
        ba(x, 1); ba(x+n, 1);
        ba(y, 1); ba(y+n, 1);
        printf("%lld ", nr);
        x = y;
    }
    printf("\n");
}