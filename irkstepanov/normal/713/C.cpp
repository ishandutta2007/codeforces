#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll inf = 1e18;

struct line
{
    ll xl, xr, y0, dy;
    line() {}
    line(ll xl, ll xr, ll y0, ll dy) : xl(xl), xr(xr), y0(y0), dy(dy) {}
};

void add(const line& l, ll minn, ll x, vector<line>& res)
{
    if (l.xl == l.xr) {
        return;
    }
    ll lf = min(minn, l.y0) + abs(x - l.xl);
    ll rg = min(minn, l.y0 + l.dy * (l.xr - l.xl)) + abs(x - l.xr);
    line ans;
    ans.xl = l.xl;
    ans.xr = l.xr;
    ans.y0 = lf;
    assert((rg - lf) % (ans.xr - ans.xl) == 0);
    ans.dy = (rg - lf) / (ans.xr - ans.xl);
    res.pb(ans);
}

void upd(ll& minn, const line& l)
{
    minn = min(minn, min(l.y0, l.y0 + l.dy * (l.xr - l.xl)));
}

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("wa9.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }

    vector<line> dp;
    dp.pb({ll(-1e9), ll(1e9), 0, 0});

    for (int i = 1; i <= n; ++i) {
        vector<line> dp_new;
        ll minn = inf;
        ll x = a[i];
        for (line& l : dp) {
            if (x <= l.xl || x >= l.xr) {
                add(l, minn, x, dp_new);
                upd(minn, l);
            } else {
                line lf = l;
                lf.xr = x;
                add(lf, minn, x, dp_new);
                upd(minn, lf);
                line rg = l;
                rg.xl = x;
                rg.y0 += rg.dy * (x - l.xl);
                add(rg, minn, x, dp_new);
                upd(minn, rg);
            }
        }
        dp.swap(dp_new);
        /*cout << i << ":\n";
        for (line& l : dp) {
            cout << l.xl << " " << l.xr << " " << l.y0 << " " << l.dy << "\n";
        }*/
    }

    ll ans = inf;
    for (line& l : dp) {
        ans = min(ans, min(l.y0, l.y0 + l.dy * (l.xr - l.xl)));
    }
    cout << ans << '\n';

}