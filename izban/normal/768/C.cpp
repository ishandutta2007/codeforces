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
const int MAXN = 1024;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k, x;
	while (scanf("%d%d%d", &n, &k, &x) == 3) {
		vector<int> cnt(MAXN);
		vector<int> ncnt(MAXN);
		for (int i = 0; i < n; i++) {
			int z;
			scanf("%d", &z);
			cnt[z]++;
		}
		for (int it = 0; it < k; it++) {
			for (int i = 0; i < MAXN; i++) ncnt[i] = 0;
			int p = 0;
			for (int i = 0; i < MAXN; i++) {
				int odd = (cnt[i] + 1) / 2;
				int even = cnt[i] / 2;
				if (p) swap(odd, even);
				ncnt[i ^ x] += odd;
				ncnt[i] += even;
				p = (p + cnt[i]) & 1;
			}
			cnt = ncnt;
		}
		vector<int> a(n);
		auto fillA = [&] {
			int j = 0;
			for (int i = 0; i < MAXN; i++) {
				while (cnt[i] > 0) {
					a[j++] = i;
					cnt[i]--;
				}
			}
		};
		fillA();
		cout << a[n - 1] << " " << a[0] << endl;
	}

	return 0;
}