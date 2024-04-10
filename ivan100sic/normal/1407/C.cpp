// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int ask(int i, int j) {
	cout << "? " << i << ' ' << j << '\n' << flush;
	int x;
	cin >> x;
	return x;
}

int sol[100005], n;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	vector<int> u(n);
	iota(begin(u), end(u), 1);
	while (u.size() >= 2) {
		int x = u.back(); u.pop_back();
		int y = u.back(); u.pop_back();
		int a = ask(x, y);
		int b = ask(y, x);
		if (a > b) {
			swap(a, b);
			swap(x, y);
		}

		// a < b, x % y < y % x, x > y
		sol[y] = b;
		u.push_back(x);
	}

	sol[u[0]] = n*(n+1ll) / 2 - accumulate(sol+1, sol+n+1, 0ll);
	cout << "!";
	for (int i=1; i<=n; i++) {
		cout << ' ' << sol[i];
	}
	cout << '\n';
}