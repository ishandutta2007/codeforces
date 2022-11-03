




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
#include <random>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"



int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	int n = (int)s.length();
	vector< vector<int> > pos(26);
	for (int i = 0; i < s.length(); i++) {
		pos[s[i] - 'a'].push_back(i);
	}
	s += s;
	long double ans = 0;
	for (int i = 0; i < 26; i++) {
		long double mx = 0;
		for (int j = 0; j < n; j++) {
			vector<int> cnt(26);
			for (int k = 0; k < pos[i].size(); k++)
				cnt[s[pos[i][k] + j] - 'a']++;
			long double res = 0;
			for (int k = 0; k < 26; k++)
				if (cnt[k] == 1)
					res += 1;
			mx = max(mx, res);
		}
		ans += mx;
	}

	cout << fixed << setprecision(15) << ans / n;
	return 0;
}