#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD int(1e9+7)

using namespace std;

int a[3000005];
int n;

long long pw(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b&1) r *= a;
        b /= 2;
        a *= a;
        a %= MOD;
        r %= MOD;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    FO(i,0,20) FO(j,0,1<<20) {
        if (~j&(1<<i)) a[j] += a[j|(1<<i)];
    }
    long long res = 0;
    FO(i,0,1<<20) if (__builtin_popcount(i)&1) {
        res += MOD-pw(2,a[i]);
    } else {
        res += pw(2,a[i]);
    }
    printf("%lld\n", res%MOD);
}