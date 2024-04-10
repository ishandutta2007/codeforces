#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll n, a, b, c;

int main() {
    scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
    ll g = b-c;
    ll k = 0;
    if (g <= a) {
        k = (n-b)/g;
        k -= 5; k = max(k,0ll);
        while (n-k*g >= b) k++;
        n -= k*g;
    }
    // take min(a,b) for rest
    k += n / min(a,b);
    printf("%lld\n", k);
}