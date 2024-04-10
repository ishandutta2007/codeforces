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

const int nmax = 500500;

int w[nmax], c[nmax], a[nmax];

const ll inf = 1e18;

struct Number {
    ll a, b;
    Number() : a(0), b(0) {}
    Number(ll x) : a(0), b(x) {}
    Number(ll a, ll b) : a(a), b(b) {}
    Number& operator+=(ll v) {
        b += v;
        if (b >= inf) {
            b -= inf;
            ++a;
        }
        return *this;
    }
};

Number ans;
ld rem;

mt19937 rr(998244353);
int total;

void solve(vector<int> ids, ll curr) {
    if (curr == total) {
        return;
    }
    if (sz(ids) == 1) {
        int v = ids[0];
        ans += ((total - curr) * c[v] / w[v]);
        rem += ld((total - curr) * c[v] % w[v]) / w[v];
        return;
    }
    int pos = rr() % sz(ids);
    vector<int> lf, rg;
    for (int i = 0; i < sz(ids); ++i) {
        if (ll(c[ids[i]]) * w[ids[pos]] < ll(c[ids[pos]]) * w[ids[i]]) {
            lf.pb(ids[i]);
        } else if (ll(c[ids[i]]) * w[ids[pos]] == ll(c[ids[pos]]) * w[ids[i]] && i <= pos) {
            lf.pb(ids[i]);
        } else {
            rg.pb(ids[i]);
        }
    }
    ll sum = 0;
    for (int v : lf) {
        sum += w[v];
    }
    if (curr + sum > total) {
        solve(lf, curr);
    } else {
        for (int v : lf) {
            curr += w[v];
            ans += c[v];
        }
        solve(rg, curr);
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m >> total;

    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<int> vct(m);
    for (int i = 0; i < m; ++i) {
        vct[i] = i;
    }

    for (int d = 1; d <= n; ++d) {
        solve(vct, 0);
        for (int j = 0; j < m; ++j) {
            c[j] -= a[j];
        }
    }

    ans += ll(rem);
    rem -= ll(rem);

    if (ans.a > 0) {
        printf("%lld", ans.a);
        printf("%018lld", ans.b);
    } else {
        printf("%lld", ans.b);
    }
    ld deg = 0.1;
    printf(".");
    for (int i = 0; i < 15; ++i) {
        int maxx = 0;
        for (int j = 0; j < 10; ++j) {
            if (rem >= deg * j) {
                maxx = j;
            }
        }
        printf("%d", maxx);
        rem -= deg * maxx;
        deg /= 10;
    }

}