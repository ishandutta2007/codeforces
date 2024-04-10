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

int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<int> a;
	cin >> n >> k;
	a.resize(n);
	set<int> rems;
	for (int& x : a) {
		cin >> x;
		rems.insert(x % k);
		if (rems.size() > 1) {
			cout << -1;
			return 0;
		}
	}

	int e = *min_element(a.begin(), a.end());
	long long sol = 0;
	for (int x : a) {
		sol += (x-e) / k;
	}
	cout << sol;
}