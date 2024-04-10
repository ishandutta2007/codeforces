#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef bitset<500> m[500];

void mul(m a, m b, m res) {
    m bt;
    FO(i,0,500) FO(j,0,500) bt[j][i] = b[i][j];
    FO(i,0,500) FO(j,0,500) res[i][j] = (a[i] & bt[j]).any();
}

m f[64][2];
int n, M;

bool any(m a, bitset<500> im) {
    FO(i,0,500) if (im[i] && a[i].any()) return true;
    return false;
}

long long ans = 0;

void go(bitset<500> im, int i, int w) {
    if (i < 0) return;
    if (any(f[i][w], im)) {
        ans |= 1ll << i;
        bitset<500> nim;
        FO(j,0,500) if (im[j]) nim |= f[i][w][j];
        go(nim, i-1, !w);
    } else go(im, i-1, w);
}

int main() {
    scanf("%d %d", &n, &M);
    FO(i,0,M) {
        int x, y, t; scanf("%d %d %d", &x, &y, &t);
        x--; y--;
        f[0][t][x][y] = 1;
    }
    FO(i,1,60) {
        mul(f[i-1][0], f[i-1][1], f[i][0]);
        mul(f[i-1][1], f[i-1][0], f[i][1]);
    }
    bitset<500> im;
    im[0] = 1;
    go(im, 59, 0);
    if (ans > 1000000000000000000ll) ans = -1;
    printf("%lld\n", ans);
}