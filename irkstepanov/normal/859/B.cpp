#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll n;
    cin >> n;

    ll ans = 1e18;

    for (ll len = 1; len <= n; ++len) {
        ll full = n / len;
        ll rem = n % len;
        if (rem == 0) {
            ans = min(ans, (full + len) * 2);
            continue;
        }
        ans = min(ans, (full + len) * 2 + 2);
    }

    cout << ans << "\n";

}