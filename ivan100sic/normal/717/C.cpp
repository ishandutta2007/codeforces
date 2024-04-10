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

const int MOD = 10007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, sol=0;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	for (int i=0; i<n; i++) {
		int j = n-i-1;
		sol = (sol + 1ll * a[i] * a[j]) % MOD;
	}
	cout << sol;
}