#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int askgr(int x) {
	cout << "> " << x << '\n' << flush;
	cin >> x;
	return x;
}

int ask(int x) {
	cout << "? " << x << '\n' << flush;
	cin >> x;
	return x;
}

struct rng {
	random_device r;
	mt19937_64 e;

	rng() : r(), e(r()) {}

	int randint(int l, int r) {
		return uniform_int_distribution<int>(l, r)(e);
	}

} r1;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	// nadji o
	int l = 0, r = 1e9, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (askgr(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	o++;

	int g = 0;

	for (int i=0; i<30; i++)
		g = gcd(g, o - ask(r1.randint(1, n)));
	cout << "! " << o-(n-1)*g << ' ' << g << '\n';
}