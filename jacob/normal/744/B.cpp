#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> res(n, INT_MAX);
	for (int i = 0; i < 10; ++i) {
		vector<int> q1, q2;
		for (int j = 1; j <= n; ++j) {
			if (j & (1<<i)) {
				q1.push_back(j);
			} else {
				q2.push_back(j);
			}
		}
		vector<int> v1(n, INT_MAX);
		if (q1.empty()) {
			break;
		}
		if (!q1.empty()) {
			cout << q1.size() << endl;
			for (vector<int>::const_iterator it = q1.begin(); it != q1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			for (int i = 0; i < n; ++i)
				cin >> v1[i];
		}
		vector<int> v2(n, INT_MAX);
		if (!q2.empty()) {
			cout << q2.size() << endl;
			for (vector<int>::const_iterator it = q2.begin(); it != q2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			for (int i = 0; i < n; ++i)
				cin >> v2[i];
		}
		for (int j = 1; j <= n; ++j) {
			if (binary_search(q1.begin(), q1.end(), j)) {
				res[j - 1] = min(res[j - 1], v2[j-1]);
			} else {
				res[j - 1] = min(res[j - 1], v1[j-1]);
			}
		}
	}
	cout << -1 << endl;
	for (int i = 0; i < n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}