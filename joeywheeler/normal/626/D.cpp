#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long long d[5005];
long long p[5005];
int n;
int a[2005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf(" %d", &a[i]);
    sort(a,a+n);
    FO(i,0,n) FO(j,0,i) d[a[i]-a[j]]++;
    FO(i,0,5005) FO(j,0,5005) {
        if (i+j >= 5005) break;
        p[i+j] += d[i]*1ll*d[j];
    }
    for (int i = 5003; i >= 0; i--) d[i] += d[i+1];
    long long res = 0;
    FO(i,0,5004) res += p[i] * d[i+1];
    long long tot = n*(n-1)/2;
    tot = tot*tot*tot;
    long double ld = res / 1.L / tot;
    double dd = ld;
    printf("%.10lf\n", dd);
}