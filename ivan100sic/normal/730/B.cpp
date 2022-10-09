#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char ask(int i, int j) {
	char x;
	cout << "? " << i << ' ' << j << '\n' << flush;
	cin >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int l, h;
		if (n % 2 == 1) {
			l = h = 1;
		} else {
			l = 1, h = 2;
			if (ask(1, 2) == '>')
				swap(l, h);
		}

		for (int i=3-n%2; i<=n; i+=2) {
			int u = i, v = i+1;
			if (ask(i, i+1) == '>')
				swap(u, v);
			if (ask(u, l) == '<')
				l = u;
			if (ask(v, h) == '>')
				h = v;
		}

		cout << "! " << l << ' ' << h << '\n' << flush;
	}
}