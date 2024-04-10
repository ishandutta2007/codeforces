#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int main() {
    ll res = 0;
    int n; scanf("%d", &n);
    FO(i,0,n) {
        ll k, a; scanf("%lld %lld", &k, &a);
        int t = 1;
        while ((1ll << (2*t)) < a) t++;
        res = max(res,k+t);
    }
    printf("%lld\n", res);
}