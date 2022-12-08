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

const int NN = 5e5 + 1;

vector<int> cl[NN];
int cnt[NN];
int cur[NN];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vector<int> a(m);
	vector<int> b(s);
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < s; i++) cin >> b[i];
	for (int i = 0; i < s; i++) {
		cnt[b[i]]++;
	}
	for (int i = 0; i < m; i++) {
		cl[a[i]].push_back(i);
	}
	vector<bool> used(m);
	int maxi = 0;
	int ct = 0;
	int res = m - n * k;
	for (int i = 0; i < NN; i++) {
		if (cl[i].size() < cnt[i]) {
			cout << -1 << endl;
			return 0;
		}
		for (int j = 0; j < cnt[i]; j++) {
			used[cl[i][j]] = true;
			cur[i] = j;
			maxi = max(maxi, cl[i][j]);
			ct += (cl[i][j] >= k);
		}
	}
	//cout << maxi << " " << ct << " " << gl << endl;
	if (maxi - k + 1 <= res) {
		res = max(0, maxi - (k - 1));
		cout << res << endl;
		for (int i = maxi; i >= 0; i--) {
			if (res == 0) break;
			if (!used[i]) {
				cout << i + 1 << " ";
				res--;
			}
		}
		//system("pause");
		return 0;
	}
	for (int i = 1, l = 1, r = k; i < m; i++) {
		if (r == m) break;
		int f = -1;
		if (used[l - 1]) {
			if (cur[a[l - 1]] + 1 == cl[a[l - 1]].size()) break;
			f = cl[a[l - 1]][cur[a[l - 1]] + 1];
			cur[a[l - 1]]++;
			used[f] = true;
			maxi = max(maxi, f);
			ct += (f >= r);
		}
		if (used[r] && f != r) {
			ct--;
		}
		//cout << l << " " << r << " " << ct << " " << maxi << " " << f << endl;
		if (l % k == 0 && maxi - r <= res) {
			res = max(0, maxi - r);
			cout << res << endl;
			for (int i = maxi; i >= 0; i--) {
				if (res == 0) break;
				if (!used[i]) {
					cout << i + 1 << " ";
					res--;
				}
			}
			//system("pause");
			return 0;
		}
		l++;
		r++;
	}
	cout << -1 <<  endl;
	//system("pause");
	return 0;
}