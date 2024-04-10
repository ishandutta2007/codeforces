#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, put;
basic_string<int> e[505];

int blok[505];

int d[2][505];

void bfs(int x, int* d) {
	fill(d+1, d+n+1, -1);
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (!blok[y] && d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}

basic_string<int> dry_run(int x, int y) {
	basic_string<int> v;
	bfs(x, d[0]);
	bfs(y, d[1]);
	for (int i=1; i<=n; i++) {
		if (!blok[i]) {
			if (d[1][i] < d[0][i])
				v += i;
		}
	}
	return v;
}

void go(int x, int y) {
	auto v = dry_run(x, y);
	basic_string<int> cnt(n+1, 0);
	for (int x : v)
		cnt[x]++;

	for (int i=1; i<=n; i++)
		if (cnt[i] == 0)
			blok[i] = 1;
}

int best_candidate() {
	int idx = -1, best = n+1;
	for (int i=1; i<=n; i++) {
		if (blok[i])
			continue;

		int worst = 0;

		for (int j : e[i]) {
			if (blok[j])
				continue;
			worst = max(worst, (int)dry_run(i, j).size());
		}

		if (worst < best) {
			best = worst;
			idx = i;
		}
	}
	return idx;
}

void reset() {
	for (int i=1; i<=n; i++)
		blok[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> put;
	while (put--) {
		int m;
		cin >> m;
		basic_string<int> v;
		while (m--) {
			int x;
			cin >> x;
			v += x;
		}
		for (int i=0; i<(int)v.size()-1; i++) {
			int x = v[i];
			int y = v[i+1];
			e[x] += y;
			e[y] += x;
		}
	}

	int t = n;

	int x0 = best_candidate();
	map<int, int> level2map;

	for (int y : e[x0]) {
		go(x0, y);
		level2map[y] = best_candidate();
		reset();
	}

	map<basic_string<int>, int> cache;

	while (t--) {
		reset();
		basic_string<int> seq;
		while (1) {
			int x;
			if (cache.count(seq)) {
				x = cache[seq];
			} else {
				x = cache[seq] = best_candidate();
			}
			cout << x << '\n' << flush;
			string s;
			cin >> s;
			if (s == "FOUND") {
				break;
			} else {
				int y;
				cin >> y;
				go(x, y);
				seq += y;
			}
		}
	}
}