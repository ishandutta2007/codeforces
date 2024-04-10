#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll inf = 1e18;

ll solve(ll val, const vector<ll>& v) {
    int pos = lower_bound(all(v), val) - v.begin();
    ll ans = inf;
    for (int i = max(pos - 2, 0); i <= min(pos + 2, sz(v) - 1); ++i) {
        ans = min(ans, abs(val - v[i]));
    }
    return ans;
}

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    vector<ll> sums;
    ll curr = 0;
    for (int j = 0; j < n; ++j) {
        if (j & 1) {
            curr -= b[j];
        } else {
            curr += b[j];
        }
    }
    sums.pb(curr);
    for (int j = n; j < m; ++j) {
        curr -= b[j - n];
        curr *= (-1);
        if (n & 1) {
            curr += b[j];
        } else {
            curr -= b[j];
        }
        sums.pb(curr);
    }

    sort(all(sums));
    sums.resize(unique(all(sums)) - sums.begin());

    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            s -= a[i];
        } else {
            s += a[i];
        }
    }
    cout << solve(s, sums) << "\n";

    while (q--) {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        --l, --r;
        int len = r - l + 1;
        if (len & 1) {
            if (l & 1) {
                s -= x;
            } else {
                s += x;
            }
        }
        cout << solve(s, sums) << "\n";
    }

}