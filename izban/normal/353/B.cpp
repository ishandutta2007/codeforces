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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
int cnt[maxn];
int ans[maxn];
int was[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < 2 * n; i++) cin >> a[i];
		memset(cnt, 0, sizeof(cnt));
		memset(was, 0, sizeof(was));

		for (int i = 0; i < 2 * n; i++) cnt[a[i]]++;
		
		vector<int> v[2];
		v[0] = v[1] = vector<int>();
		for (int i = 0; i < 2 * n; i++) {
			if (cnt[a[i]] > 1) {
				if (was[a[i]] == 0) v[0].push_back(i), was[a[i]] = 1, a[i] = -1;
				else if (was[a[i]] == 1) v[1].push_back(i), was[a[i]] = 2, a[i] = -1;
			}
		}
		int cur = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (a[i] != -1 && cnt[a[i]] == 1) {
				v[(cur++) % 2].push_back(i);
			}
		}
		cout << v[0].size() * v[1].size() << endl;

		for (int i = 0; i < 2 * n; i++) {
			if (a[i] != -1 && cnt[a[i]] > 1) {
				if (v[0].size() < n) v[0].push_back(i);
				else v[1].push_back(i);
			}
		}
		for (int i = 0; i < n; i++) ans[v[0][i]] = 1;
		for (int i = 0; i < n; i++) ans[v[1][i]] = 2;
		for (int i = 0; i < 2 * n; i++) cout << ans[i] << " \n"[i + 1 == 2 * n];
	}

	return 0;
}