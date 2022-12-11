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

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    n *= 2;

    ll ans = inf;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<ll> b;
            for (int k = 0; k < n; ++k) {
                if (i == k || j == k) {
                    continue;
                }
                b.pb(a[k]);
            }
            sort(all(b));
            ll curr = 0;
            for (int i = 0; i < sz(b); i += 2) {
                curr += b[i + 1] - b[i];
            }
            ans = min(ans, curr);
        }
    }

    cout << ans << "\n";

}