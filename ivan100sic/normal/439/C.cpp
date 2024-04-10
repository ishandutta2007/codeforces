#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> par, nepar;
int n, k, p;
basic_string<int> sol[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> p;
	p = k-p;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x % 2)
			nepar += x;
		else
			par += x;
	}

	int q = nepar.size();
	if (q < p || (p - q) % 2) {
		cout << "NO\n";
		return 0;
	}

	for (int i=0; i<p; i++)
		sol[i] += nepar[i];

	for (int i=p; i<q; i++)
		sol[(p + (i-p)/2) % k] += nepar[i];

	for (int i=0; i<k; i++) {
		if (sol[i].size() == 0 && par.size()) {
			sol[i] += par.back();
			par.pop_back();
		}
	}

	sol[0] += par;

	for (int i=0; i<k; i++) {
		if (sol[i].size() == 0)
			return cout << "NO\n", 0;
	}

	cout << "YES\n";
	for (int i=0; i<k; i++) {
		cout << sol[i].size() << ' ';
		for (int x : sol[i])
			cout << x << ' ';
		cout << '\n';
	}
}