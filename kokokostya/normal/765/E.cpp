#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

int n;
vector< vector<int> > g;
vector<int> sz;
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	g.resize(n);
	sz.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	queue<int> q;
	vector<int> d(n, INF);
	vector<int> sec(n, INF);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		sz[i] = g[i].size();
		if (sz[i] == 1) {
			q.push(i);
			d[i] = 0;
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i : g[v]) {
			if (sz[i] != 0) {
				if (d[i] == INF) {
					d[i] = d[v] + 1;
					sz[i]--;
					if (sz[i] == 1) {
						q.push(i);
					}
				}
				else {
					if (d[i] == d[v] + 1) {
						sz[i]--;
						if (sz[i] == 1) {
							q.push(i);
						}
					}
					else{
						if (sec[i] == INF) {
							sec[i] = d[v] + 1;
						}
						else {
							if (sec[i] != d[v] + 1) {
								cout << -1;
								return 0;
							}
						}
					}
				}
			}
		}
		sz[v] = 0;
	}
	int numb = -1;
	for (int i = 0; i < n; i++) {
		if (sec[i] != INF) {
			if (numb != -1) {
				cout << -1;
				return 0;
			}
			numb = i;
		}
	}
	int ans = 0;
	if(numb != -1)
		ans = d[numb] + sec[numb];
	else {
		for (int i = 0; i < n; i++)
			ans = max(ans, d[i]);
	}
	while (ans % 2 == 0)
		ans /= 2;
	cout << ans;
	return 0;
}