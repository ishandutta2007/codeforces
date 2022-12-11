#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int buben = 3;
const ll inf = 1e18;

ll c3, c5;

vector<ll> minn;

ll get(ll r) // r + c3 * x is divisible by c5
{
	r %= c5;
	r = c5 - r;
	r %= c5;
	return minn[r];
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/

	int n;
	ll sum;
	cin >> n >> sum;

	ll c4 = 0;
	while (n--) {
		int m;
		cin >> m;
		if (m == 3) {
			++c3;
		} else if (m == 4) {
			++c4;
		} else {
			++c5;
		}
	}

	minn.assign(c5, inf);
	for (ll x = 0; x < c5; ++x) {
		minn[(c3 * x) % c5] = min(minn[(c3 * x) % c5], x);
	}

	ll bestAns = inf;
	ll bestK3, bestK4, bestK5;
	ll g = __gcd(c3, c5);

	for (ll k4 = 0; 2 * k4 <= sum; ++k4) {
		ll s = sum - c4 * k4;
		ll c = c4 * k4;
		vector<ll> x0;
		vector<ll> v;
		x0.pb(0);
		x0.pb((s - k4 * c5) / c3);
		x0.pb(c / c3);
		x0.pb((s - c) / c3);
		x0.pb(s / (2 * c3));
		x0.pb(k4);
		for (int i = 0; i < sz(x0); ++i) {
			ll y = -get(s - c3 * x0[i]) + x0[i];
			for (int op = -buben; op <= buben; ++op) {
				ll x = y + ll(op) * c5 / g;
				//cout << "!" << y << " " << x0[i] << " " << x << "\n";
				if (x >= 0 && x <= k4) {
					ll k5 = (s - c3 * x) / c5;
					if (k5 >= k4) {
						v.pb(x);
					}
				}
			}
		}
		for (ll x : v) {
			//cout << x << "\n";
			/*if ((s - c3 * x) % c5) {
				cout << c3 << " " << c4 << " " << c5 << " " << k4 << " " << x << "\n";
				return 0;
			}*/
			assert((s - c3 * x) % c5 == 0);
			ll k5 = (s - c3 * x) / c5;
			ll ans = abs(c3 * x - c) + abs(c5 * k5 - c);
			if (ans < bestAns) {
				bestAns = ans;
				bestK3 = x;
				bestK4 = k4;
				bestK5 = k5;
			}
		}
	}

	//cout << c3 << " " << c4 << " " << c5 << "\n";

	if (bestAns == inf) {
		cout << "-1\n";
	} else {
		cout << bestK3 << " " << bestK4 << " " << bestK5 << "\n";
		//cout << bestAns << "\n";
	}

}