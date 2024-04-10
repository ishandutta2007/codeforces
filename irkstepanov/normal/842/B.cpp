#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	ll R, d;
	cin >> R >> d;
	int tt;
	cin >> tt;
	int ans = 0;

	while (tt--) {
		ll x, y, r;
		cin >> x >> y >> r;
		ll dist2 = x * x + y * y;
		bool ok = true;
		if (r + R - d >= 0) {
			if (dist2 < (r + R - d) * (r + R - d)) {
				ok = false;
			}
		}
		if (R - r < 0) {
			ok = false;
		} else {
			if (dist2 > (R - r) * (R - r)) {
				ok = false;
			}
		}
		if (ok) {
			++ans;
		}
	}

	cout << ans << "\n";

}