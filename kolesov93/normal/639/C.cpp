#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


ll mymod2(ll x) {
    return llabs(x) % 2;
}

int main() {
    #ifdef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif    	   	

    int n;
    ll k;
    scanf("%d%I64d", &n, &k);
    vector<ll> a(n + 1);
    vector<ll> aa(n + 1);
    for (int i = 0; i <= n; ++i) {   
        scanf("%I64d", &a[i]);
        aa[i] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] > 1 || a[i] < 0) {
            ll newai = mymod2(a[i]);
            ll diff = newai - a[i];
            assert(diff % 2 == 0);
            a[i + 1] -= diff / 2;
            a[i] = newai;
        }
    }

    int maxans = 0;
    while (a[maxans] == 0) {
        ++maxans;
    }
    assert(maxans <= n);

    ll val = 0;
    for (int i = n; i >= maxans; --i) {
        val = val * 2 + a[i];
        if (val > k * 2 || val < k * -2) {
            break;
        }
    }

    int ans = 0;
    for (int i = maxans; i >= 0; --i) {
        if (val > k * 2 || val < k * -2) {
            break;
        }

        ll newval = aa[i] - val;
        if (newval <= k && newval >= -k) {

            if (i == n && newval == 0) {
                // no inc
            } else {
                ++ans;
            }
        }
        val *= 2;
    }
    printf("%d\n", ans);

    return 0;
}