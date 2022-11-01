#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

bool prime(int x) {
    FO(i,2,x) if (x%i == 0) return false;
    return true;
}

long long pw(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b&1) res *= a;
        a *= a;
        b /= 2;
        res %= mod;
        a %= mod;
    }
    return res;
}

int a[100005];

int main() {
    int n; scanf("%d", &n);
    if (n == 4) {
        printf("YES\n");
        printf("1 3 2 4\n");
    } else if (n == 1) {
        printf("YES\n");
        printf("1\n");
    } else if (!prime(n)) {
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("1\n");
        FO(i,1,n-1) printf("%lld\n", ((i+1)*pw(i,n-2,n)) % n);
        printf("%d\n", n);
    }
}