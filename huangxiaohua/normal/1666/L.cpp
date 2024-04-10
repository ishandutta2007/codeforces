#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
typedef pair <int, int> pii;

const int N = 2e5 + 5;

int n, m, s, t, cur;
vector <int> e[N];
int pre[N];
int col[N];

void answer (int u, int v) {
	vector <int> v1, v2;
	
	v1.pb(v);
	cur = v;
	while (pre[cur]) {
		cur = pre[cur];
		v1.pb(cur);
	}
	
	v2.pb(v);
	v2.pb(u);
	cur = u;
	while (pre[cur]) {
		cur = pre[cur];
		v2.pb(cur);
	}
	
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	
	cout << v1.size() << endl;
	for (int i : v1) {
		cout << i << ' ';
	}
	cout << endl;
	cout << v2.size() << endl;
	for (int i : v2) {
		cout << i << ' ';
	}
	cout << endl;
}

int main () {
	cin >> n >> m >> s;
	for (int i = 1;i <= m;++i) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
	}
	
	queue <int> q;
	for (int i = 1;i <= n;++i) {
		col[i] = -1;
	}
	col[s] = -2;
	for (int i = 0;i < e[s].size();++i) {
		int v = e[s][i];
		pre[v] = s;
		col[v] = i;
		q.push(v);
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (col[v] == -1) {
				col[v] = col[u];
				pre[v] = u;
				q.push(v);
			} else if ((col[u] != col[v]) && (col[v] >= 0)) {
				cout << "Possible" << endl;
				answer(u, v);
				return 0;
			}
		}
	}
	
	cout << "Impossible" << endl;
	return 0;
}