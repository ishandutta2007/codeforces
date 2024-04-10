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

string p, s, ooo;
int k;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (getline(cin, p)) {
		getline(cin, s);
		cin >> k; getline(cin, ooo);
		int blocks = p.length() / k;
		bool ok = 0;
		//int cnt = s.length() / max(1, blocks);
		vector<char> res(k, '1');
		for (int cnt = 1; cnt <= min(k, (int)s.length()); cnt++) {
			int mn = cnt * blocks + max(0, cnt - k + ((int)p.length() % k));
			int mx = cnt * blocks + min(cnt, (int)p.length() % k);
			if (!(mn <= s.length() && s.length() <= mx)) continue;
			if (cnt == 0) {
				//cout << 0 << endl;
				continue;
			}
			vector<int> lol(cnt, k); bool bad = 0;
			vector<vector<int> > can(k, vector<int>(cnt, 1));
			for (int i = 0; i < p.length(); i++) {
				for (int j = 0; j < cnt; j++) {
					int o = can[i % k][j];
					can[i % k][j] = can[i % k][j] && i / k * cnt + j < s.length() && (p[i] == s[i / k * cnt + j]);
					lol[j] -= o - can[i % k][j];
					if (!lol[j]) { bad = 1; break;}
				}
				if (bad) break;
			}
			if (bad) continue;
			int o = s.length() - blocks * cnt, w = p.length() % k;
			int O = o, sum = 0;

			vector<char> ans(k);
			for (int i = w - 1; i >= 0; i--) {
				if (o && can[i][o - 1]) {
					ans[i] = '1';
					o--;
					sum++;
				} else ans[i] = '0';
			}
			o = cnt;
			for (int i = k - 1; i >= w; i--) {
				if (o > O && can[i][o - 1]) {
					ans[i] = '1';
					o--;
					sum++;
				} else ans[i] = '0';
			}
		
			if (sum != cnt) {
				//cout << 0 << endl;
			}
			else {
				ok = 1;
				res = min(res, ans);
				//for (int i = 0; i < k; i++) cout << (char)ans[i];
				//cout << endl;
			}
		}
		if (!ok) cout << 0 << endl;
		else {
			for (int i = 0; i < k; i++) cout << (char)res[i];
			cout << endl;
		}
	}

	return 0;
}