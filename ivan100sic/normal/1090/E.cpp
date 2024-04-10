#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct par {
	int x, y;
};

par p[8][8];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

basic_string<par> put(par u, par v) {
	memset(p, 255, sizeof(p));
	p[v.x][v.y] = {-2, -2};
	queue<par> q;
	q.push(v);
	while (q.size()) {
		par t = q.front(); q.pop();
		for (int i=0; i<8; i++) {
			par s = {t.x + dx[i], t.y + dy[i]};
			if (s.x < 0 || s.x > 7 || s.y < 0 || s.y > 7)
				continue;
			if (p[s.x][s.y].x == -1) {
				p[s.x][s.y] = t;
				q.push(s);
			}
		}
	}
	basic_string<par> put;
	for (par t = u; t.x != -2; t = p[t.x][t.y])
		put += t;
	return put;
}

basic_string<pair<par, par>> sol;

int h[8][8];

void swap2(par a, par b) {
	if (h[a.x][a.y] == h[b.x][b.y])
		return;

	if (h[b.x][b.y])
		swap(a, b);

	sol += {a, b};
	swap(h[a.x][a.y], h[b.x][b.y]);
}

void push_left(basic_string<par> v) {
	for (int i=(int)v.size()-2; i>=0; i--) {
		swap2(v[i+1], v[i]);
	}
}

void push_right(basic_string<par> v) {
	for (int i=0; i<(int)v.size()-1; i++) {
		swap2(v[i+1], v[i]);
	}
}

void swap_path(par a, par b) {
	if (a.x == b.x && a.y == b.y)
		return;
	auto p = put(a, b);
	push_right(p.substr(0, p.size()-1));
	swap2(p[p.size() - 2], b);
	push_left(p.substr(0, p.size()-1));
}

void pr(par a) {
	cout << (char)(a.x + 'a') << (char)(a.y + '1');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		h[s[0] - 'a'][s[1] - '1'] = 1;
	}

	for (int i=0; i<n; i++) {
		int x = i % 8;
		int y = i / 8;

		if (h[x][y])
			continue;

		for (int j=63; j>=0; j--) {
			int xt = j % 8;
			int yt = j / 8;
			if (h[xt][yt]) {
				swap_path({x, y}, {xt, yt});
				break;
			}
		}
	}

	cout << sol.size() << '\n';
	for (auto q : sol) {
		pr(q.first);
		cout << '-';
		pr(q.second);
		cout << '\n';
	}
}