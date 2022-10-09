#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[150005];

bool ok(const basic_string<int>& proveri) {
	for (int i : proveri) {
		if (i < 1 || i >= n)
			continue;
		if (i%2) {
			if (a[i] >= a[i+1])
				return false;
		} else {
			if (a[i] <= a[i+1])
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	basic_string<int> probaj, probaj2;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		if (i%2) {
			if (a[i] >= a[i+1]) {
				probaj += i;
				probaj += i+1;
			}
		} else {
			if (a[i] <= a[i+1]) {
				probaj += i;
				probaj += i+1;
			}
		}
	}

	if (probaj.size() > 10) {
		cout << "0\n";
		return 0;
	}

	for (int x : probaj) {
		probaj2 += x-1;
		probaj2 += x;
		probaj2 += x+1;
	}

	sort(probaj2.begin(), probaj2.end());
	probaj2.resize(unique(probaj2.begin(), probaj2.end()) - probaj2.begin());

	set<pair<int, int>> sol;

	for (int i : probaj2) {
		if (i < 1 || i > n)
			continue;
		for (int j=1; j<=n; j++) {
			if (i == j)
				continue;
			auto tmp = probaj2;
			tmp += {i, i-1, j, j-1};
			swap(a[i], a[j]);
			if (ok(tmp)) {
				int ti = i, tj = j;
				if (ti > tj)
					swap(ti, tj);
				sol.insert({ti, tj});
			}
			swap(a[i], a[j]);
		}
	}

	cout << sol.size() << '\n';
}