#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;

double cache[2][600];
double pa[600], pb[600];

int main() {
    scanf("%d %d", &n, &k);
    FO(m,1,600) {
        pa[m] = (k-1) / 1. / k + m / 1. / k / 1. / (m+1);
        pb[m] = 1. / k / 1. / m;
    }
    double res = 0;
    FO(i,0,n) {
        FO(j,0,600) {
            if (i == 0) cache[i&1][j] = j == 1;
            else if (j == 0) cache[i&1][j] = 0;
            else if (i+1 < j) cache[i&1][j] = 0;
            else cache[i&1][j] = pa[j] * cache[~i&1][j] + pb[j] * cache[~i&1][j-1];
            res += cache[i&1][j] * (j / 2. + j / (j + 1.));
        }
    }
    printf("%.20lf\n", res);
}