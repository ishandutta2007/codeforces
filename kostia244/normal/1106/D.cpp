#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, f, t;
vi ord;
vector<set<int>> g;
bitset<100100> vis(0);


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	g.resize(n + 1, set<int>());
	while(m--) {
		cin >> f >> t;
		g[f].insert(t);
		g[t].insert(f);
	}
	priority_queue<int> q;
	q.push(-1);
	while(!q.empty()) {
		int to = -q.top();
		q.pop();
		if(vis.test(to))
			continue;
		vis.set(to);
		cout << to << " ";
		for(auto& i : g[to]) {
			if(!vis.test(i))
				q.push(-i);
		}
	}
}