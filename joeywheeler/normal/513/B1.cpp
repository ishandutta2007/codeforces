#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int main() {
    int n; scanf("%d", &n);
    ll m; scanf("%lld", &m); m--;
    int l = 0, r = n-1;
    int a[100] = {};
    for (int i = n-2; i >= 0; i--) {
        if ((m>>i)&1ll) {
            a[r--] = n-i-1;
        } else a[l++] = n-i-1;
    }
    a[l] = n;
    FO(i,0,n) printf("%d ", a[i]);
    printf("\n");
}