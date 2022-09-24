#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << 20;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

string inttostr(int x) {
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}

vector<string> g(vector<int> a) {
	vector<string> ans;
	for (int i = 0; i < (int)a.size(); i++) {
		ans.push_back(inttostr(a[i]));
	}
	return ans;
}

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll inv(ll x, ll m) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	return ((1 - inv(m % x, x) * m) / x + m);
}

pair<ll, ll> solve(pair<ll, ll> _a, pair<ll, ll> _b) {
	ll a1 = _a.first;
	ll a2 = _b.first;
	ll p1 = _a.second;
	ll p2 = _b.second;

	ll x1 = a1;
	ll x2 = (a2 - x1) * inv(p1 % p2, p2) % p2; if (x2 < 0) x2 += p2;

	ll x = x1 + x2 * p1;
	ll y = lcm(p1, p2);
	return make_pair(x, y);
}

pair<ll, ll> merge(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	ll g = gcd(a.second, b.second);
	if (a.first % g != b.first % g) return make_pair(0, -1);

	pair<ll, ll> na = make_pair(a.first / g, a.second / g);
	pair<ll, ll> nb = make_pair(b.first / g, b.second / g);

	pair<ll, ll> nc = solve(na, nb);
	nc = make_pair(nc.first * g + a.first % g, nc.second * g);

	return nc;
}

struct Stack {
	pair<ll, ll> a[MAXN];
	pair<ll, ll> c[MAXN];
	int sz;

	Stack() {
		a[0] = make_pair(0, 1);
		sz = 1;
	}

	int size() const {
		return sz;
	}

	bool empty() const {
		return size() == 1;
	}

	bool push(const pair<ll, ll> &b) {
		pair<ll, ll> nw = merge(a[sz - 1], b);
		if (nw.second == -1) return false;
		c[sz] = b;
		a[sz++] = nw;
		return true;
	}

	void pop() {
		sz--;
	}

	pair<ll, ll> top() const {
		return a[sz - 1];
	}

	void clear() {
		a[0] = make_pair(0, 1);
		sz = 1;
	}
};

struct Queue {
	Stack s1, s2;

	Queue() {}

	int size() const {
		return s1.size() + s2.size();
	}

	bool empty() const {
		return size() == 2;
	}

	bool push(const pair<ll, ll> &b) {
		pair<ll, ll> cur = merge(s1.top(), s2.top());
		pair<ll, ll> nw = merge(cur, b);
		if (nw.second == -1) return false;
		s2.push(b);
		return true;
	}

	void pop() {
		if (s1.empty()) {
			while (!s2.empty()) {
				s1.push(s2.c[s2.sz - 1]);
				s2.pop();
			}
		}
		s1.pop();
	}

	void clear() {
		s1.clear();
		s2.clear();
	}
} q;

vector<string> solve(vector<vector<int> > a, int m) {
	int n = a.size();
	int maxSize = 0;
	for (int i = 0; i < n; i++) maxSize = max(maxSize, (int)a[i].size());

	if (maxSize == 1) {
		vector<int> b;
		for (int i = 0; i < n; i++) b.push_back(a[i % n][0]);

		vector<int> ans(m);
		for (int l = 0; l < n; l++) {
			int r = l;
			while (r + 1 < n && b[r + 1] == b[l]) r++;
			ans[b[l]] = max(ans[b[l]], r - l + 1);
			l = r;
		}

		vector<string> res = g(ans);
		return res;
	}

	vector<vector<pair<int, int> > > pos(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)a[i].size(); j++) {
			pos[a[i][j]].push_back(make_pair(i, j));
		}
	}

	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		vector<pair<int, int> > vct;

		for (int j = 0; j < (int)pos[i].size(); j++) {
			int nx = pos[i][j % (int)pos[i].size()].first;
			int ny = pos[i][j % (int)pos[i].size()].second;
			vct.push_back(make_pair(nx, ny));
		}

		q.clear();
		int r = -1;
		int cans = 0;
		for (int l = 0; l < (int)vct.size(); l++) {
			while (r < (int)vct.size() - 1 && vct[r + 1].first == vct[l].first + (r + 1 - l)) {
				pair<ll, ll> nw = make_pair(vct[r + 1].second, a[vct[r + 1].first].size());
				if (!q.push(nw)) break;
				r++;
			}
			cans = max(cans, r - l + 1);
			q.pop();
		}
		ans[i] = cans;
	}
	return g(ans);
}

void print(vector<string> a) {
	for (int i = 0; i < (int)a.size(); i++) printf("%s\n", a[i].c_str());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	bool first = 1;
	while (scanf("%d%d", &n, &m) == 2) {
		if (first) first = 0;
		else printf("\n");

		vector<vector<int> > a(n);
		for (int i = 0; i < n; i++) {
			int k;
			scanf("%d", &k);
			a[i].resize(k);
			for (int j = 0; j < k; j++) {
				scanf("%d", &a[i][j]);
				a[i][j]--;
			}
		}

		print(solve(a, m));
	}

	return 0;
}