//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;

ll n;

ll cur;

int ask(ll x)
{
    cout << "? " << x + 1 << endl;
    int res;
    cin >> res;
    cur = x;
    return res;
}

void answer(ll x)
{
    cout << "= " << x << endl;
}

void solve()
{
    cin >> n;
    ll l = 0;
    ll r = n;
    vector<ll> seq;
    while (r - l > 1)
    {
        l = (l + r) / 2;
        seq.push_back(l);
    }
    reverse(seq.begin(), seq.end());
    ll dir = 1;
    ll t = 0;
    for (ll l : seq)
    {
        t += dir * l;
        dir = -dir;
    }
    l = 0;
    r = n;
    ask(t);
    while (r - l > 1)
    {
        ll h = (l + r) / 2;
        ll to = t + dir * h;
        dir = -dir;
        if (ask(to))
            r = h;
        else
            l = h;
        t = to;
    }
    answer(r);
}

int main()
{
#ifdef ONPC
    //freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}