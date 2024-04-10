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
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;

vector<pair<vector<int>, vector<int>>> edge;

bool dfs(int v, int c, vector<int> &ans) {
	ans[v] = c;
	if (c == -1) {
		for (int u : edge[v].first) {
			if (ans[u] && ans[u] != c) return false;
			if (!ans[u] && !dfs(u, c, ans)) return false;
		}
	}
	else {
		for (int u : edge[v].second) {
			if (ans[u] && ans[u] != c) return false;
			if (!ans[u] && !dfs(u, c, ans)) return false;
		}
	}
	return true;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	int l;
	vector<int> ans(m + 1);
	edge.resize(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> l;
		a[i].resize(l);
		for (int j = 0; j < l; j++) cin >> a[i][j];
		if (i > 0) {
			bool fl = false;
			for (int j = 0; j < min(l, (int)a[i - 1].size()); j++) {
				if (a[i - 1][j] != a[i][j]) {
					if (a[i - 1][j] < a[i][j]) {
						edge[a[i - 1][j]].second.push_back(a[i][j]);
						edge[a[i][j]].first.push_back(a[i - 1][j]);
					}
					else {
						if (ans[a[i - 1][j]] == 1 || ans[a[i][j]] == -1) {
							cout << "No\n";
							return 0;
						}
						ans[a[i - 1][j]] = -1;
						ans[a[i][j]] = 1;
					}
					fl = true;
					break;
				}
			}
			if (!fl && l < a[i - 1].size()) {
				cout << "No\n";
				return 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!ans[i]) continue;
		if (!dfs(i, ans[i], ans))  {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	vector<int> f;
	for (int i = 1; i <= m; i++) {
		if (ans[i] == -1) f.push_back(i);
	}
	cout << f.size() << endl;
	for (int i : f) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}