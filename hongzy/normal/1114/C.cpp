#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
ll n, b;
vector<ll> p, c;

int main() {
    scanf("%I64d%I64d", &n, &b);
    ll x = b, cnt;
    for(ll i = 2; i * i <= b; i ++) {
        if(x % i == 0) {
            p.push_back(i);
            cnt = 0;
            while(x % i == 0) cnt ++, x /= i;
            c.push_back(cnt);
        }
    }
    if(x > 1) {
        p.push_back(x);
        c.push_back(1);
    }
    ll ans = 9e18;
    for(int i = 0; i < p.size(); i ++) {
        ll now = 0, pi = p[i];
        for(; ; pi *= p[i]) {
            now += n / pi;
            if(pi > n / p[i]) break ;
        }
        ans = min(ans, now / c[i]);
    }
    printf("%I64d\n", (ll) ans);
    return 0;
}
/*
13 12
*/