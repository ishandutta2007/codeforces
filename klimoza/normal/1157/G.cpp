#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")	
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
typedef vector<vector<int>> matrix;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

bool check_matrix(matrix &a, int n, int m, bool fl, vector<int> &ans) {
	for (int i = 1; i < n; i++) {
		bool fl1 = false;
		bool fl2 = false;
		for (int j = 0; j < m; j++) {
			if (j > 0 && a[i][j] && !a[i][j - 1]) fl1 = true;
			if (j > 0 && !a[i][j] && a[i][j - 1]) fl2 = true;
		}
		if (fl1 && fl2) return false;
		else if (fl && (fl1 || fl2)) return false;
		else if (fl) {
			if (!a[i][0]) {
				ans[i] ^= 1;
				for (int j = 0; j < m; j++) {
					a[i][j] ^= 1;
				}
			}
			continue;
		}
		else if (fl1 || fl2) {
			if (fl2) {
				ans[i] ^= 1;
				for (int j = 0; j < m; j++) {
					a[i][j] ^= 1;
				}
			}
			fl = true;
		}
		else {
			if (a[i][0]) {
				ans[i] ^= 1;
				for (int j = 0; j < m; j++) {
					a[i][j] ^= 1;
				}
			}
			continue;
		}
	}
	return true;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> an1(m);
	vector<int> an2(n);
	bool fl = false;
	bool h = false;
	for (int j = 0; j < m; j++) {
		if (a[0][j]) {
			an1[j] ^= 1;
			for (int i = 0; i < n; i++) {
				a[i][j] ^= 1;
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		if (i != 0) {
			//cout << "lol\n";
			for (int j = 0; j < n; j++) {
				a[j][m - i] ^= 1;
			}
			an1[m - i] ^= 1;
			fl = true;
		}
		//for (int i : an2) cout << i << " ";
		//cout << endl;
		h = check_matrix(a, n, m, fl, an2);
		if (h) {
			break;
		}
	}
	//cout << h << endl;
	if (h) {
		cout << "YES\n";
		for (int i : an2) cout << i;
		cout << endl;
		for (int i : an1) cout << i;
		cout << endl;
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}