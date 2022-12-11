#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int nmax = 100;

int main()
{

	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll x;
	cin >> x;

	int cnt = 0;
	vector<ll> p;

	for (ll d = 2; d * d <= x; ++d) {
		while (x % d == 0) {
			++cnt;
			x /= d;
			p.pb(d);
		}
	}

	if (x != 1) {
		++cnt;
		p.pb(x);
	}

	if (cnt == 2) {
		cout << "2\n";
	} else {
		cout << "1\n";
		if (cnt <= 1) {
			cout << "0\n";
		} else {
			cout << p[0] * p[1] << "\n";
		}
	}

}