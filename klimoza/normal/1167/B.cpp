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
ll mod = 998244353;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	vector<int> f = { 4, 8, 15, 16, 23, 42 };
	map < pair<int, int>, pair<pair<int, int>, int>> d;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++) {
				if (k == j || k == i || i == j) continue;
				d[{f[i] * f[j], f[j] * f[k]}] = { {f[i], f[j]}, f[k] };
			}
		}
	}
	cout << "? 1 2" << endl;
	int r1, r2, r3, r4;
	cin >> r1;
	cout << "? 2 3" << endl;
	cin >> r2;
	cout << "? 4 5" << endl;
	cin >> r3;
	cout << "? 5 6" << endl;
	cin >> r4;
	vector<int> ans(6);
	ans[0] = d[{r1, r2}].first.first;
	ans[1] = d[{ r1, r2 }].first.second;
	ans[2] = d[{r1, r2}].second;
	ans[3] = d[{r3, r4}].first.first;
	ans[4] = d[{r3, r4}].first.second;
	ans[5] = d[{r3, r4}].second;
	cout << "! ";
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}