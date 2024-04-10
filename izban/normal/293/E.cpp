#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
int n, l, w;
ll ans;

struct magic;

struct tree {
	int n;
	int addL, addW;
	vector<pair<int, int> > a;
	vector<vector<int> > t;
	
	tree() {
		n = 0;
		addL = 0;
		addW = 0;
	}

	void add(int dL, int dW) {
		addL += dL;
		addW += dW;
	}

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = vector<int>(1, a[tl].second);
			return;
		}
		int tm = (tl + tr) >> 1;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
		merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
	}

	int size() {
		return n;
	}


	void doquery(int v, int tl, int tr, magic * cur);
	void doqueries(magic * cur);
	void transfer(int v, int tl, int tr, magic * cur);
	void transfer(magic * cur);

	void transfer(int v, int tl, int tr, vector<pair<int, int> > &cur) {
		if (tl == tr) {
			int cx = a[tl].first + addL, cy = a[tl].second + addW;
			cur.push_back(make_pair(cx, cy));
			return;
		}
		int tm = (tl + tr) >> 1;
		transfer(v * 2, tl, tm, cur);
		transfer(v * 2 + 1, tm + 1, tr, cur);
	}

	void transfer(vector<pair<int, int> > &cur) {
		transfer(1, 0, n - 1, cur);
		n = 0;
		a.clear();
		t.clear();
	}

	int get(int v, int tl, int tr, int l, int r, int x) {
		if (l > r) return 0;
		if (tl == l && tr == r) {
			int k = lower_bound(t[v].begin(), t[v].end(), x + 1) - t[v].begin();
			k--;
			//if (k == t[v].size() || t[v][k] > x) k--;
			return k + 1;
		}
		int tm = (tl + tr) >> 1;
		return
			get(v * 2, tl, tm, l, min(r, tm), x) + 
			get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
	}

	int get(int l, int w) {
		l -= addL; w -= addW;
		int k = lower_bound(a.begin(), a.end(), make_pair(l, (int)2e9)) - a.begin();
		k--;
		//if (k == n || a[k].first > l) k--;
		if (k == -1) return 0;
		return get(1, 0, n - 1, 0, k, w);
	}

	void build(vector<pair<int, int> > V) {
		a = V;
		n = a.size();
		t.assign(2 * n, vector<int>(0));
		build(1, 0, n - 1);
	}
};

struct magic {
	vector<tree*> v;

	int size() {
		int res = 0;
		for (int i = 0; i < v.size(); i++)
			res += v[i]->size();
		return res;
	}

	void add(int dl, int dw) {
		for (int i = 0; i < v.size(); i++)
			v[i]->add(dl, dw);
	}

	void doqueries(magic * cur) {
		for (int i = 0; i < v.size(); i++)
			v[i]->doqueries(cur);
	}

	void transfer(magic * cur) {
		for (int i = 0; i < v.size(); i++)
			v[i]->transfer(cur);
	}

	void insert(int l, int w) {
		vector<pair<int, int> > vct(1, make_pair(l, w));
		int cur = 0;
		while (cur < v.size() && v[cur]->size() == vct.size()) {
			v[cur++]->transfer(vct);
		}
		sort(vct.begin(), vct.end());
		vector<tree*> nv;
		tree* tr = new tree;
		tr->build(vct);
		nv.push_back(tr);
		for (int i = 0; i < v.size(); i++) if (v[i]->size() > tr->size()) nv.push_back(v[i]);
		v = nv;
	}

	void get(int l, int w) {
		for (int i = 0; i < v.size(); i++)
			ans += v[i]->get(l, w);
	}
};

void tree::doquery(int v, int tl, int tr, magic * cur) {
	if (tl == tr) {
		int cx = a[tl].first + addL, cy = a[tl].second + addW;
		cur->get(l - cx, w - cy);
		return;
	}
	int tm = (tl + tr) >> 1;
	doquery(v * 2, tl, tm, cur);
	doquery(v * 2 + 1, tm + 1, tr, cur);
}

void tree::doqueries(magic * cur) {
	doquery(1, 0, n - 1, cur);
}

void tree::transfer(int v, int tl, int tr, magic * cur) {
	if (tl == tr) {
		int cx = a[tl].first + addL, cy = a[tl].second + addW;
		cur->insert(cx, cy);
		return;
	}
	int tm = (tl + tr) >> 1;
	transfer(v * 2, tl, tm, cur);
	transfer(v * 2 + 1, tm + 1, tr, cur);
}

void tree::transfer(magic * cur) {
	transfer(1, 0, n - 1, cur);
	n = 0;
	a.clear();
	t.clear();
}

vector<vector<pair<int, int> > > e;
magic str[maxn];


magic * dfs(int v) {
	magic * cur = &str[v];
	for (int i = 0; i < e[v].size(); i++) {
		magic * nw = dfs(e[v][i].first);
		nw->add(1, e[v][i].second);
		if (nw->size() > cur->size()) swap(cur, nw);
		nw->doqueries(cur);
		nw->transfer(cur);
	}
	cur->get(l, w);
	cur->insert(0, 0);
	return cur;
}

int cnt[maxn];

bool cmp(pair<int, int> i, pair<int, int> j) {
	return cnt[i.first] < cnt[j.first];
}

int DFS(int v) {
	cnt[v] = 1;
	for (int i = 0; i < e[v].size(); i++)
		cnt[v] += DFS(e[v][i].first);
	sort(e[v].begin(), e[v].end(), cmp);
	return cnt[v];
}

ll solve() {
	ans = 0;
	memset(cnt, 0, sizeof(cnt));
	DFS(1);
	for (int i = 1; i <= n; i++)
		str[i] = magic();
	dfs(1);
	return ans;
}

vector<pair<int, int> > dfsslow(int v) {
	vector<pair<int, int> > cur;
	for (int i = 0; i < e[v].size(); i++) {
		vector<pair<int, int> > nw = dfsslow(e[v][i].first);
		for (int k = 0; k < nw.size(); k++) {
			nw[k].first += 1;
			nw[k].second += e[v][i].second;
		}
		for (int j = 0; j < cur.size(); j++) {
			for (int k = 0; k < nw.size(); k++) {
				if (cur[j].first + nw[k].first <= l && cur[j].second + nw[k].second <= w)
					ans++;
			}
		}
		for (int k = 0; k < nw.size(); k++)
			cur.push_back(nw[k]);
	}
	for (int i = 0; i < cur.size(); i++) ans += cur[i].first <= l && cur[i].second <= w;
	cur.push_back(make_pair(0, 0));
	return cur;
}

ll slowsolve() {
	ans = 0;
	dfsslow(1);
	return ans;
}

void reading() {
	scanf("%d%d%d", &n, &l, &w);
	e.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int p, w;
		scanf("%d%d", &p, &w);
		e[p].push_back(make_pair(i, w));
	}
}

void gen() {
	n = rand() % 300 + 1;
	e.assign(n + 1, vector<pair<int, int> >(0));
	w = rand() % 300;
	l = rand() % 300 + 1;
	for (int i = 2; i <= n; i++) {
		e[rand() % (i - 1) + 1].push_back(make_pair(i, rand() % 300));
	}
}

void stress() {
	if (1) return;
	for (int it = 0; it < 20000; it++) {
		gen();
		if (slowsolve() != solve()) {
			cout << n << " " << l << " " << w << endl;
			vector<pair<int, int> > edges(n + 1);
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < e[i].size(); j++)
					edges[e[i][j].first] = make_pair(i, e[i][j].second);
			for (int i = 2; i <= n; i++)
				cout << edges[i].first << " " << edges[i].second << endl;
			cout << endl;
			cout << solve() << endl << slowsolve() << endl;
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stress();
	reading();
	cout << solve() << endl;
	//cout << slowsolve() << endl;

	return 0;
}