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

int n;
vector<int> a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		a[i].resize(5);
		for (int j=0; j<5; j++) {
			cin >> a[i][j];
		}
	}

	if (n > 100) {
		cout << 0;
		return 0;
	}

	vector<int> sol;

	for (int i=1; i<=n; i++) {
		bool good = true;
		for (int j=1; j<=n; j++) if (j != i) {
			for (int k=1; k<=n; k++) if (k != j && k != i) {
				int sp = 0;
				for (int l=0; l<5; l++) {
					sp += (a[i][l] - a[j][l]) * (a[i][l] - a[k][l]);
				}
				if (sp > 0) {
					good = false;
				}
			}
		}
		if (good) {
			sol.push_back(i);
		}
	}

	cout << sol.size() << '\n';
	for (int x : sol) { 
		cout << x << '\n';
	}
}