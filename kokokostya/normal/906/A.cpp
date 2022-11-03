



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

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	set<char> s;
	vector<int> used(256, -1);
	for (int i = 0; i < 26; i++)
		s.insert('a' + i);
	int timer = -1;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		char c; string t;
		cin >> c >> t;
		if (c == '.') {
			for (char tc : t)
				s.erase(tc);
		}
		if (c == '?') {
			s.erase(t[0]);
			cnt++;
		}
		if (c == '!') {
			cnt++;
			for (char tc : t)
				used[tc] = i;
			for (int j = 0; j < 26; j++) {
				if (used[j + 'a'] != i)
					s.erase(j + 'a');
			}
		}
		if (s.size() == 1) {
			if (timer == -1)
				timer = cnt;
			
		}
	}
	if (timer == -1)
		cout << 0;
	else
		cout << cnt - timer;
	return 0;
}