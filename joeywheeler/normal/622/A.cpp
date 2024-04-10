#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int main() {
    ll n; scanf("%lld", &n);
    ll s = 0;
    FO(i,1,1e9) {
        if (s+i >= n) {
            printf("%lld\n", n-s);
            return 0;
        }
        s += i;
    }
}