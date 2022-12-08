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

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a1(n, vector<int>(m));
	vector<vector<int>> a2(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a1[i][j];
		}
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a2[i][j];
		}
	}
	vector<vector<int>> b1(n, vector<int>(m));
	vector<vector<int>> b2(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b1[i][j] = min(a1[i][j], a2[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b2[i][j] = max(a1[i][j], a2[i][j]);
		}
	}
	bool fl = true;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (b1[i][j] > b1[i][j - 1] && b2[i][j] > b2[i][j - 1]) continue;
			fl = false;
			break;
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			if (b1[i][j] > b1[i - 1][j] && b2[i][j] > b2[i - 1][j]) continue;
			fl = false;
			break;
		}
	}
	if (!fl) {
		cout << "Impossible\n";
	}
	else {
		cout << "Possible\n";
	}
	//system("pause");
	return 0;
}