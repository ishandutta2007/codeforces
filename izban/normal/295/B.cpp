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

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
vector<vector<int> > d;
vector<int> x;
vector<ll> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		d.assign(n, vector<int>(n, inf));
		x.assign(n, -1);
		ans.assign(n, -1);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &d[i][j]);
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		
		for (int I = n - 1; I >= 0; I--) {
			int k = x[I] - 1;
			ll res = 0;
			for (int i1 = n - 1; i1 >= I; i1--) {
				for (int j1 = n - 1; j1 >= I; j1--) {
					int i = x[i1] - 1, j = x[j1] - 1;
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					res += d[i][j];
				}
			}
			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			ans[I] = res;
		}
		for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
	}

	return 0;
}