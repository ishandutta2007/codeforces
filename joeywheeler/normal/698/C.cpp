#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

double p[25];
double s[1<<20];
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    int l = 1<<n;
    FO(i,0,n) {
        scanf("%lf", p+i);
    }
    FO(i,0,l) {
        FO(j,0,n) if (i&(1<<j)) {
            s[i] += p[j];
        }
    }
    FO(i,0,l) if (s[i] < 1 - 1e-6) {
        s[i] = 1. / (1. - s[i]);
    }
    FO(i,0,n) FO(j,0,l) if (j & (1<<i)) s[j] -= s[j^(1<<i)];
    FO(i,0,n) {
        if (p[i]) {
            double ans = 0;
            FO(j,0,l) if (~j & (1<<i)) if (__builtin_popcount(j) <= k-1) {
                ans += s[j];
            }
            printf("%.9lf ", ans * p[i]);
        } else printf("0 ");
    }
    printf("\n");
}