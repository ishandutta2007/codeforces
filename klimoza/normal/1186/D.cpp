#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	double sm = 0;
	vector<double> ans(n);
	vector<pair<pair<double, double>, int>> less;
	vector<pair<pair<double, double>, int>> mr;
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		if (ceil(a) == floor(a)) {
			sm += a;
			ans[i] = a;
		}
		else if (a < 0) less.push_back({ { floor(a), ceil(a) }, i });
		else mr.push_back({ { floor(a), ceil(a) }, i });
	}
	sort(less.begin(), less.end());
	sort(mr.begin(), mr.end());
	for (auto u : less) sm += u.first.second;
	for (auto u : mr) sm += u.first.first;
	if (sm > 0) {
		int ind = 0;
		for (; ind < sm; ind++) {
			ans[less[ind].second] = less[ind].first.first;
		}
		for (; ind < less.size(); ind++) {
			ans[less[ind].second] = less[ind].first.second;
		}
		for (auto u : mr) ans[u.second] = u.first.first;
	}
	else {
		sm *= -1;
		int ind = 0;
		for (; ind < sm; ind++) {
			ans[mr[ind].second] = mr[ind].first.second;
		}
		for (; ind < mr.size(); ind++) {
			ans[mr[ind].second] = mr[ind].first.first;
		}
		for (auto u : less) ans[u.second] = u.first.second;
	}
	for (int i : ans) cout << i << endl;
	//system("pause");
	return 0;
}