// MIPT Shock Content (place 19)

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

const ll inf = 1e18;

int n;
ll s;
vector<ll> x, a, b;
vector<pll> vct;
ll k;
ll sum;

ll solve(ll second) {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * x[i];
    }
    if (second == 0) {
        return ans;
    }
    if (second == k) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += b[i] * x[i];
        }
        return ans;
    }
    ll curr = sum - (k - second) * s;
    //cout << sum << " " << s << " " << k << " " << second << " " << curr << "\n";
    int ptr = 0;
    while (curr) {
        if (curr >= vct[ptr].second) {
            ans += vct[ptr].second * vct[ptr].first;
            curr -= vct[ptr].second;
            ++ptr;
            continue;
        } else {
            ans += vct[ptr].first * curr;
            break;
        }
    }
    ll init = sum - (k - second) * s;
    ll rem = second * s - init;
    while (rem && ptr < sz(vct) && vct[ptr].first > 0) {
        ll z = vct[ptr].second;
        if (curr) {
            z -= curr;
            curr = 0;
        }
        if (rem >= z) {
            ans += vct[ptr].first * z;
            rem -= z;
            ++ptr;
        } else {
            ans += vct[ptr].first * rem;
            break;
        }
    }
    return ans;
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> s;

    x.resize(n);
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> a[i] >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        vct.pb({b[i] - a[i], x[i]});
    }
    sort(all(vct));

    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += x[i];
    }
    k = (sum + s - 1) / s;

    ll t = 0;
    for (int i = sz(vct) - 1; i >= 0; --i) {
        if (vct[i].first > 0) {
            t += vct[i].second;
        }
    }

    t /= s;
    reverse(all(vct));

    ll ans = -inf;
    for (ll z = t; z <= k && z <= t + 10; ++z) {
        ans = max(ans, solve(z));
    }

    cout << ans << "\n";

}