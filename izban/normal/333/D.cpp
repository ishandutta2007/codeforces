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
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int a[maxn][maxn];
bool was[maxn][maxn];

bool f(int x) {
	memset(was, 0, sizeof(was));
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) if (a[i][j] >= x) v.push_back(j);
		for (int j = 0; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				if (was[v[j]][v[k]]) return 1;
				was[v[j]][v[k]] = 1;
			}
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

		int l = 0, r = 1e9;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (f(m)) l = m;
			else r = m;
		}
		if (f(r)) cout << r << endl;
		else cout << l << endl;
	}

	return 0;
}