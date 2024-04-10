#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const ll inf = 1e16;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	ll k;
	cin >> k;

	ll ans = 0;
	map<ll, int> mapa;
	mapa[0] = 1;
	ll curr = 0;

	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		curr += a;
		for (ll val = 1; val <= inf; val *= k) {
			if (mapa.count(curr - val)) {
				ans += mapa[curr - val];
			}
			if (k == 1) {
				break;
			}
			if (k == -1 && val == -1) {
				break;
			}
		}
		++mapa[curr];
	}

	cout << ans << "\n";

}