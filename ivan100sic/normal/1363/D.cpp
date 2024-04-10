// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int ask(vector<int> v) {
	if (v.size() == 0)
		return 0;

	cout << "? " << v.size();
	for (int x : v) {
		cout << ' ' << x+1;
	}
	cout << '\n' << flush;
	int x;
	cin >> x;
	return x;
};

void ans(vector<int> v) {
	cout << "!";
	for (int x : v) {
		cout << ' ' << x;
	}
	cout << '\n' << flush;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> cl(n, k);

		for (int i=0; i<k; i++) {
			int c;
			cin >> c;
			for (int j=0; j<c; j++) {
				int x;
				cin >> x;
				// stavi
				cl[x-1] = i;
			}
		}

		auto range = [&](int l, int r) {
			vector<int> a;
			for (int i=0; i<n; i++) {
				if (l <= cl[i] && cl[i] <= r) {
					a.push_back(i);
				}
			}
			return a;
		};

		int allmax = ask(range(0, k));

		int l = 1, r = k-1, o=0, oq=0;
		while (l <= r) {
			int m = (l+r) / 2;
			int res = ask(range(0, m-1));
			if (res == allmax) {
				r = m - 1;
			} else {
				o = m;
				oq = res;
				l = m + 1;
			}
		}

		// sad pitaj za ostatak
		int resto = ask(range(o+1, k));

		int h = max(resto, oq);
		vector<int> sol(k, allmax);
		if (h != allmax) {
			sol[o] = h;
		}
		ans(sol);

		string status;
		cin >> status;
		if (status == "Incorrect")
			return 0;
	}
}