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

vector<vector<int>> edge;

bool dfs(int v, int c, vector<int> &ans) {
	ans[v] = c;
	for (int u : edge[v]) {
		if (!ans[u]) {
			if (!dfs(u, c, ans)) return false;
		}
		else {
			if (ans[u] != c) return false;
		}
	}
	return true;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> p(n);
	set<int> f;
	vector<int> num;
	map<int, int> c;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (f.find(p[i]) == f.end()) {
			num.push_back(p[i]);
		}
		f.insert(p[i]);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		c[num[i]] = i;
	}
	vector<int> ans(num.size());
	vector<int> an(num.size());
	edge.resize(num.size());
	for (int i = 0; i < n; i++) {
		auto r1 = f.find(a - p[i]);
		auto r2 = f.find(b - p[i]);
		if (r1 == f.end() && r2 == f.end()) {
			cout << "NO\n" << endl;
			return 0;
		}
		else if (r1 != f.end() && r2 != f.end()) {
			//cout << c[p[i]] << endl;
			int ind1 = c[p[i]];
			int ind2 = c[a - p[i]];
			int ind3 = c[b - p[i]];
			edge[ind1].push_back(ind2);
			edge[ind2].push_back(ind1);
			edge[ind1].push_back(ind3);
			edge[ind3].push_back(ind1);
		}
		else if (r1 != f.end()) {
			ans[c[p[i]]] = -1;
			ans[c[a - p[i]]] = -1;
		}
		else {
			ans[c[p[i]]] = 1;
			ans[c[b - p[i]]] = 1;
		}
	}
	//for (int i : p) cout << ans[i] << " ";
	//cout << endl;
	for (int i = 0; i < n; i++) {
		int ind = c[p[i]];
		if (!ans[ind]) continue; 
		if (!dfs(ind, ans[ind], ans)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	//cout << c[4] << endl;
	for (int i : p) cout << (ans[c[i]] == -1 ? 0 : 1) << " ";
	cout << endl;
	//system("pause");
	return 0;
}