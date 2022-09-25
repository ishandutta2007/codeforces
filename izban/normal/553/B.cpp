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

const double eps = 1e-9;

void work() {
	for (int n = 1; n <= 6; n++) {
		vector<int> p;
		for (int i = 0; i < n; i++) p.push_back(i);

		do {
			vector<char> used(n, 0);
			vector<vector<int> > c;
			vector<int> b;
			for (int i = n - 1; i >= 0; i--) {
				if (used[i]) continue;
				int j = i;
				vector<int> a;
				do {
					a.push_back(j);
					used[j] = 1;
					j = p[j];
				} while (j != i);
				c.push_back(a);
			}
			sort(c.begin(), c.end());
			for (int i = 0; i < (int)c.size(); i++) for (int j = 0; j < (int)c[i].size(); j++) b.push_back(c[i][j]);

			if (b == p) {
				for (int i = 0; i < n; i++) cout << b[i] << " \n"[i + 1 == n];
			}
		} while (next_permutation(p.begin(), p.end()));
		cout << endl;
	}
}

const int MAXN = 64;

ll f[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//work();
	f[0] = f[1] = 1;
	for (int i = 2; i < MAXN; i++) f[i] = f[i - 1] + f[i - 2];

	int n;
	ll k;
	while (cin >> n >> k) {
		k--;
		vector<int> cur;
		for (int i = 0; i < n; i++) cur.push_back(i + 1);

		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int id = -1;
			if (k >= f[n - i - 1]) {
				k -= f[n - i - 1];
				id = 1;
			} else {
				id = 0;
			}
			ans.push_back(cur[id]);
			cur.erase(cur.begin() + id);
		}
		for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}

	return 0;
}