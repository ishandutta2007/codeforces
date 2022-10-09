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

const int MOD = 1'000'000'007;

int n;
int a[200005];
int root[200005];

bool instack[200005];

vector<int> e[200005];

set<int> done;

int find_root(int x) {
	if (instack[x]) {
		return root[x] = -x;
	}

	if (root[x]) {
		return root[x];
	}

	instack[x] = true;	

	if (a[x] == 0) {
		root[x] = x;
	} else {
		root[x] = find_root(a[x]);
	}

	instack[x] = false;

	return root[x];
}

int solve(int root) {
	int sol = 1;
	for (int y : e[root]) {
		sol = (sol + solve(y)) % MOD;
	}
	return sol;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		a[x] = y;
		e[y].push_back(x);

		if (x == y) {
			root[x] = -MOD-x;
		}
	}

	for (int i=1; i<=2*n; i++) {
		find_root(i);
	}

	int sol = 1;

	for (int i=1; i<=2*n; i++) {
		if (!done.count(root[i])) {
			if (root[i] < 0) {
				if (root[i] > -MOD) {
					sol = 2ll * sol % MOD;
				}
			} else {
				sol = sol * 1ll * solve(root[i]) % MOD;
			}
			done.insert(root[i]);
		}
	}

	cout << sol;


}