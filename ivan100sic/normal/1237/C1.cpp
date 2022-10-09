#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int s(vector<int> a, vector<int> b) {
	int i = 0;
	while (a[i] == b[i])
		i++;
	return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a, c(n, vector<int>(4));
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++)
			cin >> c[i][j];
		c[i][3] = i+1;
	}
	sort(c.begin(), c.end());

	for (int j=2; j>=0; j--) {
		for (auto b : c) {
			if (a.size() && s(a.back(), b) == j) {
				cout << a.back()[3] << ' ' << b[3] << '\n';
				a.pop_back();
			} else {
				a.push_back(b);
			}
		}
		c = a;
		a = {};
	}
}