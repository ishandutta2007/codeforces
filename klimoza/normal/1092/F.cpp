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

vector<ll> sz;
vector<ll> cnt;
vector<ll> a;
vector<vector<int>> edge;

void dfs_sz(int v, int p) {
	sz[v] = 0;
	for (int i : edge[v]) {
		if (i == p) continue;
		dfs_sz(i, v);
		sz[v] += sz[i] + a[i];
	}
}

void dfs_cnt(int v, int p) {
	for (int u : edge[v]) {
		if (u == p) continue;
		dfs_cnt(u, v);
		cnt[v] += cnt[u];
	}
	cnt[v] += sz[v];
}

ll maxi = 0;

void dfs(int v, int p, ll cur, ll tot) {
	maxi = max(maxi, tot + cnt[v]);
	//cout << v + 1 << " " << p + 1 << " " << cur << " " << tot << endl;
	for (int u : edge[v]) {
		if (u == p) continue;
		dfs(u, v, cur + sz[v] - sz[u] - a[u] + a[v], tot + cur + cnt[v] + sz[v] + a[v] - 2 * sz[u] - cnt[u] - 2 * a[u]);
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	sz.resize(n);
	a.resize(n);
	edge.resize(n);
	cnt.resize(n);
	int t1, t2;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		cin >> t1 >> t2; t1--;
		t2--;
		edge[t2].push_back(t1);
		edge[t1].push_back(t2);
	}
	dfs_sz(0, -1); dfs_cnt(0, -1); 
	for (int i = 0; i < n; i++) {
		//cout << sz[i] << " " << cnt[i] << " " << i + 1<< endl;
	}
	dfs(0, -1, 0, 0);
	cout << maxi << endl;
	//system("pause");
	return 0;
}