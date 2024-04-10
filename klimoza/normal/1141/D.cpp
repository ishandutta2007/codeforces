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
ll mod = 1e9 + 7;
long double eps = 1e-8;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string st1, st2;
	cin >> st1 >> st2;
	vector<vector<int>> cnt1(27), cnt2(27);
	for (int i = 0; i < n; i++) {
		if (st1[i] == '?') cnt1[26].push_back(i + 1);
		else cnt1[st1[i] - 'a'].push_back(i + 1);
		if (st2[i] == '?') cnt2[26].push_back(i + 1);
		else cnt2[st2[i] - 'a'].push_back(i + 1);
	}
	int f = 0;
	vector<pair<int, int>> ans;
	for (int i = 0; i < 26; i++) {
		f = min(cnt1[i].size(), cnt2[i].size());
		for (int j = 0; j < f; j++) {
			ans.push_back({ cnt1[i][cnt1[i].size() - 1], cnt2[i][cnt2[i].size() - 1] });
			cnt1[i].pop_back(); cnt2[i].pop_back();
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt1[26].empty()) break;
		while (cnt2[i].size() && cnt1[26].size()) {
			ans.push_back({ cnt1[26][cnt1[26].size() - 1], cnt2[i][cnt2[i].size() - 1] });
			cnt1[26].pop_back(); cnt2[i].pop_back();
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt2[26].empty()) break;
		while (cnt1[i].size() && cnt2[26].size()) {
			ans.push_back({ cnt1[i][cnt1[i].size() - 1], cnt2[26][cnt2[26].size() - 1] });
			cnt1[i].pop_back(); cnt2[26].pop_back();
		}
	}
	while (!cnt1[26].empty() && !cnt2[26].empty()) {
		ans.push_back({ cnt1[26][cnt1[26].size() - 1], cnt2[26][cnt2[26].size() - 1] });
		cnt1[26].pop_back();
		cnt2[26].pop_back();
	}
	cout << ans.size() << endl;
	for (auto u : ans) cout << u.first << " " << u.second << endl;
	return 0;
}