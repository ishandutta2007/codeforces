#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<pair<int, int>> b(n);
	map<pair<int, int>, int> g;
	for (int i = 0; i < n; i++) {
		cin >> b[i].first >> b[i].second;
		g[b[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		set<pair<int, int>> f;
		for (int j = 0; j < n; j++) {
			if(j != i)
			f.insert(b[j]);
		}
		pair<int, int> t = { a[0].first + b[i].first, a[0].second + b[i].second };
		bool fl = true;
		for (int j = 1; j < n; j++) {
			if (f.find({ t.first - a[j].first, t.second - a[j].second }) == f.end()) {
				fl = false;
				break;
			}
			else {
				f.erase({ t.first - a[j].first, t.second - a[j].second });
			}
		}
		if (fl) {
			cout << t.first << " " << t.second << endl;
			break;
		}
	}
	//system("pause");
	return 0;
}