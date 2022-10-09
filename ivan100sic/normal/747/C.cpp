#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int n, q;
int till[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	while (q--) {
		int t, k, d;
		cin >> t >> k >> d;

		vector<int> good;

		for (int j=1; j<=n; j++) {
			if (till[j] <= t) {
				good.push_back(j);
			}
		}

		if (good.size() >= k) {
			cout << accumulate(good.begin(), good.begin() + k, 0) << '\n';
			for (int i=0; i<k; i++) {
				till[good[i]] = t + d;
			}
		} else {
			cout << "-1\n";
		}
	}

}