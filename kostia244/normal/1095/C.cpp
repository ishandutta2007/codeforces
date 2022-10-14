#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	if (k > n) {
		cout << "NO";
		return 0;
	}

	vector<int> a;
	for (; n; n -= n & (-n))
		a.push_back(n & (-n));

	if (a.size() > k) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	int sz = a.size();
	while (sz < k) {
		while(a.back() == 1)
			cout << "1 ", a.pop_back();
		a.back() >>= 1;
		a.push_back(a.back());
		sz++;
	}
	for (auto& i : a)
		cout << i << " ";

	return 0;
}