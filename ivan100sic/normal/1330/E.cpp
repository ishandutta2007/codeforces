// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
void povuci(T& a, T& p, int t) {
	if (a[2*t] == 0 && a[2*t+1] == 0) {
		a[t] = 0;
		return;
	}

	if (a[2*t] > a[2*t+1]) {
		a[t] = a[2*t];
		p[a[t]] = t;
		povuci(a, p, 2*t);
	} else {
		a[t] = a[2*t+1];
		p[a[t]] = t;
		povuci(a, p, 2*t+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int h, g;
		cin >> h >> g;
		int n = (1 << h) - 1;
		int m = (1 << g) - 1;
		vector<int> a(2*n+5), b(n), p(n+1), sol;
		for (int i=1; i<=n; i++)
			cin >> a[i], b[i-1] = a[i];
		sort(begin(b), end(b));
		for (int i=1; i<=n; i++)
			a[i] = lower_bound(begin(b), end(b), a[i]) - begin(b) + 1;
		for (int i=1; i<=n; i++)
			p[a[i]] = i;

		for (int x=n; x>=1; x--) {
			// probaj da obrises x
			int t = p[x];
			while (a[t] > 0) {
				if (a[2*t] > a[2*t+1])
					t = 2*t;
				else
					t = 2*t+1;
			}

			if (t/2 <= m)
				continue;

			sol.push_back(p[x]);
			povuci(a, p, p[x]);
		}

		ll z = 0;
		for (int i=1; i<=m; i++)
			z += b[a[i] - 1];
		cout << z << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}
}

// I will still practice daily...