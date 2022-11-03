#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};

vector < vector < set < int > > > g, q;

vector < pair < int, int > > ans;

vector< vector<int> > gr;
vector<int> used;

int timer;

void dfs(int v){
	used[v] = timer;
	for (int i : gr[v])
	if (!used[i])
		dfs(i);
	return;
}

vector<set<int>> get(int v){
	used[v] = 1;
	timer = 0;
	for (int i : gr[v]){
		timer++;
		dfs(i);
	}
	vector< set<int> > res(timer);
	for (int i = 0; i < gr.size(); i++){
		if (i != v && used[i])
			res[used[i] - 1].insert(i);
	}
	return res;
}


vector < int > f(string s) {
	vector < int > res;
	s += ' ';
	int cur = 0;
	for (char c : s) {
		if (c < '0' || c > '9') {
			res.push_back(cur);
			cur = 0;
		}
		else {
			cur = cur * 10 + c - '0';
		}
	}
	return res;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	g.resize(n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector < int > cur = f(s);
		int pn = 0;
		while (pn < cur.size()) {
			int x = cur[pn];
			g[i].emplace_back();
			for (int j = 0; j < x; j++, pn++)
				g[i][g[i].size() - 1].insert(cur[pn + 1] - 1);
			pn++;
		}
	}

	q = g;

	for (int i = 0; i < n - 1; i++) {
		int st = -1;
		for (int j = 0; j < n && st == -1; j++) {
			for (auto &k : g[j]) {
				if (k.size() == 1) {
					st = *k.begin();
					ans.push_back({ j, st });
					break;
				}
			}
		}

		if (st == -1) {
			cout << -1;
			return 0;
		}

		for (int j = 0; j < n; j++) {
			for (auto &k : g[j]) {
				k.erase(st);
			}
			for (int k = 0; k < (int)g[j].size(); k++) {
				if (g[j][k].empty()) {
					g[j].erase(g[j].begin() + k);
					k--;
				}
			}
		}
	}

	

	//cout << n - 1 << '\n';

	gr.resize(n);
	for (auto i : ans){
		gr[i.first].push_back(i.second);
		gr[i.second].push_back(i.first);
	}
	bool is = 1;
	for (int i = 0; i < n; i++){
		used.assign(n, 0);
		auto qr = get(i);
		vector< vector<int> > a(q[i].size()), b(qr.size());
		for (int j = 0; j < q[i].size(); j++)
			a[j] = vector < int >(q[i][j].begin(), q[i][j].end());
		for (int j = 0; j < qr.size(); j++)
			for (auto z : qr[j])
				b[j].push_back(z);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		is &= (a == b);
	}
	if (is){
		cout << n - 1 << '\n';
		for (auto i : ans) {
			cout << i.first + 1 << ' ' << i.second + 1 << '\n';
		}
	}
	else{
		cout << "-1";
	}

	return 0;
}