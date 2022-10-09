#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], b[200005];

struct rac {
	ll p, q;
	rac (ll a, ll b) : p(a), q(b) {
		if (q < 0) {
			p = -p;
			q = -q;
		}	
	}
	bool operator< (const rac& b) const {
		return p*b.q < q*b.p;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	int z = 0;
	map<rac, int> mp;

	for (int i=0; i<n; i++) {
		if (a[i] == 0 && b[i] == 0) {
			z++;
		} else if (a[i] == 0 && b[i] != 0) {
			//
		} else {
			mp[rac(b[i], a[i])]++;
		}
	}

	int y = 0;
	for (auto p : mp)
		y = max(y, p.second);

	cout << z+y << '\n';
}