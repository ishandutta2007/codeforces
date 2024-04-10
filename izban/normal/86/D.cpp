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

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000007;
const int k = 600;

int n, m;
int a[maxn], l[maxn], r[maxn];
int curl, curr;
ll cur, ans[maxn];
int cnt[1 << 20];

vector<pair<pair<int, int>, int> > e[maxn / k];

void decR() {
	cur -= 1LL * cnt[a[curr]] * cnt[a[curr]] * a[curr];
	cnt[a[curr]]--;
	cur += 1LL * cnt[a[curr]] * cnt[a[curr]] * a[curr];
	curr--;
}

void incR() {
	curr++;
	cur -= 1LL * cnt[a[curr]] * cnt[a[curr]] * a[curr];
	cnt[a[curr]]++;
	cur += 1LL * cnt[a[curr]] * cnt[a[curr]] * a[curr];
}

void decL() {
	curl--;
	cur -= 1LL * cnt[a[curl]] * cnt[a[curl]] * a[curl];
	cnt[a[curl]]++;
	cur += 1LL * cnt[a[curl]] * cnt[a[curl]] * a[curl];
}

void incL() {
	cur -= 1LL * cnt[a[curl]] * cnt[a[curl]] * a[curl];
	cnt[a[curl]]--;
	cur += 1LL * cnt[a[curl]] * cnt[a[curl]] * a[curl];
	curl++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < m; i++) scanf("%d%d", &l[i], &r[i]);

		for (int i = 0; i <= n / k; i++) e[i].clear();
		for (int i = 0; i < m; i++) e[l[i] / k].push_back(make_pair(make_pair(r[i] - 1, l[i] - 1), i));

		memset(cnt, 0, sizeof(cnt));
		curl = 0, curr = -1;
		cur = 0;
		for (int i = 0; i <= n / k; i++) {
			sort(e[i].begin(), e[i].end());
			for (int j = 0; j < e[i].size(); j++) {
				while (curr > e[i][j].first.first) decR();
				while (curr < e[i][j].first.first) incR();
				while (curl < e[i][j].first.second) incL();
				while (curl > e[i][j].first.second) decL();
				ans[e[i][j].second] = cur;
			}
		}
		for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
	}

	return 0;
}