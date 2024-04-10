#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll inf = 1000000000ll * 1000000000ll;
const ll nmax = 1442251;///unreachable

int main()
{
    ll x;
    scanf("%I64d", &x);
    vector<ll> sumSqr(nmax);
    for (ll i = 1; i < nmax; ++i) {
        sumSqr[i] = sumSqr[i - 1] + i * i;
    }
    vector<pair<ll, ll> > ans;
    for (ll n = 1; n < nmax; ++n) {
        ll r = x - sumSqr[n - 1];
        ll t = n * (n - 1) / 2;
        r += t * n;
        if (r < 0) {
            continue;
        }
        r *= 2;
        if (r % (n * (n + 1))) {
            continue;
        }
        ll m = (r / n) / (n + 1);
        if (m < n) {
            continue;
        }
        ans.pb(mp(n, m));
        if (n != m) {
           ans.pb(mp(m, n));
        }
    }
    sort(all(ans));
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i) {
        printf("%I64d %I64d\n", ans[i].first, ans[i].second);
    }
}