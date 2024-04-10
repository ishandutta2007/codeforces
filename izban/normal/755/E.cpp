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
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

void print(vector<pair<int, int> > e) {
	if (e.empty()) {
		printf("%d\n", -1);
		return;
	}
	printf("%d\n", (int)e.size());
	for (int i = 0; i < (int)e.size(); i++) {
		printf("%d %d\n", e[i].first + 1, e[i].second + 1);
	}
}

vector<pair<int, int> > solve(int n, int k) {
	// k=1 -> clique
	if (k == 1) {
		return vector<pair<int, int> >();
	}
	// impossible, min(d1, d2) <= 3
	if (k > 3) {
		return vector<pair<int, int> >();
	}
	// n = 3 -> 3 edges, not enough
	if (n < 4) {
		return vector<pair<int, int> >();
	}
	if (k == 2) {
		// 3 + 3 = 6 edges
		if (n == 4) {
			return vector<pair<int, int> >();
		}
		vector<pair<int, int> > edges;
		for (int i = 0; i < n - 1; i++) {
			edges.push_back(make_pair(i, i + 1));
		}
		return edges;
	}
	vector<pair<int, int> > edges;
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 3; j++) {
			edges.push_back(make_pair(i, j));
		}
		edges.push_back(make_pair(i, n - 3));
	}
	for (int i = n - 3; i < n - 1; i++) {
		edges.push_back(make_pair(i, i + 1));
	}
	return edges;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (cin >> n >> k) {
		print(solve(n, k));
	}

	return 0;
}