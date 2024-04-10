#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 998244353;

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

ll rightBound[6];

pair<bool, ll> isRoot(ll n, int k) {
    ll lf = 0, rg = rightBound[k];
    while (rg - lf > 1) {
        ll md = (lf + rg) >> 1;
        ll val = 1;
        for (int i = 0; i < k; ++i) {
            val *= md;
        }
        if (val <= n) {
            lf = md;
        } else {
            rg = md;
        }
    }
    ll val = 1;
    for (int i = 0; i < k; ++i) {
        val *= lf;
    }
    return {val == n, lf};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    rightBound[2] = ll(2e9);
    rightBound[3] = ll(2e6);
    rightBound[4] = ll(5e4);
    rightBound[5] = ll(5e3);

    map<ll, int> mapa;
    int n;
    cin >> n;
    vector<ll> vct;
    while (n--) {
        ll x;
        cin >> x;
        pair<bool, ll> p = isRoot(x, 4);
        if (p.first) {
            mapa[p.second] += 4;
            continue;
        }
        p = isRoot(x, 3);
        if (p.first) {
            mapa[p.second] += 3;
            continue;
        }
        p = isRoot(x, 2);
        if (p.first) {
            mapa[p.second] += 2;
            continue;
        }
        vct.pb(x);
    }

    int ans = 1;
    map<ll, int> cnt;
    while (!vct.empty()) {
        ll x = vct.back();
        bool done = false;
        for (auto it : mapa) {
            ll val = __gcd(it.first, x);
            if (val != 1 && val != x) {
                ++mapa[val];
                ++mapa[x / val];
                done = true;
                break;
            }
        }
        if (done) {
            vct.pop_back();
            continue;
        }
        for (ll y : vct) {
            ll val = __gcd(x, y);
            if (val != 1 && val != x) {
                ++mapa[val];
                ++mapa[x / val];
                done = true;
                break;
            }
        }
        if (done) {
            vct.pop_back();
            continue;
        }
        vct.pop_back();
        ++cnt[x];
    }

    for (auto it : mapa) {
        mul(ans, it.second + 1);
    }
    for (auto it : cnt) {
        mul(ans, it.second + 1);
        mul(ans, it.second + 1);
    }
    cout << ans << "\n";
    cout.flush();

    
}