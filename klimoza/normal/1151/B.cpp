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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	bool fl = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (j > 0 && a[i][j - 1] != a[i][j]) fl = true;
		}
	}
	int h = 0;
	for (int i = 0; i < n; i++) {
		h ^= a[i][0];
	}
	if (h) {
		cout << "TAK\n";
		for (int i = 0; i < n; i++) cout << 1 << " ";
	}
	else if (!fl) {
		cout << "NIE\n";
	}
	else {
		cout << "TAK\n";
			bool f = false;
			for (int i = 0; i < n; i++) {
				if (f) cout << 1 << " ";
				else {
					for (int j = 1; j < m; j++) {
						if (a[i][j] != a[i][0]) {
							f = true;
							cout << j + 1 << " ";
							break;
						}
					}
					if (!f) cout << 1 << " ";
				}
			}
	}
	//system("pause");
	return 0;
}