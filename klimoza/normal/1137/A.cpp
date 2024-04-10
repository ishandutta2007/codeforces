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
double eps = 1e-12;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> up(n, vector<int>(m));
	vector<vector<int>> side(m, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			up[i][j] = (a[i][j]);
			side[j][i] = (a[i][j]);
		}
	}
	vector<map<int, int>> r1(n);
	vector<map<int, int>> r2(m);
	vector<int> sz1(n);
	vector<int> sz2(m);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur = 1;
		sort(up[i].begin(), up[i].end());
		r1[i][up[i][0]] = 1;
		for (int j = 1; j < m; j++) {
			if (up[i][j] == up[i][j - 1]) continue;
			else {
				cur++;
				r1[i][up[i][j]] = cur;
			}
		}
		sz1[i] = cur;
	}
	for (int j = 0; j < m; j++) {
		cur = 1;
		sort(side[j].begin(), side[j].end());
		r2[j][side[j][0]] = 1;
		for (int i = 1; i < n; i++) {
			if (side[j][i] == side[j][i - 1]) continue;
			else {
				cur++;
				r2[j][side[j][i]] = cur;
			}
		}
		sz2[j] = cur;
	}
	int c1 = 0;
	int c2 = 0;
	int f1 = 0;
	int f2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c1 = r1[i][a[i][j]];
			c2 = r2[j][a[i][j]];
			f1 = sz1[i];
			f2 = sz2[j];
			//cout << c1 << " " << c2 << " " << f1 << " " << f2 << " " << i << " " << j << endl;
			cout << max(f1 - c1 + max(c1, c2), f2 - c2 + max(c1, c2)) << " ";
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}