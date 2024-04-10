#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	a.resize(2*n);
	for (int i=0; i<2*n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int sol = 1e9;

	for (int i=0; i<2*n; i++) {
		for (int j=i+1; j<2*n; j++) {
			vector<int> b;
			for (int k=0; k<2*n; k++) {
				if (k == i || k == j) {
					continue;
				} else {
					b.push_back(a[k]);
				}
			}

			int ins = 0;
			for (int k=0; k<2*n-2; k+=2) {
				ins += b[k+1] - b[k];
			}

			sol = min(sol, ins);
		}
	}

	cout << sol;
}