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




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	while (cin >> n) {
		vector<int> a(n);
		vector<vector<int> > b(1e5 + 1);
		for (int i = 0; i < n; i++) cin >> a[i], b[a[i]].push_back(i);

		vector<pair<int, int> > ans;
		for (int x = 1; x <= 1e5; x++) {
			int cur = -1;
			for (int i = 0; i < b[x].size(); i++) {
				if (cur == -1) cur = 0;
				else if (cur == 0) cur = b[x][i] - b[x][i - 1];
				else if (cur != b[x][i] - b[x][i - 1]) cur = -2;
			}
			if (cur >= 0) ans.push_back(make_pair(x, cur));
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}