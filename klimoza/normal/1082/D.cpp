#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

typedef long long ll;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> one;
	vector<pair<int, int>> mn;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		if (a[i] == 1) {
			one.push_back(i);
		}
		else if (a[i] >= 2) {
			mn.push_back({ a[i], i });
		}
	}
	int d = 0;
	vector<pair<int, int>> ans;
	if (one.size() == 0) {
		d = n - 1;
		for (int i = 0; i < n - 1; i++) {
			ans.push_back({ i + 1, i + 2 });
		}
	}
	else if (one.size() == 1) {
		d = n - 1;
		bool fl = true;
		if (mn.size() > 0) {
			ans.push_back({ one[0] + 1, mn[0].second + 1 });
			for (int i = 0; i < mn.size() - 1; i++) {
				ans.push_back({ mn[i].second + 1, mn[i + 1].second + 1 });
			}
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	else if (one.size() >= 2) {
		d = 2;
		if (mn.size() == 0) {
			cout << "NO\n";
			return 0;
		}
		ans.push_back({ one[0] + 1, mn[0].second + 1 });
		for (int i = 0; i < mn.size() - 1; i++) {
			ans.push_back({ mn[i].second + 1, mn[i + 1].second + 1 });
			d++;
			mn[i].first -= 2;
		}
		ans.push_back({ mn[mn.size() - 1].second + 1, one[1] + 1});
		mn[mn.size() - 1].first -= 2;
		int r = 0;
		for (int i = 2; i < one.size(); i++) {
			if (r == mn.size()) {
				cout << "NO\n";
				return 0;
			}
			else if(mn[r].first == 0){
				i--;
				r++;
			}
			else {
				mn[r].first--;
				ans.push_back({ mn[r].second + 1, one[i] + 1 });
			}
		}
	}
	cout << "YES " << d << endl;
	cout << ans.size() << " " << endl;
	for (auto t : ans) {
		cout << t.first << " " << t.second << endl;
	}
	//system("pause");
	return 0;
}