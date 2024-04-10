#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int& x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	int s = 1e9;
	for (int i=0; i+n-1<m; i++) {
		s = min(s, a[i+n-1] - a[i]);
	}
	cout << s;
}