#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
	int n;
	cin >> n;
	vector<string> a(2 * n - 2);
	vector<set<string>> f(2);
	vector<set<string>> l(2);
	vector<vector<int>> cnt(n);
	for (int i = 0; i < 2 * n - 2; i++) {
		cin >> a[i];
		cnt[a[i].size()].push_back(i);
		if (a[i].size() == n - 1) {
			string g = "";
			if (f[0].empty()) {
				for (int j = 0; j < n - 1; j++) {
					g += a[i][j];
					f[0].insert(g);
				}
				g = "";
				for (int j = n - 2; j >= 0; j--) {
					g = a[i][j] + g;
					l[1].insert(g);
				}
			}
			else {
				for (int j = 0; j < n - 1; j++) {
					g += a[i][j];
					l[0].insert(g);
				}
				g = "";
				for (int j = n - 2; j >= 0; j--) {
					g = a[i][j] + g;
					f[1].insert(g);
					//cout << g << "      lul\n";
				}
			}
		}
	}
	bool fl1 = true;
	vector<char> ans1(2 * n - 2);
	vector<char> pre1(n, 'N');
	vector<char> pre2(n, 'N');
	vector<char> ans2(2 * n - 2);
	for (int i = 0; i < 2 * n - 2; i++) {
		if (f[0].find(a[i]) != f[0].end()) {
			if(pre1[a[i].size()] == 'N' || pre1[a[i].size()] == 'S')
				ans1[i] = 'P';
			else if (f[1].find(a[cnt[a[i].size()][0]]) != f[1].end()) {
				ans1[i] = 'P';
				ans1[cnt[a[i].size()][0]] = 'S';
			}
			else {
				//cout << "lul " << i << " " << a[cnt[a[i].size()][0]] << endl;
				fl1 = false;
			}
			pre1[a[i].size()] = 'P';
		}
		else if (f[1].find(a[i]) != f[1].end() && (pre1[a[i].size()] == 'N' || pre1[a[i].size()] == 'P')) {
			//cout << i << endl;
			ans1[i] = 'S';
			pre1[a[i].size()] = 'S';
		}
		else {
			fl1 = false;
		}
		if (l[0].find(a[i]) != l[0].end()) {
			if (pre2[a[i].size()] == 'N' || pre2[a[i].size()] == 'S')
				ans2[i] = 'P';
			else if (l[1].find(a[cnt[a[i].size()][0]]) != l[1].end()) {
				ans2[i] = 'P';
				ans2[cnt[a[i].size()][0]] = 'S';
			}
			pre2[a[i].size()] = 'P';
		}
		else if (l[1].find(a[i]) != l[1].end() && (pre2[a[i].size()] == 'N' || pre2[a[i].size()] == 'P')) {
			ans2[i] = 'S';
			pre2[a[i].size()] = 'S';
		}
	}
	if (fl1) {
		for (char c : ans1) cout << c;
	}
	else {
		for (char c : ans2) cout << c;
	}
	//system("pause");
	return 0;
}