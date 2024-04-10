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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> b[i];

		vector<int> c(n);
		vector<int> ans;
		while (1) {
			int v = -1;
			for (int i = 0; i < n; i++) if (b[i] == c[i]) {
				v = i;
				break;
			}
			if (v == -1) break;

			ans.push_back(v);
			for (int i = 0; i < n; i++) if (a[v][i] == '1') c[i]++;
		}

		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] + 1 << " \n"[i + 1 == (int)ans.size()];
	}

	return 0;
}