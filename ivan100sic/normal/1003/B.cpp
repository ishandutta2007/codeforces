#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, x;
	cin >> a >> b >> x;

	list<int> d;
	int j = 1;
	if (a > b)
		j = 0;
	
	for (int i=0; i<=x; i++) {
		int v = (i+j) % 2;
		d.push_back(v);
		if (v == 0)
			a--;
		else
			b--;
	}

	while (a--) {
		auto it = find(d.begin(), d.end(), 0);
		d.insert(it, 0);
	}

	while (b--) {
		auto it = find(d.begin(), d.end(), 1);
		d.insert(it, 1);
	}

	for (int x : d)
		cout << x;

}