#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<ll> build(const vector<ll>& a)
{
    int n = sz(a);
    vector<ll> ans(n);
    if (n == 0) {
        return ans;
    }
    ans[0] = a[0];
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i - 1] + a[i];
    }
    return ans;
}

int solve(const vector<ll>& v, ll val, int start)
{
    if (v.empty()) {
        return 0;
    }
    if (start == sz(v)) {
        return 0;
    }
    if (v.back() <= val) {
        return sz(v) - start;
    }
    if (v[start] > val) {
        return 0;
    }
    int lf = start, rg = sz(v);
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        if (v[md] <= val) {
            lf = md;
        } else {
            rg = md;
        }
    }
    return lf - start + 1;
}

ll get_sum(const vector<ll>& pref, int l, int r)
{
    assert(l <= r);
    ll ans = pref[r];
    if (l) {
        ans -= pref[l - 1];
    }
    return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    vector<char> likea(n, false), likeb(n, false);
    int ss;
    cin >> ss;
    while (ss--) {
        int x;
        cin >> x;
        likea[x - 1] = true;
    }

    cin >> ss;
    while (ss--) {
        int x;
        cin >> x;
        likeb[x - 1] = true;
    }

    ll ans = 1e18;

    vector<ll> both, a, b, neither;
    for (int i = 0; i < n; ++i) {
        if (likea[i] && likeb[i]) {
            both.pb(cost[i]);
        } else if (likea[i]) {
            a.pb(cost[i]);
        } else if (likeb[i]) {
            b.pb(cost[i]);
        } else {
            neither.pb(cost[i]);
        }
    }
    sort(all(both));
    sort(all(a));
    sort(all(b));
    sort(all(neither));

    vector<ll> both_pref = build(both);
    vector<ll> a_pref = build(a);
    vector<ll> b_pref = build(b);
    vector<ll> neither_pref = build(neither);

    for (int cnt = min(sz(both), m); cnt >= 0; --cnt) {
        ll sum = 0;
        int taken = cnt;
        if (cnt) {
            sum += both_pref[cnt - 1];
        }
        int l = max(k - cnt, 0);
        if (l > sz(a) || l > sz(b)) {
            continue;
        }
        if (cnt + sz(a) + sz(b) + sz(neither) < m) {
            continue;
        }
        if (l) {
            sum += a_pref[l - 1];
            sum += b_pref[l - 1];
            taken += 2 * l;
        }
        if (taken > m) {
            continue;
        }
        ll lf = -1, rg = 1e9 + 10;
        while (rg - lf > 1) {
            ll md = (lf + rg) >> 1;
            int z = solve(a, md, l) + solve(b, md, l) + solve(neither, md, 0);
            if (z + taken >= m) {
                rg = md;
            } else {
                lf = md;
            }
        }
        int pos = solve(a, rg, l) + l - 1;
        if (pos >= l) {
            sum += get_sum(a_pref, l, pos);
            taken += pos - l + 1;
        }
        pos = solve(b, rg, l) + l - 1;
        if (pos >= l) {
            sum += get_sum(b_pref, l, pos);
            taken += pos - l + 1;
        }
        pos = solve(neither, rg, 0) - 1;
        if (pos >= 0) {
            sum += get_sum(neither_pref, 0, pos);
            taken += pos + 1;
        }
        if (taken > m) {
            sum -= ll(taken - m) * rg;
        }
        assert(taken >= m);
        ans = min(ans, sum);
    }

    if (ans == ll(1e18)) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

}