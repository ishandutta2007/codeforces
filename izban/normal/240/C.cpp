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

using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")


const int maxn = 1 << 10;

int ans, n;
vector<int> e[maxn];

void rec(int x, int l, int r) {
	if (l == r) return;
	if (l + 1 == r) {
		e[x].push_back(l);
		ans = max(ans, x + 1);
		return;
	}
	int m = (l + r) >> 1;
	for (int i = l; i <= m; i++)
		e[x].push_back(i);
	rec(x + 1, l, m);
	rec(x + 1, m + 1, r);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n;
	rec(0, 1, n);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%d ", (int)e[i].size());
		for (int j = 0; j < e[i].size(); j++)
			printf("%d ", e[i][j]);
		printf("\n");
	}
	return 0;
}