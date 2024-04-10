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

int n, k, m, c;
int t[50];
int tt[5000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=0; i<k; i++) {
		cin >> t[i];
	}

	// resavamo x celih zadataka
	int sol = 0;
	int suma = accumulate(t, t+k, 0);
	for (int x=0; x<=n; x++) {
		if (x * suma > m) {
			continue;
		}
		int curr = (k+1) * x;
		int mm = m - x * suma;

		vector<int> data;
		for (int i=0; i<n-x; i++) {
			for (int j=0; j<k; j++) {
				data.push_back(t[j]);
			}
		}
		sort(data.begin(), data.end());
		auto it = data.begin();
		while (it != data.end()) {
			if (*it <= mm) {
				mm -= *it;
				curr++;
				++it;
			} else {
				break;
			}
		}
		sol = max(sol, curr);
	}
	cout << sol;
}