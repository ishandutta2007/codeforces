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
long double eps = 1e-8;

int n, m;
vector<multiset<int>> get(vector<vector<int>> a) {
	vector<multiset<int>> f1(n + m - 1);
	for (int i = 0; i < n; i++) {
		int x = i;
		int y = 0;
		while (x >= 0 && y < m) {
			f1[i].insert(a[x][y]);
			x--;
			y++;
		}
	}
	for (int i = 1; i < m; i++) {
		int x = n - 1;
		int y = i;
		while (x >= 0 && y < m) {
			f1[i + n - 1].insert(a[x][y]);
			x--;
			y++;
		}
	}
	return f1;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<multiset<int>> f1 = get(a);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<multiset<int>> f2 = get(a);
	if (f1 == f2) cout << "YES\n";
	else cout << "NO\n";
	//system("pause");
	return 0;
}