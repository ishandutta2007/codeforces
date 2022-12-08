#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	set<int> p;
	int t;
	for (int i = 0; i < m; i++) {
		cin >> t;
		p.insert(t);
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (p.find(x[i]) != p.end()) {
			ans.push_back(x[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	//system("pause");
	return 0;
}