



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int MX = 51;
char a[MX][MX];

vector< pair<int, int> > dir = { {-1, 0}, {0, -1}, {0, 1},{1, 0} };

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	int stx = 0, sty = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				stx = i, sty = j;
			}
		}
	int ans = 0;
	string s;
	cin >> s;
	do {
		int x = stx;
		int y = sty;
		for (int i = 0; i < s.length(); i++) {
			x += dir[s[i] - '0'].first;
			y += dir[s[i] - '0'].second;
			if (x < 0 || x >= n || y < 0 || y >= m)
				break;
			if (a[x][y] == '#')
				break;
			if (a[x][y] == 'E') {
				ans++;
				break;
			}
		}
	} while (next_permutation(dir.begin(), dir.end()));
	cout << ans;
	return 0;
}