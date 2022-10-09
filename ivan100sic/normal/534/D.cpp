#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[200005], sol, modz1[3], modz2[3];
int a[200005], act[3];
int n, rem;

void no() {
	cout << "Impossible\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		e[x] += i;
	}

	sol.resize(n, 1123123123);
	iota(act, act+3, 0);

	for (int j=0; j<n; j++) {
		if (e[j].size()) {
			modz1[j % 3] += e[j].back();
			e[j].pop_back();
		}
	}

	for (int j=0; j<n; j++) {
		while (e[j].size()) {
			modz2[j % 3] += e[j].back();
			e[j].pop_back();
		}
	}

	for (int i=0; i<3; i++) {
		auto modz = modz1[i];
		reverse(modz2[i].begin(), modz2[i].end());
		modz += modz2[i];
		for (int x : modz) {
			if (act[i] >= n)
				no();
			sol[act[i]] = x;
			act[i] += 3;
		}
	}

	// for (int x : sol)
	// 	cerr << a[x] << ' ';
	// cerr << '\n';

	if (a[sol[0]] != 0)
		no();
	for (int i=0; i<(int)sol.size()-1; i++) {
		int r = a[sol[i+1]] - a[sol[i]];
		if (!(r == 1 || r % 3 == -2))
			no();
	}

	cout << "Possible\n";
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}