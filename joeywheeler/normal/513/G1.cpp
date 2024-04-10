#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
double cache[35][35][205];
bool seen[35][35][205];

double p(int i, int j, int k) {
    if (i > j) return 1. - p(j,i,k);
    if (seen[i][j][k]) return cache[i][j][k];
    if (k == 0) return i < j;
    //seen[i][j][k] = true;
    double res = 0;
    double tot = 0;
    FO(l,0,n) FO(r,l,n) {
        // l to r, r to l
        int ni = l <= i && i <= r ? l+r-i : i;
        int nj = l <= j && j <= r ? l+r-j : j;
        res += p(ni, nj, k-1);
        tot++;
    }
    res /= tot;
    return cache[i][j][k] = res;
}

int a[400];

int main() {
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    FO(i,0,n) scanf("%d", a+i);
    double res = 0;
    FO(i,0,n) FO(j,i+1,n) {
        if (a[i] > a[j]) res += p(i,j,k);
        else res += p(j,i,k);
    }
    printf("%.15lf\n", res);
}