// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct ax {
	int q, w;

	template<class T>
	auto operator< (const T& b) const {
		return w > b.w;
	}

} a[100005];
int n, m;

ll f(ll x) {
	if (x % 2) {
		return x*(x-1) / 2 + 1;
	} else {
		return x*x / 2;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// for (int i=1; i<=6; i++)
	// 	cerr << i << " -> " << f(i) << '\n';

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> a[i].q >> a[i].w;
	}

	sort(a, a+m);

	int y = 1;
	for (int x=1; x<=n; x++) {
		if (f(x) <= n) {
			y = x;
		}
	}

	y = min(y, m);
	ll z = 0;
	for (int i=0; i<y; i++)
		z += a[i].w;
	cout << z << '\n';
}