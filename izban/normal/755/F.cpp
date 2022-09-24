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
#include <bitset>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << 20;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

pair<int, int> solve(vector<int> a, int w) {
	int n = a.size();
	vector<char> was(n);
	vector<int> cycles;
	for (int i = 0; i < n; i++) {
		if (was[i]) continue;
		int v = i;
		int cur = 0;
		while (!was[v]) {
			was[v] = 1;
			cur++;
			v = a[v];
		}
		cycles.push_back(cur);
	}

	w = n - w;

	int ansMin = 0, ansMax = 0;

	vector<int> cnt(3);
	for (int i = 0; i < (int)cycles.size(); i++) {
		int x = cycles[i];
		if (x % 2 == 0) {
			cnt[0] += x / 2;
			cnt[2] += x / 2;
		}
		else {
			cnt[0] += x / 2;
			cnt[1] += 1;
			cnt[2] += x / 2;
		}
	}
	int ww = w;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			if (ww > 0) {
				ansMin += i;
				ww--;
			}
		}
	}

	vector<int> cntC(n + 1, 0);
	for (int i = 0; i < (int)cycles.size(); i++) {
		cntC[cycles[i]]++;
	}

	bitset<MAXN> dp;
	dp[0] = 1;
	for (int i = 0; i <= n; i++) {
		if (cntC[i] != 0) {
			vector<int> o;
			int sum = 0;
			int j = 0;
			while (sum + (1 << j) <= cntC[i]) {
				sum += 1 << j;
				o.push_back(j++);
			}
			while (j >= 0) {
				if (sum + (1 << j) <= cntC[i]) {
					o.push_back(j);
					sum += 1 << j;
				}
				j--;
			}
			for (int x : o) {
				dp |= dp << (i * (1 << x));
			}
		}
	}
	if (dp[w]) ansMax = w;
	else ansMax = w - 1;
	
	return make_pair(n - ansMax, n - ansMin);
}

void test() {
	vector<int> a;
	for (int i = 2; a.size() <= 1e6; i++) {
		int x = a.size();
		for (int j = 0; j < i - 1; j++) a.push_back(x + j + 1);
		a.push_back(x);
	}
	auto o = solve(a, (int)a.size() / 2);
	cerr << o.first << " " << o.second << endl;
	cerr << clock() / (double)CLOCKS_PER_SEC << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//test();

	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
		}

		auto o = solve(a, k);
		printf("%d %d\n", o.first, o.second);
	}

	return 0;
}