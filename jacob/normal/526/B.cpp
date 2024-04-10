#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n;

long long dfs(int p, const vector<int>& maxval) {
	if (p >> n) {
		return 0;
	}
	return dfs(p * 2, maxval) + dfs(p * 2 + 1, maxval) + abs(maxval[p * 2 + 1] - maxval[p * 2]);
}

int main(void) {
	
	cin >> n;
	vector<int> a(2 << n);
	for (int i = 2; (i >> (n + 1)) == 0; i++) {
		cin >> a[i];
	}
	vector<int> maxval = a;
	for (int i = (1 << n) - 1; i > 0; --i) {
		maxval[i] = a[i] + max(maxval[i * 2], maxval[i * 2 + 1]);
	}
	cout << dfs(1, maxval) << endl;
}