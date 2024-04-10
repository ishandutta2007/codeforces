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

	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> f1;
	vector<pair<pair<int, int>, int>> f2;
	int t1, t2;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		if (t1 < t2) f1.push_back({ {t2, t1}, i });
		else f2.push_back({ {t2, t1}, i });
	}
	sort(f1.begin(), f1.end()); sort(f2.begin(), f2.end());
	reverse(f1.begin(), f1.end());
	if (f1.size() > f2.size()) {
		cout << f1.size() << endl;
		for (auto u : f1) cout << u.second + 1<< " ";
	}
	else {
		cout << f2.size() << endl;
		for (auto u : f2) cout << u.second + 1 << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}