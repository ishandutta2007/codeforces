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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = -1;

vector<int> e[26];
int vis[26], pos[26];
vector<int> vct;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int i = 0; i < (int)e[v].size(); i++) dfs(e[v][i]);
	pos[v] = vct.size();
	vct.push_back(v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < 26; i++) e[i].clear();

		bool fail = 0;
		for (int i = 0; i + 1 < n; i++) {
			bool curfail = a[i].length() > a[i + 1].length();
			for (int j = 0; j < min((int)a[i].length(), (int)a[i + 1].length()); j++) {
				if (a[i + 1][j] != a[i][j]) {
					e[a[i][j] - 'a'].push_back(a[i + 1][j] - 'a');
					curfail = 0;
					break;
				}
			}
			fail |= curfail;
		}
		vct.clear();
		for (int i = 0; i < 26; i++) vis[i] = 0;
		for (int i = 0; i < 26; i++) dfs(i);

		bool ok = 1;
		for (int i = 0; i < 26; i++) for (int j = 0; j < (int)e[vct[i]].size(); j++) ok &= pos[e[vct[i]][j]] < i;

		if (!ok || fail) {
			cout << "Impossible" << endl;
			continue;
		}
		for (int i = 25; i >= 0; i--) cout << (char)('a' + vct[i]);
		cout << endl;
	}

	return 0;
}