#include <bits/stdc++.h>
using namespace std;

#define N 1111111
typedef long long ll;

ll dev0[N];
ll dev1[N];
void add(ll i, ll j, ll x0, ll x1) {
    assert(i <= j);
    dev0[i] += x0;
    dev1[i] += x1;
    dev0[j] -= x0;
    dev1[j] -= x1;
}

ll dev[N];
int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        ll per;
        scanf("%lld", &per);
        per--;
        ll b = max(0LL, per - i);
        ll c = min(n, per + n - i);
        add(0, b, per - i, -1);
        add(b, n - i, i - per, 1);
        add(n - i, c, per - i + n, -1);
        add(c, n, i - n - per, 1);
    }
    for (int i = 0; i < n; i++) {
        dev[i] += dev0[i] + dev1[i] * i;
        dev0[i + 1] += dev0[i];
        dev1[i + 1] += dev1[i];
    }
    assert(dev0[n] == 0);
    assert(dev1[n] == 0);
    ll mn = (1LL<<60), mk = 0;
    for (int k = 0; k < n; k++) {
        if (mn > dev[k]) {
            mn = dev[k];
            mk = k;
        }
    }
    printf("%lld %lld\n", mn, mk);
}