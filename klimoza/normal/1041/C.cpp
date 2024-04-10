#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<pair<int, int>> a(n);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	//for (int i = 0; i < n; i++) {
	//	cout << a[i].first << " " << a[i].second << "\n";
	//}
	vector<int> ans(n);
	vector<int> day(n, -1000000000);
	deque<int> qu;
	pair<int, int> t;
	d++;
	qu.push_front(0);
	qu.push_back(1000000000);
	int max_i = 0;
	for (int i = 0; i < n; i++) {
		t = a[i];
		for (int j = 0; j < qu.size(); j++) {
			if (day[qu[j]] <= t.first - d) {
				day[qu[j]] = t.first;
				ans[t.second] = qu[j] + 1;
				max_i = max(max_i, qu[j] + 1);
				if (j == 0) {
					qu.push_front(0);
				}
				qu[j]++;
				if (qu[j] > qu[j + 1]) swap(qu[j], qu[j + 1]);
				break;
			}
		}
	}
	cout << max_i << "\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	//system("pause");
	return 0;
}