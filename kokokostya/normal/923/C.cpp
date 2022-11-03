





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

struct vert {
	int sz;
	int to[2];
};

vert nw;
int sz = 0;
vector<vert> b;

void add(int v, int len, int a) {
	b[v].sz++;
	if (len == -1) {
		return;
	}
	int x = (a & (1 << len)) ? 1 : 0;
	if (b[v].to[x] == -1) {
		b[v].to[x] = sz++;
		b.push_back(nw);
	}
	add(b[v].to[x], len - 1, a);
}

int get(int v, int len, int a) {
	b[v].sz--;
	if (len == -1) {
		return a;
	}
	int x = (a & (1 << len)) ? 1 : 0;
	if (b[v].to[x] != -1 && b[b[v].to[x]].sz) {
		a &= ~(1 << len);
		return get(b[v].to[x], len - 1, a);
	}

	a |= 1 << len;
	return get(b[v].to[x ^ 1], len - 1, a);
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	nw.sz = 0;
	nw.to[0] = -1, nw.to[1] = -1;
	b.push_back(nw);
	sz++;
	for (int i = 0; i < n; i++)
		add(0, 29, p[i]);
	for (int i = 0; i < n; i++) {
		cout << get(0, 29, a[i]) << ' ';
	}

	return 0;
}