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

	int n, m;
	while (cin >> n >> m) {
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j + 1 < m; j++) {
				vector<int> cnt(26);
				cnt[a[i][j] - 'a']++;
				cnt[a[i + 1][j] - 'a']++;
				cnt[a[i][j + 1] - 'a']++;
				cnt[a[i + 1][j + 1] - 'a']++;
				ans += cnt['a' - 'a'] && cnt['f' - 'a'] && cnt['c' - 'a'] && cnt['e' - 'a'];
			}
		}
		cout << ans << endl;
	}

	return 0;
}