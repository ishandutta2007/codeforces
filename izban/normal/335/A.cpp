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
	string s;
	int k;
	while (cin >> s >> k) {
		int n = s.length(), o = 0;
		vector<pair<char, int> > cnt(26);
		vector<int> cnt2(26);
		for (int i = 0; i < n; i++) cnt[s[i] - 'a'].second++;
		for (int i = 0; i < 26; i++) cnt[i].first = (char)('a' + i), o += cnt[i].second > 0;
		if (o > k) {
			cout << -1 << endl;
			continue;
		}
		string ans = "";
		for (int i = 0; i < 26; i++) {
			if (cnt[i].second) ans += cnt[i].first, cnt2[i] = 1;
		}
		int res, cans;
		while (ans.length() <= k) {
			res = -1, cans = -1;
			for (int i = 0; i < 26; i++) {
				if (cnt[i].second && res < cnt[i].second / cnt2[i] + (cnt[i].second % cnt2[i] > 0)) {
					res = cnt[i].second / cnt2[i] + (cnt[i].second % cnt2[i] > 0);
					cans = i;
				}
			}
			if (ans.length() == k) break;
			ans += cnt[cans].first;
			cnt2[cans]++;
		}
		cout << res << " " << ans << endl;
	}

	return 0;
}