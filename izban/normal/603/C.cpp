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

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int grSlow(int n, int k) {
	k %= 2;
	//for (int k = 1; k <= 2; k++) {
	int N = n;
	vector<int> gr(N + 1);
	for (int i = 1; i <= N; i++) {
		vector<int> vct;
		vct.push_back(gr[i - 1]);
		if (i % 2 == 0) {
			if (k % 2 == 0) vct.push_back(0);
			else vct.push_back(gr[i / 2]);
		}
		sort(vct.begin(), vct.end());
		for (int x = 0;; x++) {
			if (find(vct.begin(), vct.end(), x) == vct.end()) {
				gr[i] = x;
				break;
			}
		}
	}
	return gr[n];
		//for (int i = 0; i <= N; i++) cout << gr[i] << " \n"[i == N];
	//}
}

int grFast(int n, int k) {
	if (k % 2 == 1) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 0;
		if (n == 3) return 1;
		if (n == 4) return 2;
		if (n % 2 == 1) return 0;
		int x = n;
		int cnt = 0;
		while (x % 2 == 0) x /= 2, cnt++;
		if (x == 1 && cnt % 2 == 0) return 2;
		if (x == 3 && cnt % 2 == 1) return 2;
		if (x != 1 && x != 3 && cnt % 2 == 0) return 2;
		return 1;
	}
	else {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		return (n - 1) % 2;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	/*int T = 30;
	for (int n = 1; n <= T; n++) {
		cerr << n << endl;
		for (int k = 1; k <= T; k++) {
			assert(grSlow(n, k) == grFast(n, k));
		}
	}
	return 0;*/

	int n, k;
	while (cin >> n >> k) {
		vector<int> a(n);
		int xr = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			xr ^= grFast(a[i], k);
		}
		cout << (xr == 0 ? "Nicky" : "Kevin") << endl;
	}

	return 0;
}