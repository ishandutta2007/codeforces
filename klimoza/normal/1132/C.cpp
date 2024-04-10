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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> t(q);
	vector<int> cnt(n);
	vector<pair<int, int>> f;
	for (int i = 0; i < q; i++) {
		cin >> t[i].first >> t[i].second;
		t[i].first--; t[i].second--;
		f.push_back({ t[i].second + 1, -1 });
		f.push_back({ t[i].first, 1 });
	}
	sort(f.begin(), f.end());
	int cur = 0;
	for (int i = 0; i < f.size() - 1; i++) {
		if (f[i].second == -1) {
			cur--;
		}
		else {
			cur++;
		}
		for (int j = f[i].first; j < f[i + 1].first; j++) cnt[j] = cur;
	}
	sort(t.begin(), t.end());
	vector<int> pref1(n);
	vector<int> pref2(n);
	if (cnt[0] == 1) pref1[0] = 1;
	else if (cnt[0] == 2) pref2[0] = 1;
	int tot = min(cnt[0], 1);
	for (int i = 1; i < n; i++) {
		pref1[i] = pref1[i - 1];
		pref2[i] = pref2[i - 1];
		if (cnt[i] == 1) pref1[i]++;
		else if (cnt[i] == 2) pref2[i]++;
		//cout << pref1[i] << " " << i << " " << pref2[i] << " " << cnt[i] << " ----- \n";
		tot += min(cnt[i], 1);
	}
	int maxi = 0;
	//cout << tot << endl;
	for (int i = 0; i < q; i++) {
		for (int j = i + 1; j < q; j++) {
			pair<int, int> t1;
			pair<int, int> t2;
			pair<int, int> t3;
			if (t[i].second >= t[j].second) {
				t1 = { t[i].first, t[j].first - 1 };
				t2 = { t[j].first, t[j].second };
				t3 = { t[j].second + 1, t[i].second };
			}
			else if (t[i].second >= t[j].first) {
				t1 = { t[i].first, t[j].first - 1 };
				t2 = { t[j].first, t[i].second };
				t3 = { t[i].second + 1, t[j].second };
			}
			else {
				t1 = t[i];
				t3 = t[j];
				t2 = { -1, -1 };
			}
			int c = tot;
			if (t1.first <= t1.second) {
				c -= pref1[t1.second];
				if (t1.first > 0) c += pref1[t1.first - 1];
			}
			if (t2.first != -1) {
				c -= pref2[t2.second];
				if (t2.first > 0) c += pref2[t2.first - 1];
			}
			if (t3.first <= t3.second) {
				c -= pref1[t3.second];
				if (t3.first > 0) c += pref1[t3.first - 1];
			}
			//cout << i << " " << j << " " << t1.first << " " << t1.second << " " << t3.first << " " << t3.second << " " << c << endl;
			maxi = max(maxi, c);
		}
	}
	cout << maxi << endl;
	//system("pause");
	return 0;
}