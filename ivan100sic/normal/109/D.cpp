#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];
map<int, set<int>> ainv;
int ind_lucky, any_lucky;
basic_string<pair<int, int>> sol;

bool lucky(int x) {
	while (x > 0) {
		int y = x % 10;
		if (y != 4 && y != 7)
			return false;
		x /= 10;
	}
	return true;
}

void zameni(int i, int j) {
	if (i == j)
		return;

	if (!lucky(a[i]) && !lucky(a[j])) {
		cerr << "red flag " << i << ' ' << j << "(" << sol.size() << ")\n";
	}

	sol += {i, j};
	ainv[a[i]].erase(i);
	ainv[a[j]].erase(j);
	ainv[a[i]].insert(j);
	ainv[a[j]].insert(i);
	swap(a[i], a[j]);

	if (i == any_lucky || j == any_lucky)
		any_lucky ^= i ^ j;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ainv[a[i]].insert(i);
	}

	copy(a+1, a+n+1, b+1);
	sort(b+1, b+n+1);

	for (int i=1; i<=n; i++)
		if (lucky(a[i])) {
			any_lucky = i;
			break;
		}

	if (any_lucky == 0) {
		// bolje bi ti bilo da si sortiran!
		if (equal(a+1, a+n+1, b+1)) {
			cout << "0\n";
		} else {
			cout << "-1\n";
		}
		return 0;
	}

	// {
	// 	basic_string<int> plus, minus;
	// 	for (int i=1; i<=n; i++) {
	// 		if (lucky(a[i]) && !lucky(b[i])) {
	// 			plus += i;
	// 		} else if (!lucky(a[i]) && lucky(b[i])) {
	// 			minus += i;
	// 		}
	// 	}

	// 	for (int j=0; j<(int)plus.size(); j++) {
	// 		int x = plus[j];
	// 		int y = minus[j];
	// 		zameni(x, y);
	// 	}
	// }

	// for (int i=1; i<=n; i++)
	// 	cerr << a[i] << ' ';
	// cerr << '\n';
	// for (int i=1; i<=n; i++)
	// 	cerr << b[i] << ' ';
	// cerr << '\n';

	// cerr << "done 1/3\n";

	// sredi unlucky
	for (int pass=0; pass<100; pass++) {
		for (int i=1; i<=n; i++) {
			if (a[i] == b[i])
				continue;
			if (!lucky(b[i])) {
				int j = *ainv[b[i]].rbegin();
				int k = any_lucky;
				zameni(i, k);
				zameni(i, j);

				// cerr << "zamena " << i << ' ' << j << ' ' << k << '\n';
				// for (int x=1; x<=n; x++)
				// 	cerr << a[x] << ' ';
				// cerr << '\n';
			} else {
				int j = *ainv[b[i]].rbegin();
				zameni(i, j);

				// cerr << "ez " << i << ' ' << j << '\n';
				// for (int x=1; x<=n; x++)
				// 	cerr << a[x] << ' ';
				// cerr << '\n';
			}
		}
	}
		

	// for (int i=1; i<=n; i++)
	// 	cerr << a[i] << ' ';
	// cerr << '\n';
	// for (int i=1; i<=n; i++)
	// 	cerr << b[i] << ' ';
	// cerr << '\n';

	// cerr << "done 2/3\n";

	// // sredi lucky
	// for (int i=1; i<=n; i++) {
	// 	if (a[i] == b[i])
	// 		continue;
	// 	int j = *ainv[b[i]].begin();
	// 	zameni(i, j);
	// }

	if (!equal(a+1, a+n+1, b+1)) {
		cerr << "red flag! arrays not equal\n";
	}

	cout << sol.size() << '\n';
	for (auto [p, q] : sol)
		cout << p << ' ' << q << '\n';

}