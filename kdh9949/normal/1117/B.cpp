#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll k, m, fm, sm;

int main(){
    scanf("%d%lld%lld", &n, &m, &k);
    for(int i = 0; i < n; i++){
        ll x; scanf("%lld", &x);
        if(x >= fm){ sm = fm; fm = x; }
        else if(x > sm){ sm = x; }
    }
    ll a = m / (k + 1);
    ll b = m % (k + 1);
    ll r = (fm * k + sm) * a + fm * b;
    printf("%lld\n", r);
}