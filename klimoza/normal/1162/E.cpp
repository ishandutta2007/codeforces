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

vector<int> z_function(vector<int> st) {
	int n = st.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < n && st[z[i]] == st[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	z[0] = n;
	return z;
}

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}


int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	/*int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> f(n + 1);
	vector<pair<int, int>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
		f[(a[i].second - a[i].first + n) % n].push_back(a[i]);
	}
	for (int i = 1; i <= n; i++) sort(f[i].begin(), f[i].end(), cmp);
	vector<vector<int>> g(n + 1);
	vector<int> z;
	vector<int> k(n + 1);
	int need = n;
	for (int i = 1; i <= n; i++) {
		cout << i << endl;
		if (f[i].size() == 0) {
			need--;
			continue;
		}
		else if (f[i].size() == 1) {
			cout << "No\n";
			system("pause");
			return 0;
		}
		for (int j = 1; j < f[i].size(); j++) {
			g[i].push_back(f[i][j].second - f[i][j - 1].second);
		}
		cout << i << " " << 2 << endl;
		g[i].push_back(f[i][0].second + n - f[i][f[i].size() - 1].second);
		cout << "perdezh\n";
		for (int i : g[i]) cout << i << " ";
		cout << endl;
		z = z_function(g[i]);
		int last = f[i][0].second + n;
		for (int h = 1; h < f[i].size(); h++) {
			if (z[h] == f[i].size() - h && z[f[i].size() - h] == h) {
				k[last - f[i][f[i].size() - h].second]++;
			}
		}
	}
	cout << "lol\n";
	cout << need << endl;
	for (int i = 0; i <= n; i++) {
		cout << k[i] << " " << i << endl;
		if (k[i] == need) {
			cout << "Yes\n";
			system("pause");
			return 0;
		}
	}
	cout << "No\n";
	*/
	int n;
	cin >> n;
	vector<int> a(n);
	int mini = INFi;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mini = min(mini, a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mini) cnt++;
	}
	if (cnt > n / 2) cout << "Bob\n";
	else cout << "Alice\n";
	//system("pause");
	return 0;
}