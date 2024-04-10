#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 998244353;



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> fn(n);
	vector<pair<int, int>> fm(m);
	for (int i = 0; i < n; i++) fn[i] = { 0, i };
	for (int i = 0; i < m; i++) fm[i] = { 0, i };
	vector<string> st(n);
	for (int i = 0; i < n; i++) {
		cin >> st[i];
		for (int j = 0; j < m; j++) {
			if (st[i][j] == '<') {
				fm[j].first++;
				fn[i].first--;
			}
			else if (st[i][j] == '>') {
				fn[i].first++;
				fm[j].first--;
			}
		}
	}
	vector<int> ans1(n);
	vector<int> ans2(m);
	int cur = 1;
	int l = 0;
	int r = 0;
	sort(fn.begin(), fn.end());
	sort(fm.begin(), fm.end());
	while (l < n || r < m) {
		//cout << cur << " " << l << " " << r << endl;
		if (l == n) {
			if (r == m - 1) ans2[fm[r].second] = cur;
			else if (fm[r].first == fm[r + 1].first) {
				ans2[fm[r].second] = cur;
			}
			else {
				ans2[fm[r].second] = cur++;
			}
			r++;
			continue;
		}
		if (r == m) {
			if (l == n - 1) ans1[fn[l].second] = cur;
			else if (fn[l].first == fn[l + 1].first) {
				ans1[fn[l].second] = cur;
			}
			else {
				ans1[fn[l].second] = cur++;
			}
			l++;
			continue;
		}
		if (st[fn[l].second][fm[r].second] == '=') {
			ans1[fn[l].second] = ans2[fm[r].second] = cur;
			if (!((l < n - 1 && fn[l + 1].first == fn[l].first) || (r < m - 1 && fm[r + 1].first == fm[r].first))) cur++;
			l++; r++;
			continue;
		}
		if (st[fn[l].second][fm[r].second] == '>') {
			ans2[fm[r].second] = cur;
			//cout << "flex\n";
			if (!(r < m - 1 && fm[r + 1].first == fm[r].first)) cur++;
			r++;
			continue;
		}
		if (st[fn[l].second][fm[r].second] == '<') {
			ans1[fn[l].second] = cur;
			if (!(l < n - 1 && fn[l + 1].first == fn[l].first)) cur++;
			l++;
			continue;
		}
	}
	bool fl = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (st[i][j] == '<' && ans1[i] >= ans2[j]) {
				fl = false;
				break;
			}
			if (st[i][j] == '=' && ans1[i] != ans2[j]) {
				fl = false;
				break;
			}
			if (st[i][j] == '>' && ans1[i] <= ans2[j]) {
				fl = false;
				break;
			}
		}
	}
	if (fl) {
		cout << "Yes\n";
		for (int i : ans1) cout << i << " ";
		cout << endl;
		for (int i : ans2) cout << i << " ";
		cout << endl;
	}
	else {
		cout << "No\n";
	}
	//system("pause");
	return 0;
}