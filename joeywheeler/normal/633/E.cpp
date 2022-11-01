#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int v[1000005], c[1000005];
int a[1000005];
int n, k;
double f[1000005];

int main() {
    scanf("%d%d", &n, &k);
    FO(i,0,n) scanf("%d", v+i), v[i] *= 100;
    FO(i,0,n) scanf("%d", c+i);
    multiset<int> sv, sc;
    for (int i = n-1; i >= 0; i--) {
        sv.insert(v[i]); sc.insert(c[i]);

        if (i+sz(sv) <= n-1) {
            int j = i+sz(sv);
            sv.insert(v[j]);
            sc.insert(c[j]);
        }

        while (sz(sv)) {
            int x = *sv.rbegin(), y = *sc.begin();
            a[i] = max(a[i],min(x,y));
            if (x<=y) break;
            int j = i+sz(sv)-1;
            sv.erase(sv.find(v[j]));
            sc.erase(sc.find(c[j]));
        }
    }
    sort(a,a+n);
    f[0] = 0;
    FO(i,1,n+1) f[i] = f[i-1] + log(i);
    double ans = 0;
    FO(i,0,n) {
        int r = n-i-1;
        if (r >= k-1) {
            ans += a[i] * exp((f[r] - f[k-1] - f[r-k+1]) - (f[n] - f[k] - f[n-k]));
        }
    }
    printf("%.9lf\n", ans);
}