#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

struct vert {
	int x, y, vx, vy;
};

bool comp(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b) {
	return (a.first.first * 1ll * b.first.second < a.first.second * 1ll * b.first.first) || (a.first.first * 1ll * b.first.second == a.first.second * 1ll * b.first.first && (a.second > b.second));
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<vert> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y >> a[i].vx >> a[i].vy;
	vector< pair< pair<int, int>, int > > arr;
	if (x1 == x2 || y1 == y2) {
		cout << -1;
		return 0;
	}
	bool is = 1;
	for (int i = 0; i < n; i++) {
		if (a[i].x <= x1 || a[i].x >= x2)
			is = 0;
		if (a[i].y <= y1 || a[i].y >= y2)
			is = 0;
	}
	if (is) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i].vx == 0) {
			if (a[i].x <= x1 || a[i].x >= x2) {
				cout << -1;
				return 0;
			}
		}
		else {
			if (a[i].vx < 0) {
				swap(x1, x2);
				arr.push_back({ {-(x1 - a[i].x) , -a[i].vx}, 0 });
				arr.push_back({ { -(x2 - a[i].x) , -a[i].vx }, 2 });
				if (a[i].vx < 0)
					swap(x1, x2);
			}
			else {
				arr.push_back({ { (x1 - a[i].x) , a[i].vx }, 0 });
				arr.push_back({ { (x2 - a[i].x) , a[i].vx }, 2 });
			}
		}
			if (a[i].vy == 0) {
				if (a[i].y <= y1 || a[i].y >= y2) {
					cout << -1;
					return 0;
				}
			}
			else {
				if (a[i].vy < 0) {
					swap(y1, y2);
					arr.push_back({ { -(y1 - a[i].y) , -a[i].vy }, 0 });
					arr.push_back({ { -(y2 - a[i].y) , -a[i].vy }, 2 });
					if (a[i].vy < 0)
						swap(y1, y2);
				}
				else {
					arr.push_back({ { (y1 - a[i].y) , a[i].vy }, 0 });
					arr.push_back({ { (y2 - a[i].y) , a[i].vy }, 2 });
				}
		}
	}
	sort(arr.begin(), arr.end(), comp);
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].second == 0)
			cnt++;
		if(arr[i].second == 2)
			cnt--;
		if (cnt == arr.size() / 2) {
			if (arr[i].first.first * 1ll * arr[i].first.second >= 0) {
				cout << fixed << setprecision(15) << (double(arr[i].first.first) + 1e-20) / arr[i].first.second;
				return 0;
			}
		}
	}
	cout << -1;


	return 0;
}