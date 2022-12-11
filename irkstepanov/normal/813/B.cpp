#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, y, l, r;
    cin >> x >> y >> l >> r;

    vector<ll> v;

    vector<ll> xs;
    ll val = 1;
    while (true) {
        xs.pb(val);
        if (val > (r + x - 1) / x) {
            break;
        }
        val *= x;
    }

    vector<ll> ys;
    val = 1;
    while (true) {
        ys.pb(val);
        if (val > (r + y - 1) / y) {
            break;
        }
        val *= y;
    }

    for (ll p : xs) {
        for (ll q : ys) {
            if (p + q >= l && p + q <= r) {
                v.pb(p + q);
            }
        }
    }

    sort(all(v));
    v.pb(r + 1);
    ll prev = l;
    ll ans = 0;

    for (int i = 0; i < sz(v); ++i) {
        ans = max(ans, v[i] - prev);
        prev = v[i] + 1;
    }

    cout << ans << "\n";

}