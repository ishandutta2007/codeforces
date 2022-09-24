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
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

map<pair<int, vector<int> >, int> mp;

int mex(vector<int> a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int ans = 0;
	while (ans < (int)a.size() && a[ans] == ans) ans++;
	return ans;
}

int gr(int n, vector<int> v) {
	pair<int, vector<int> > o = make_pair(n, v);
	if (mp.count(o)) return mp[o];
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (!binary_search(v.begin(), v.end(), i)) {
			vector<int> nv = v;
			nv.push_back(i);
			int j = (int)nv.size() - 1;
			while (j > 0 && nv[j] < nv[j - 1]) {
				swap(nv[j], nv[j - 1]);
				j--;
			}
			res.push_back(gr(n - i, nv));
		}
	}
	return mp[o] = mex(res);
}
const int g[61] = { 0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	/*const int N = 60;
	vector<int> o(N + 1);
	for (int i = 1; i <= N; i++) {
		o[i] = gr(i, vector<int>());
	}

	cout << "const int g[61] = {";
	for (int i = 0; i <= N; i++) cout << o[i] << ",}"[i == N];
	cout << ";" << endl;
	return 0;*/

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		int xr = 0;
		for (int i = 0; i < n; i++) xr ^= g[a[i]];
		if (xr == 0) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}