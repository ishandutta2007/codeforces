#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct covek {
	int x, y;
	bool operator< (const covek& o) const {
		return y < o.y;
	}
};

int c[100005];
int n, k;
covek a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i].x;
	for (int i=0; i<n; i++)
		cin >> a[i].y;

	for (int i=0; i<n; i++)
		c[a[i].x]++;

	int z = 0;
	for (int i=1; i<=k; i++)
		if (c[i] == 0)
			z++;

	sort(a, a+n);
	ll sol = 0;
	for (int i=0; i<n; i++) {
		if (c[a[i].x] > 1 && z > 0) {
			z--;
			c[a[i].x]--;
			sol += a[i].y;
		}
	}

	cout << sol << '\n';
}