#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

vector<ll> a;
ll mod;
int n;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void solve(int lf, int rg, vector<ll>& ans) {
    ans.pb(0);
    if (lf > rg) {
        return;
    }
    int k = rg - lf + 1;
    for (int mask = 0; mask < (1 << k); ++mask) {
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            if (bit(mask, i)) {
                sum += a[i + lf];
            }
        }
        ans.pb(sum % mod);
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> mod;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> u, v;
    int a = n / 2;
    solve(0, a, u);
    solve(a + 1, n - 1, v);

    ll ans = 0;
    for (int i = 0; i < sz(u); ++i) {
        ll x = u[i];
        ll y = mod - 1 - x;
        int pos = lower_bound(all(v), y) - v.begin();
        if (pos == sz(v) || v[pos] > y) {
            --pos;
        }
        assert(pos == -1 || v[pos] <= y);
        if (pos != -1) {
            ans = max(ans, x + v[pos]);
        }
        y = mod - x;
        pos = lower_bound(all(v), y) - v.begin();
        if (pos != sz(v)) {
            ans = max(ans, x + v[pos] - mod);
        }
    }

    cout << ans << "\n";

}