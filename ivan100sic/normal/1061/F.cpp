#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<vector<int>, bool> kes;

bool ask(int x, int y, int z) {
	if (x > z)
		swap(x, z);
	if (x == z)
		return y == x;
	if (y == x || y == z)
		return true;
	if (kes.count({x, y, z}))
		return kes[{x, y, z}];
	cout << "? " << x << ' ' << y << ' ' << z << '\n' << flush;
	string s;
	cin >> s;
	return kes[{x, y, z}] = (s == "Yes");
}

void ans(int x) {
	cout << "! " << x << '\n' << flush;
	exit(0);
}

int n, k;

basic_string<int> between(int x, int y) {
	basic_string<int> r;
	for (int i=1; i<=n; i++)
		if (i != x && i != y)
			if (ask(x, i, y))
				r += i;
	return r;
}

bool not_roots[2222];

void test_root(int x) {
	if (not_roots[x])
		return;

	int y = 1;
	if (x == 1)
		y = 2;
	// dovedi y do x
	for (int i=1; i<=n; i++)
		if (ask(x, i, y) && i != x && i != y)
			y = i;
	// pitaj velicine
	int z = 0;
	for (int i=1; i<=n; i++)
		if (ask(x, y, i))
			z++;

	if (z == (n-1) / k) {
		ans(x);
	} else {
		not_roots[x] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	int d = 0, m = 1;
	while (m < n) {
		m = k*m + 1;
		d++;
	}

	int listovi = 2*d - 1;

	cerr << "listovi: " << listovi << '\n';

	srand(hash<string>()("JEBITE SE"));

	while (1) {
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		auto v = between(x, y);
		if ((int)v.size() != listovi)
			continue;
		for (int z : v)
			test_root(z);
	}
}