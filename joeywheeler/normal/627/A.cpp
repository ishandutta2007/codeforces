#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int main() {
    ll s, x; scanf("%lld %lld", &s, &x);
    ll g = s-x;
    if (g%2 == 1) {
        printf("0\n");
        return 0;
    }
    g /= 2;

    ll ans = 1;
    FO(i,0,60) {
        if (x&(1ll<<i)) {
            ans *= 2;

            if (g&(1ll<<i)) {
                printf("0\n");
                return 0;
            }
        }
    }
    if (x == s) ans -= 2;
    printf("%lld\n", ans);
}