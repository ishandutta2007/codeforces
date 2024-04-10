#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dist[505][5005];
int s, k;

basic_string<int> e[505][10];

void bfs() {
	queue<pair<int, int>> q;
	memset(dist, 255, sizeof(dist));
	q.push({0, s});
	dist[0][s] = 0;

	while (q.size()) {
		auto [r, s] = q.front(); q.pop();
		for (int i=0; i<=min(9, s); i++) {
			for (int x : e[r][i]) {
				if (dist[x][s-i] == -1) {
					dist[x][s-i] = dist[r][s] + 1;
					q.push({x, s-i});
				}
			}
		}
	}
}

void solve() {
	string sol;
	if (dist[0][0] == -1) {
		cout << "-1\n";
		return;
	}

	int rem = 0, sum = 0;
	while (1) {
		if (rem == 0 && sum == s)
			break;
		for (int i=0; i<10; i++) {
			if (dist[(10 * rem + i) % k][sum + i] == dist[rem][sum] - 1) {
				sol += (char)(i + 48);
				rem = (10 * rem + i) % k;
				sum += i;
				break;
			}
		}
	}
	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> s;

	for (int x=0; x<k; x++) {
		for (int j=0; j<10; j++) {
			int y = (10*x + j) % k;
			e[y][j] += x;
		}
	}
	
	bfs();
	solve();
}