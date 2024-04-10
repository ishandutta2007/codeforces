#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
const ll mod = 1e9 + 7;

struct poll {
    ll a, b, c, d;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pair<ll, ll> p[3];
    cin >> p[0].first >> p[0].second;
    cin >> p[1].first >> p[1].second;
    cin >> p[2].first >> p[2].second;
    sort(p, p + 3, [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        return a.first < b.first;
    });
    ll mmin = p[1].second, mmax = p[1].second;
    mmin = min(mmin, p[0].second);
    mmax = max(mmax, p[0].second);
    mmin = min(mmin, p[2].second);
    mmax = max(mmax, p[2].second);

    if (mmin == mmax) {
        cout << 1 << endl;
        cout << p[0].first << ' ' << mmin << ' ' << p[2].first << ' ' << mmin << endl;
        return 0;
    }

    ll mx = max(p[0].second, p[2].second);
    mx = max(mx, p[1].second);
    ll mn = min(p[0].second, p[2].second);
    mn = min(mn, p[1].second);

    vector<poll> v;
    v.push_back({p[1].first, mn, p[1].first, mx});
    if (p[0].first != p[1].first) v.push_back({p[0].first, p[0].second, p[1].first, p[0].second});
    if (p[2].first != p[1].first) v.push_back({p[2].first, p[2].second, p[1].first, p[2].second});

    cout << v.size() << endl;
    for (auto &i: v) cout << i.a << ' ' << i.b << ' ' << i.c << ' ' << i.d << endl;
}