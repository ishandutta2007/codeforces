#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	map<string, int> a;
	set<string> check;
	vector<string> list;
	int n;
	cin >> n;
	vector<pair<string, int>> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i].first >> d[i].second;
		if (check.find(d[i].first) == check.end()) {
			list.push_back(d[i].first);
		}
		check.insert(d[i].first);
		a[d[i].first] += d[i].second;
	}
	set<string> ans;
	int maxi = -10001;
	for (string man : list) {
		maxi = max(maxi, a[man]);
	}
	for (string man : list) {
		if (a[man] == maxi) ans.insert(man);
	}
	a.clear();
	string winner = "";
	for (int i = 0; i < n; i++) {
		a[d[i].first] += d[i].second;
		if (a[d[i].first] >= maxi && ans.find(d[i].first) != ans.end()) {
			winner = d[i].first;
			break;
		}
	}
	cout << winner << "\n";
	//system("pause");
	return 0;
}