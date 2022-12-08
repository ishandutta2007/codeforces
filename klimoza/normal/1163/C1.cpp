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
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<double, double>> po(n);
	for (int i = 0; i < n; i++) {
		cin >> po[i].first >> po[i].second;
	}
	vector<pair<double, double>> lines;
	set<pair<double, double>> lin;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double k, b;
			if (po[i].first == po[j].first) {
				k = -INFi;
				b = po[i].first;
			}
			else {
				k = (po[i].second - po[j].second) / (po[i].first - po[j].first);
				b = po[i].second - k * po[i].first;
			}
			if (lin.find({ k, b }) == lin.end()) {
				lines.push_back({ k, b });
				lin.insert({ k, b });
			}
		}
	}
	n = lines.size();
	int ans = n * (n - 1) / 2;
	//cout << ans << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (lines[i].first == lines[j].first) ans--;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}