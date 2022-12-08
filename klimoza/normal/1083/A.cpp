#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;

vector<int> w;
vector<vector<int>> edge;
map<pair<int, int>, int> s;
vector<char> used;

ll ans = 0;

ll dfs(int v) {
	used[v] = true;
	ll maxi1 = 0;
	ll maxi2 = 0;
	ll r = 0;
	for (int u : edge[v]) {
		if (!used[u]) {
			r = dfs(u);
			r -= s[{v, u}];
			if (r > maxi1) {
				maxi2 = maxi1;
				maxi1 = r;
			}
			else if (r > maxi2) {
				maxi2 = r;
			}
		}
	}
	ans = max(ans, w[v] + maxi1 + maxi2);
	return maxi1 + w[v];
}


int main() {
	int n;
	cin >> n;
	w.resize(n);
	edge.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++)cin >> w[i];
	int t1, t2, t3;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2 >> t3;
		t1--;
		t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
		s[{t1, t2}] = t3;
		s[{t2, t1}] = t3;
	}
	dfs(0);
	cout << ans << endl;
	//system("pause");
	return 0;
}