#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

vector<ll> f(vector<ll> cur, ll a, ll w) {
    ll x = cur[0], k = cur[1], l = cur[2];
    if (a >= x) {
        if (w >= k)
            return {x, 0, 0};
        else
            return {x, k - w, l};
    } else {
        if (a * w >= x * k - l)
            return {x, 0, 0};
        else {
            ll lf = x * k  - l - a * w;
            ll d = (lf - 1) / x + 1;
            return {x, d, d * x - lf};
        }
    }

}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    ll t, n, a, b, k;

    cin >> t >> n >> a >> b >> k;

    ll ca = (n + 1) / 2;
    ll cb = n / 2;

    if(a < b) {
        swap(a, b);
        swap(ca, cb);
    }

    ll l = 0, r = t + 1;
    while (l != r - 1) {
        ll m = (l + r) >> 1;

        vector<ll> cur = {m, k, 0};

        cur = f(cur, b, cb);
        cur = f(cur, a, ca);

        if (cur[1])
            r = m;
        else
            l = m;
    }

    cout << l << '\n';

    return 0;
}