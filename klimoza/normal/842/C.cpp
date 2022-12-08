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

vector<int> p;
vector<int> cur;
vector<int> a;
vector<vector<int>> edge;
vector<int> ans;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

void dfs(int v, int par, int _r, int d) {
	if (par == -1) {
		ans[v] = a[v];
	}
	else {
		_r = gcd(_r, a[v]);
		ans[v] = _r;
		for (int i = 0; i < p.size(); i++) {
			if (a[v] % p[i] == 0) {
				cur[i]++;
			}
		/*	if (v == 4) {
				cout << p[i] << " " << cur[i] << endl;
			}*/
			if (cur[i] >= d - 1) ans[v] = max(ans[v], p[i]);
		}
	}
	for (int u : edge[v]) {
		if (u == par) continue;
		dfs(u, v, _r, d + 1);
	}
	if (par != -1) {
		for (int i = 0; i < p.size(); i++) {
			if (a[v] % p[i] == 0) {
				cur[i]--;
			}
		}
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	a.resize(n);
	edge.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t1, t2;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	for (int i = 1; i <= sqrt(a[0]); i++) {
		if (a[0] % i == 0) {
			p.push_back(i);
			p.push_back(a[0] / i);
		}
	}
	cur.assign(p.size(), 1);
	sort(p.begin(), p.end());
	dfs(0, -1, 0, 1);
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}