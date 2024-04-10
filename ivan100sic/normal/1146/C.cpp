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

	int t;
	cin >> t;
	while (t--) {
		int n, z=0;
		cin >> n;
		for (int i=0; i<9; i++) {
			basic_string<int> a, b;
			for (int x=1; x<=n; x++) {
				if (x & (1 << i))
					a += x;
				else
					b += x;
			}
			if (a.size() == 0 || b.size() == 0)
				continue;
			cout << a.size() << ' ' << b.size() << ' ';
			for (int x : a)
				cout << x << ' ';
			for (int x : b)
				cout << x << ' ';
			cout << '\n' << flush;
			int r;
			cin >> r;
			z = max(z, r);
		}
		cout << "-1 " << z << '\n' << flush;
	}
}