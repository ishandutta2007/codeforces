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

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);

	double n, s; cin >> n >> s;
	vector < pair<pair<double, double>, int>> pp(n);
	double l = 0, r = 1e6;
	for (int i = 0; i < n; i++) {
		cin >> pp[i].first.first >> pp[i].first.second >> pp[i].second;
	}
	while (r - l > eps) {
		double mini = 1e9;
		double maxi = -1e9;
		double mid = (r + l) / 2;
		vector<pair<pair<double, int>, int>> ev;
		for (auto u : pp) {
			if (u.second == 2) {
				if ((1e6 - u.first.first) / (u.first.second + s) > mid) {
					continue;
				} else if ((1e6 - u.first.first) / u.first.second <= mid) {
					ev.push_back({ { -1e9, -1 }, 0 });
					ev.push_back({ { 1e9, 1 }, 0 });
				}
				else {
					ev.push_back({ { ceil((mid * (s * s - u.first.second * u.first.second) - (1e6 - u.first.first) * (s - u.first.second) - s * u.first.first) / -s), -1 }, 0 });
					ev.push_back({ { u.first.first, 1 }, 0 });
				}
			}
			else {
				if (u.first.first / (u.first.second + s) > mid) {
					continue;
				}
				else if (u.first.first / u.first.second <= mid) {
					ev.push_back({ { -1e9, -1 }, 1 });
					ev.push_back({ { 1e9, 1 }, 1 });
				}
				else {
					ev.push_back({ { floor((mid * (s * s - u.first.second * u.first.second) + u.first.first * u.first.second) / s), 1 }, 1 });
					ev.push_back({ { u.first.first, -1 }, 1 });
				}
			}
		}
		sort(ev.begin(), ev.end());
		int cnt1 = 0, cnt2 = 0;
		for (auto u : ev) {
			if (u.first.second == -1) {
				if (u.second == 0) cnt1++;
				else cnt2++;
			}
			else {
				if (u.second == 0) cnt1--;
				else cnt2--;
			}
			if (cnt1 > 0 && cnt2 > 0) break;
		}
		if (cnt1 > 0 && cnt2 > 0) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r << endl;
	//system("pause");
	return 0;
}