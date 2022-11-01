#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int a[5005],f[5005];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) scanf("%d %*s", &a[i]);
    a[n] = m+5;
    f[n] = 0;
    int r = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j <= n; j++) if (a[j] >= a[i]) f[i] = max(f[i],1+f[j]);
        r = max(r,f[i]);
    }
    printf("%d\n", n-r);
}