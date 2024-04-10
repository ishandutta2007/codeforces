#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll A, ll x)
{
    ll sz0 = A / x;
    ll sz1 = A / x + 1;
    ll cnt0 = x - A % x;
    ll cnt1 = A % x;
    return cnt0 * sz0 * sz0 + cnt1 * sz1 * sz1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    set<pair<ll, int> > s;
    vector<ll> p(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = 1;
        s.insert({f(a[i], 2) - f(a[i], 1), i});
        ans += a[i] * a[i];
    }
    //cout << f(a[0], 1) << " " << f(a[0], 2) << " " << f(a[0], 3) << endl;
    //cout << ans << endl;
    for (int i = n; i < k; i++)
    {
        auto it = *(s.begin());
        s.erase(s.begin());
        ans += it.first;
        p[it.second]++;
        //cout << it.first << " " << it.second << endl;
        s.insert({f(a[it.second], p[it.second] + 1) - f(a[it.second], p[it.second]), it.second});
    }
    cout << ans;
}