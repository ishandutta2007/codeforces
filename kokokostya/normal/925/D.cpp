



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <random>
#include <cassert>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int MX = 3e5 + 7;
vector<int> g[MX];

const int INF = 1e9 + 7;
vector<int> comp;
bool used[MX];

void dfs(int v) {
	used[v] = 1;
	for (int i : g[v])
		if (!used[i])
			dfs(i);
	comp.push_back(v);
}

set< pair<int, int> > gr;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		gr.insert({ a, b });
		gr.insert({ b, a });
	}
	queue<int> q;
	vector<int> d(n, INF);
	d[0] = 0, q.push(0);
	vector<int> p(n, -1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int j : g[v]) {
			if (d[j] == INF) {
				d[j] = d[v] + 1;
				p[j] = v;
				q.push(j);
			}
		}
	}
	int is = -1;
	for (int i = 0; i < n - 1; i++)
		if (d[i] == 2)
			is = i;

	vector<int> ans;
	if (d[n - 1] != INF) {
		int now = n - 1;
		while (now) {
			ans.push_back(now + 1);
			now = p[now];
		}
		ans.push_back(1);
		reverse(ans.begin(), ans.end());
	}
	


	if (is == -1) {
		used[0] = 1;
		int a = -1, b = -1, c = -1;
		for (int i : g[0]) {
			if (!used[i]) {
				dfs(i);
				int sz = comp.size();

				for (int j : comp) {
					if (g[j].size() != sz) {
						a = j;

						vector<int> d2(n, INF);
						d2[0] = -1;
						d2[a] = 0, q.push(a);
						while (!q.empty()) {
							int v = q.front();
							q.pop();
							for (int j : g[v]) {
								if (d2[j] == INF) {
									d2[j] = d2[v] + 1;
									p[j] = v;
									q.push(j);
								}
							}
						}
						for (int s = 0; s < n; s++) {
							if (d2[s] == 2) {
								c = s;
								b = p[s];
								break;
							}
						}




						break;
					}
				}
				if (a != -1)
					break;

				comp.clear();
			}
		}


		if (d[n - 1] == INF) {
			if (a != -1) {
				cout << 5 << '\n';
				cout << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << a + 1 << ' ' << n << '\n';
				return 0;
			}
			cout << -1;
			return 0;
		}
		
		if (a != -1 && d[n - 1] >= 5) {
			cout << 5 << '\n';
			cout << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << a + 1 << ' ' << n << '\n';
			return 0;
		}
			cout << d[n - 1] << '\n';
			for (int i : ans)
				cout << i << ' ';
			return 0;

	}
	else {
		if (d[n - 1] <= 4) {
			cout << d[n - 1] << '\n';
			for (int i : ans)
				cout << i << ' ';
			return 0;
		}
		vector<int> out;
		while (is) {
			out.push_back(is + 1);	
			is = p[is];
		}
		cout << 4 << '\n';
		out.push_back(1);
		reverse(out.begin(), out.end());
		out.push_back(1);
		out.push_back(n);
		for (int i : out)
			cout << i << ' ';	
	}

	return 0;
}