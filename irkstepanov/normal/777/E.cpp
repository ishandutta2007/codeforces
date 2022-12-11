#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int N;

vector<ll> t;

ll get(int l, int r)
{
    ll ans = 0;
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans = max(ans, t[l]);
        }
        if (!(r & 1)) {
            ans = max(ans, t[r]);
        }
    }
    return ans;
}

void update(int pos, ll val)
{
    for (pos += N; pos; pos >>= 1) {
        t[pos] = max(t[pos], val);
    }
}

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");
    //ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    map<ll, pll> mapa;
    for (int i = 0; i < n; ++i) {
        ll a, b, h;
        cin >> a >> b >> h;
        if (mapa.count(b)) {
            pll p = mapa[b];
            p.first = min(p.first, a);
            p.second += h;
            mapa[b] = p;
        } else {
            mapa[b] = {a, h};
        }
    }

    vector<ll> sorted;
    for (auto it : mapa) {
        sorted.pb(it.second.first);
        sorted.pb(it.first - 1);
    }
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());
    N = sz(sorted);

    vector<ll> a, b, h;
    for (auto it : mapa) {
        b.pb(it.first);
        a.pb(it.second.first);
        h.pb(it.second.second);
    }
    reverse(all(a));
    reverse(all(b));
    reverse(all(h));

    t.assign(2 * N, 0);
    for (int i = 0; i < sz(a); ++i) {
        int pos = lower_bound(all(sorted), b[i] - 1) - sorted.begin();
        ll x = get(0, pos);
        //cout << b << " " << x << " " << h << "\n";
        update(lower_bound(all(sorted), a[i]) - sorted.begin(), x + h[i]);
    }

    cout << get(0, N - 1) << "\n";

}