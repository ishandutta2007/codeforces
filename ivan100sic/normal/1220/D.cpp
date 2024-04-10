#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[200005];
vector<ll> c[62];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		ll z = 1, y=0;
		while (!(z & x))
			z <<= 1, y++;
		c[y].push_back(x);
	}
	int i = 0;
	for (int j=0; j<62; j++)
		if (c[j].size() > c[i].size())
			i = j;
	cout << n - c[i].size() << '\n';
	for (int j=0; j<62; j++) {
		if (j != i) {
			for (ll x : c[j])
				cout << x << ' ';
		}
	}
}