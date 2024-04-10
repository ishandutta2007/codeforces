#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int g[1000000];

struct mexer {
	set<int> alive;
	vector<int> c;

	mexer() {
		c = vector<int>(1000000, 0);
		for (int i=0; i<1000000; i++) {
			alive.insert(i);
		}
	}

	void add(int x) {
		c[x]++;
		if (c[x] == 1)
			alive.erase(x);
	}

	void rem(int x) {
		c[x]--;
		if (c[x] == 0)
			alive.insert(x);
	}

	int get() {
		return *alive.begin();
	}
};

int n;
ll a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


	ll p = 1, q = 0;

	mexer mx;
	for (int i=0; i<1000000; i++) {
		while (q*q <= i && q < i)
			mx.add(g[++q]);
		mx.rem(g[q--]);
		while (p*p*p*p < i)
			mx.rem(g[p++]);
		if (i < 20)
			cerr << i << ' ' << p << ' ' << q << '\n';
		g[i] = mx.get();
	}

	// for (int i=0; i<20; i++)
	// 	cerr << g[i] << " \n"[i == 9];


	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	mx = mexer();
	int z = 0;
	p = 1, q = 0;
	for (int i=0; i<n; i++) {
		while (q*q <= a[i] && q < a[i])
			mx.add(g[++q]);
		mx.rem(g[q--]);
		while (p*p*p*p < a[i])
			mx.rem(g[p++]);
		// cerr << mx.get() << '\n';
		z ^= mx.get();
	}

	cout << (!z ? "Rublo\n" : "Furlo\n");
}