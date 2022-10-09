// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct node {
	int c, t, id;

	template<class T>
	auto operator< (const T& b) const {
		return t > b.t;
	}
};

ll n;
node a[200005];

map<int, int> fr;

int nadji(int x) {
	if (!fr.count(x)) {
		fr[x] = x;
		return x;
	} else {
		x = fr[x];
		return fr[x] = nadji(x+1);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i].c;
	for (int i=0; i<n; i++) cin >> a[i].t, a[i].id = i;

	sort(a, a+n);

	ll sol = 0;

	for (int i=0; i<n; i++) {
		int p = nadji(a[i].c);
		fr[a[i].c] = p;
		sol += (p - a[i].c) * 1ll * a[i].t;
	}

	cout << sol << "\n";
}