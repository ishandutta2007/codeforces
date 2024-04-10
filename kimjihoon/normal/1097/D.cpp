#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define ll long long
ll md = 1000000007;

vector<pair<ll, int> > v;
ll ft[99], r[99];

ll rv(ll n)
{
    ll k = md - 2, a = 1;
    while (k > 0) {
        if (k % 2)
            a = (a * n) % md;
        k /= 2; n = (n * n) % md;
    }
    return a;
}

int main()
{
    ll n; int k; cin >> n >> k;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (v.size() > 0 && v.back().first == i)
                v.back().second++;
            else
                v.push_back(make_pair(i, 1));
            n /= i; i = 1;
        }
    }
    if (n != 0) {
        if (v.size() > 0 && v.back().first == n)
            v.back().second++;
        else
            v.push_back(make_pair(n, 1));
    }
    ll ans = 1;
    for (int i = 0; i < v.size(); i++) {
        v[i].second++;
        for (int j = 1; j <= v[i].second; j++) {
            ft[j] = 1;
            for (int l = 2; l <= v[i].second; l++)
                if (j != l)
                    ft[j] = (ft[j] * 1LL * l) % md;
        }
        for (int j = 0; j < v[i].second; j++)
            r[j] = ft[v[i].second];
        ll p = ft[1];
        for (int j = 1; j < k; j++) {
            ll s = 0;
            for (int l = v[i].second - 1; l >= 0; l--) {
                s = (s + ft[l + 1] * r[l]) % md;
                r[l] = s;
            }
            p = (p * ft[1]) % md;
        }
        ll t = 1, s = 0;
        for (int j = 0; j < v[i].second; j++) {
            s = (s + t * r[j]) % md; t = (t * v[i].first) % md;
        }
        s = (s * rv(p)) % md;
        ans = (ans * s) % md;
    }
    cout << ans << '\n';
    return 0;
}