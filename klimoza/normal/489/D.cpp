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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> is(n, vector<int>(n));
	vector<vector<int>> edge(n);
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
	}
	for (int i = 0; i < n; i++) {
		for (int j : edge[i]) {
			for (int k : edge[j]) {
				if (k == i) continue;
				is[i][k]++;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			ans += (is[i][j] * (is[i][j] - 1) / 2);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}