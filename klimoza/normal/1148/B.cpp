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

	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	if (k >= n || k >= m) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> a(n), b(m);;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ind = m;
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < m; i++) {
		if (b[i] >= a[0] + ta) {
			ind = i;
			break;
		}
	}
	if (ind == m) {
		cout << -1 << endl;
		return 0;
	}
	//cout << ind << endl;
	int l = 0, r = ind;
	int win = 0;
	int id = 0;
	for (; l < n; l++) {
		if (l > k) break;
		while (r < m && a[l] + ta > b[r]) r++;
		if ((r - ind) - l > win) {
			id = l;
			win = r - ind - l;
		}
	}
	//cout << win << " " << id << " l" << endl;
	int f = m;
	for (int i = 0; i < m; i++) {
		if (a[id] + ta <= b[i]) {
			f = i;
			break;
		}
	}
	if (f == m) {
		cout << -1 << endl;
	}
	else {
		int h = f + (k - id);
		if (h >= m) {
			cout << -1 << endl;
		}
		else {
			cout << b[h] + tb << endl;
		}
	}
	//system("pause");
	return 0;
}