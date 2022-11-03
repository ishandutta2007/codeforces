


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

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int MX = 1e5 + 7;
vector<int> g[MX];
vector<int> used(MX);

bool cycle(int v) {
	used[v] = 1;

	for (int i : g[v]) {
		if (used[i] == 1)
			return 1;
		if (used[i] == 0) {
			if (cycle(i))
				return 1;
		}
	}


	used[v] = 2;
	return 0;
}

int dp[MX][2];
int nxt[MX][2];
bool us[MX][2];

bool wn(int v, int tp) {

	us[v][tp] = 1;
	if (tp == 1) {
		if (g[v].size() == 0)
			return dp[v][tp] = -1;

		for (int i : g[v]) {
			if (!dp[i][tp ^ 1]) {
				if (!us[i][tp ^ 1])
					wn(i, tp ^ 1);
			}
		}

		for (int i : g[v]) {
			if (dp[i][tp ^ 1] == -1) {
				nxt[v][tp] = i;
				return dp[v][tp] = 1;
			}
		}
		return dp[v][tp] = -1;


	}
	else {
		if (g[v].size() == 0)
			return dp[v][tp] = -1;


		for (int i : g[v]) {
			if (!dp[i][tp ^ 1]) {
				if (!us[i][tp ^ 1])
					wn(i, tp ^ 1);
			}
		}

		for (int i : g[v]) {
			if (dp[i][tp ^ 1] == 1) {
				nxt[v][tp] = i;
				return dp[v][tp] = -1;
			}
		}
		return dp[v][tp] = 1;

	
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++) {
			int a;
			cin >> a;
			a--;
			g[i].push_back(a);
		}
	}
	int s;
	cin >> s;
	s--;

	int res = 0;
	if (cycle(s))
		res = 1;

	wn(s, 1);
	if (dp[s][1] == 1) {
		cout << "Win\n";
		cout << s + 1 << ' ';
		int tp = 1;
		while (!g[s].empty()) {
			s = nxt[s][tp];
			cout << s + 1 << ' ';
			tp ^= 1;
		}
		return 0;
	}


	if (res == 1)
		cout << "Draw";
	else
		cout << "Lose";

	return 0;
}