#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int dp[5005], p[5005];
bool taken[5005];

int taken_first, taken_last;

bool ok(int x, int y) {
	return x % 7 == y % 7 || abs(x-y) == 1 || x == 0 || y == 0;
}

vector<pair<int, int>> e[10005];
int d[10005];

int spfa(int x, int goal, int sz) {
	vector<short> status(sz, 0);
	deque<int> q;

	fill(d, d+sz, 1e9);

	q.push_front(x);
	status[x] = 2;
	d[x] = 0;

	while (!q.empty()) {
		x = q.front(); q.pop_front();
		status[x] = 1;

		for (auto ee : e[x]) {
			int y = ee.first;
			int len = ee.second;

			if (d[x] + len < d[y]) {
				d[y] = d[x] + len;
				if (status[y] == 2) {
					//
				} else if (status[y] == 1) {
					q.push_front(y);
					status[y] = 2;
				} else {
					q.push_back(y);
					status[y] = 2;
				}
			}
		}
	}

	return d[goal];
}

void add_edge(int x, int y, int cost) {
	e[x].push_back({y, cost});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n+1; i++) {
		for (int j=0; j<i; j++) {
			if (ok(a[i], a[j])) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					p[i] = j;
				}
			}
		}
	}

	for (int x=n+1; x; x=p[x]) {
		taken[x] = true;

		if (x <= n && taken_last == 0) {
			taken_last = x;
		}

		taken_first = x;
	}

	int sol = dp[n+1] - 1;

	for (int i=1; i<=n; i++) {
		add_edge(0, 2*i-1, 0); 
		add_edge(2*i, 2*n+1, 0);
		if (taken[i]) {
			add_edge(2*i, 2*i-1, 1);
		} else {
			add_edge(2*i-1, 2*i, -1);
		}		
	}

	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (ok(a[i], a[j])) {
				if (taken[j] && i == p[j]) {
					add_edge(2*j-1, 2*i, 0);
				} else {
					add_edge(2*i, 2*j-1, 0);
				}				
			}
		}
	}

	add_edge(0, 2*n+1, 0);

	sol -= spfa(0, 2*n+1, 2*n+2);

	cout << sol;
}