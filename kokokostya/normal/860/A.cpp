

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

using namespace std;

#define LOCAL

set<char> q = { 'a', 'e', 'i', 'o', 'u' };

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("victory.in", "r", stdin);
	freopen("victory.out", "w", stdout);
#endif
	string s;
	cin >> s;
	int cnt = 0;
	bool is = 1;
	for (int i = 0; i < s.length(); i++) {
		cnt++;
		if (q.find(s[i]) != q.end()) {
			cnt = 0;
			is = 1;
		}
		else {
			if (i && cnt > 1 && s[i] != s[i - 1])
				is = 0;
			if (!is && cnt >= 3) {
				cout << ' ';
				is = 1;
				cnt = 1;
			}
		}
		cout << s[i];
	}
	
	return 0;
}