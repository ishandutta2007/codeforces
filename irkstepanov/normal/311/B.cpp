#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p. y * q.x;
}

ll dot(const pt& p, const pt& q) {
    return p.x * q.x + p.y * q.y;   
}

ll get(const vector<pt>& vct, const pt& q) {
    int lf = 0, rg = sz(vct) - 1;
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        ll val = dot(vct[md + 1] - vct[md], q);
        if (val < 0) {
            lf = md;
        } else {
            rg = md;
        }
    }
    ll ans = dot(vct[lf], q);
    for (int i = lf + 1; i <= rg; ++i) {
        ans = min(ans, dot(vct[i], q));
    }
    return ans;
}

void add(vector<pt>& vct, const pt& p) {
    while (sz(vct) >= 2 && cross(vct[sz(vct) - 1] - vct[sz(vct) - 2], p - vct.back()) <= 0) {
        vct.pop_back();
    }
    vct.pb(p);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n, m, p;
    cin >> n >> m >> p;

    vector<ll> d(n);
    for (int i = 1; i < n; ++i) {
        cin >> d[i];
    }

    vector<ll> pref(n);
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + d[i];
    }

    vector<ll> a(m);
    for (int i = 0; i < m; ++i) {
        int pos;
        ll t;
        cin >> pos >> t;
        --pos;
        t -= pref[pos];
        a[i] = t;
    }

    sort(all(a));

    vector<vector<ll> > dp(p + 1, vector<ll>(m));
    for (int i = 0; i < m; ++i) {
        dp[1][i] = a[i] * (i + 1);
    }
    vector<vector<pt> > convex(p + 1);
    for (int i = 0; i < m; ++i) {
        for (int k = 2; k <= p; ++k) {
            dp[k][i] = dp[k - 1][i];
            if (i == 0) {
                continue;
            }
            pt p = {-a[i], 1};
            ll opt = get(convex[k - 1], p);
            dp[k][i] = min(dp[k][i], opt + a[i] * i);
        }
        for (int k = 1; k <= p; ++k) {
            pt p = {i, dp[k][i]};
            add(convex[k], p);
        }
    }

    ll ans = dp[1][m - 1];
    for (int k = 2; k <= p; ++k) {
        ans = min(ans, dp[k][m - 1]);
    }
    for (int i = 0; i < m; ++i) {
        ans -= a[i];
    }
    cout << ans << "\n";

}