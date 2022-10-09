#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int a[1000005];
int n, sum, sum3, root;

vector<int> e[1000005];

int l[1000005], r[1000005], t;
int z[1000005];

vector<int> shine1, shine2;

int dfs(int x) {
	l[x] = ++t;

	int w = a[x];
	for (int y : e[x]) {
		w += dfs(y);
	}

	if (w == sum3 && x != root) {
		shine1.push_back(x);
		z[l[x]] = 1;
	}
	if (w == sum3+sum3 && x != root) {
		shine2.push_back(x);
	}
	r[x] = t;

	return w;
}

bool cmp(int x, int y) {
	return l[x] < l[y];
}

int inv(int x) {
	for (int i=1; i<=n; i++) {
		if (l[i] == x) {
			return i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int p, b;
		cin >> p >> b;
		if (p) {
			e[p].push_back(i);
		} else {
			root = i;
		}
		a[i] = b;
	}

	sum = accumulate(a+1, a+n+1, 0);
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	sum3 = sum / 3;

	dfs(root);

	// pogledaj skup intervala za shine1. Ako nadjes dva koja se ne seku
	// oni su resenje

	if (shine1.size() > 1) {
		int minr=1e9, minri, maxl=-1e9, maxli;

		for (int x : shine1) {
			if (l[x] > maxl) {
				maxl = l[x];
				maxli = x;
			}
			if (r[x] < minr) {
				minr = r[x];
				minri = x;
			}
		}

		if (minr < maxl) {
			cout << minri << ' ' << maxli;
			return 0;
		}
	}

	if (shine2.size() > 0) {
		// pogledaj da li neki shine1 se nalazi u nekom shine2
		for (int i=1; i<=n; i++) {
			z[i] += z[i-1];
		}

		for (int x : shine2) {
			if (z[r[x]] - z[l[x]] > 0) {
				// samo ga nadji
				for (int i=l[x]+1; i<=r[x]; i++) {
					if (z[i] > z[i-1]) {
						cout << inv(i) << ' ' << x;
						return 0;
					}
				}
			}
		}
	}

	cout << -1;
	

}