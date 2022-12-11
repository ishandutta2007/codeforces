 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = 0;
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    sum = pref[n - 1];
    vector<ll> suff(n);
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = suff[i + 1] + a[i];
    }

    map<ll, vector<int> > m;
    for (int i = 0; i < n; ++i) {
        m[suff[i]].pb(i);
    }

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll val = pref[i];
        if (sum == (ll)(3) * val) {
            if (m[val].empty()) {
                continue;
            }
            int pos = upper_bound(all(m[val]), i + 1) - m[val].begin();
            ans += sz(m[val]) - pos;
        }
    }

    cout << ans << "\n";

}