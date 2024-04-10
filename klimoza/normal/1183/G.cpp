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
	
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		multiset<pair<int, int>> b;
		int t1, t2;
		for(int i = 0 ; i < n; i++) {
			cin >> t1 >> t2; t1--;
			a[t1].first++;
			a[t1].second += t2;
		}
		for (auto u : a) b.insert(u);
		sort(a.begin(), a.end());
		int t = (*b.rbegin()).first;
		pair<int, int> ans;
		while(t != 0) {
			//cout << a[i].first << " lol " << a[i].second << endl;
			auto u = (*b.rbegin());
			set<pair<int, int>>::iterator f = b.end();
			//for (auto u : b) cout << u.first << " " << u.second << " ||| ";
			//cout << endl;
			f--;
			//cout << u.first << " " << u.second << " " << t << endl;
			if (u.first > t) {
				u.first = min(u.first, t);
				u.second = min(u.second, t);
				b.erase(f);
				b.insert(u);
				continue;
			}
			if (u.first == 0) break;
			t = min(t, u.first);
			ans.first += t;
			ans.second += min(t, u.second);
			b.erase(f);
			t--;
		}
		cout << ans.first << " " << ans.second << endl;
	}
	//system("pause");
	return 0;
}