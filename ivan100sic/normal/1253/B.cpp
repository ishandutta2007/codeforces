#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, c = 0;
	cin >> n;
	vector<int> sol;
	set<int> s, w;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c++;
		if (x > 0) {
			if (s.count(x))
				no();
			if (w.count(x))
				no();
			s.insert(x);
		} else {
			x = -x;
			if (!s.count(x))
				no();
			s.erase(x);
			w.insert(x);
		}
		if (s.size() == 0) {
			w = {};
			sol.push_back(c);
			c = 0;
		}
	}

	if (s.size())
		no();

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}