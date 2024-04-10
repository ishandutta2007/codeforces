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
string s[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> s[i];
		vector<int> row(n, 0), col(n, 0);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) row[i] += s[i][j] == 'E', col[j] += s[i][j] == 'E';
		bool bad = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (row[i] == n && col[j] == n && !bad) {
			bad = 1;
		}
		if (bad) {
			cout << -1 << endl;
			continue;
		}

		bool fl = 0;
		for (int i = 0; i < n; i++) fl |= row[i] == n;

		vector<pair<int, int> > ans;
		if (!fl) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (s[i][j] != 'E') {
						ans.push_back(make_pair(i + 1, j + 1));
						break;
					}
				}
			}
		} else {
			for (int j = 0; j < n; j++) {
				for (int i = 0; i < n; i++) {
					if (s[i][j] != 'E') {
						ans.push_back(make_pair(i + 1, j + 1));
						break;
					}
				}
			}
		}
		assert(ans.size() == n);
		for (int i = 0; i < n; i++) cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}