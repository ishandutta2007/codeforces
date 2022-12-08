#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

vector<vector<int>> edge;
vector<int> p;
vector<int> c;
set<int> qu;

void dfs(int v) {
	int cnt = 0;
	//cout << v << endl;
	for (int u : edge[v]) {
		dfs(u);
		if (c[u]) {
			cnt++;
		}
	}
	//cout << cnt << " " << v << endl;
	if (cnt == edge[v].size() && c[v]) qu.insert(v);
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	int n;
	cin >> n;
	edge.resize(n);
	p.resize(n);
	c.resize(n);
	int ind = -1;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> c[i];
		if (p[i] != -1) {
			p[i]--;
			edge[p[i]].push_back(i);
		}
		else {
			ind = i;
		}
	}
	dfs(ind);
	if (qu.empty()) {
		cout << -1 << endl;
	}
	while (!qu.empty()) {
		int cur = *qu.begin();
		cout << cur + 1 << " ";
		qu.erase(qu.begin());
	}
	//system("pause");
	return 0;
}