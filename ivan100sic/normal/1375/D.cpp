// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct dynmex {
	int n;
	vector<int> c;
	set<int> fali;

	dynmex(int n) : n(n), c(n+1, 0) {
		for (int i=0; i<=n; i++)
			fali.insert(i);
	}

	void add(int x) {
		if (++c[x] == 1) {
			fali.erase(x);
		}
	}

	void rem(int x) {
		if (--c[x] == 0) {
			fali.insert(x);
		}
	}

	int operator() () {
		return *fali.begin();
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;

		dynmex dx(n);
		for (int x : a)
			dx.add(x);

		vector<int> sol;

		auto repl = [&](int i, int v) {
			// cerr << "repl " << i << ' ' << v << '\n';
			dx.rem(a[i]);
			a[i] = v;
			dx.add(a[i]);
			sol.push_back(i);
		};

		int k = n;
		for (int i=0; i<2*n && k; i++) {
			int v = dx();
			if (v == k) {
				repl(--k, v);
			} else {
				repl(v, v);
			}
		}

		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x+1 << ' ';
		cout << '\n';

		// for (int x : a) {
		// 	cerr << x << ' ';
		// }
		// cerr << "\n\n";
	}
}