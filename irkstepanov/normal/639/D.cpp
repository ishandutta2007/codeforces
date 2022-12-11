#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll inf = 1e18;

int f(ll val)
{
    int x = val % 5;
    if (x < 0) {
        x += 5;
    }
    return x;
}

int main()
{

    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    ll t5, t1;
    cin >> t5 >> t1;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    ll ans = inf;

    if (5 * t1 <= t5) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (i >= k) {
                sum -= a[i - k];
            }
            if (i >= k - 1) {
                ans = min(ans, a[i] * (ll)(k) - sum);
            }
        }
        cout << ans << "\n";
        return 0;
    }

    for (int mod = 0; mod < 5; ++mod) {
        map<ll, int> m;
        int s = 0;
        ll delta = 0;
        ll prev = -inf;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            for (ll val = a[i]; val < a[i] + 5; ++val) {
                if (f(val) == mod) {
                    if (prev != -inf) {
                        delta += t5 * (val - prev) / 5;
                    }
                    ll x = t1 * (val - a[i]);
                    map<ll, int>::iterator it = m.begin();
                    if (s == k && -it->first + delta > x) {
                        --m[it->first];
                        --s;
                        sum += it->first;
                        if (!m[it->first]) {
                            m.erase(m.begin());
                        }
                        ++m[delta - x];
                        sum += x - delta;
                        ++s;
                    } else if (s < k) {
                        ++m[delta - x];
                        sum += x - delta;
                        ++s;
                    }
                    if (s == k) {
                        ans = min(ans, sum + delta * (ll)(k));
                    }
                    prev = val;
                }
            }
        }
    }

    cout << ans << "\n";

}