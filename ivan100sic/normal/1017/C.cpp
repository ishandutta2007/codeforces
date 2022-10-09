#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sq(int x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	int rut = sqrt(n);
	while (sq(rut+1) <= n)
		rut++;
	while (sq(rut) > n)
		rut--;

	if (rut * rut != n)
		rut++;

	int ima = n;
	int x = 0;
	vector<int> a;

	while (ima > 0) {
		int y = min(rut, ima);
		for (int i=1; i<=y; i++)
			a.push_back(x + i);
		reverse(a.end() - y, a.end());
		ima -= y;
		x += y;
	}

	for (int x : a)
		cout << x << ' ';
}