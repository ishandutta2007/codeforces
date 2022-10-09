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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;

	for (int i=30; i>=0; i--) {
		vector<int> b;
		for (int x : a)
			if (x & (1 << i))
				b.push_back(x);
		if (b.size() > 0) {
			int z = 0xffffffff;
			for (int x : b)
				z &= x;
			if ((z & -z) == (1 << i)) {
				cout << b.size() << '\n';
				for (int x : b)
					cout << x << ' ';
				cout << '\n';
				return 0;
			}
		}
	}
	cout << -1;
}