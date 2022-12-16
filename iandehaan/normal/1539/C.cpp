#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	ll k, x;
	cin >> n >> k >> x;
	ll a[n];
	rep(i, 0, n) cin >> a[i];
	sort(a, a+n);
	int out = n;
	vector<ll> amts;
	rep(i, 0, n-1) {
		if (a[i+1]-a[i] <= x) out--;
		else {
			amts.pb(a[i+1]-a[i]);
		}
	}
	sort(all(amts));
	rep(i, 0, sz(amts)) {
		ll amtneeded = (amts[i]-1) / (x);
		//cout << amts[i] << ' ' << amtneeded << endl;
		if (amtneeded > k) break;
		k -= amtneeded;
		out--;
	}
	cout << out << endl;
}