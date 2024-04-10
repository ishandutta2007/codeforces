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

const int maxn = 2600;
const int inf = 1000000007;
const int mod = 1000000007;

vector<vector<int> > dp;
pair<pair<int, int>, int> p[maxn][maxn];
string res;
bool f;

void rec(int l, int r) {
	while (l <= r && dp[l][r]) {
		f = l == r;
		res += (char)('a' + p[l][r].second);
		pair<int, int> o = p[l][r].first;
		l = o.first; r = o.second;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	while (cin >> s) {
		int n = s.length();
		if (s.length() >= 2600) {
			vector<int> cnt(26);
			for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
			for (int i = 0; i < 26; i++) if (cnt[i] >= 100) {
				for (int j = 0; j < 100; j++) cout << (char)('a' + i);
				cout << endl;
				break;
			}
			continue;
		}
		vector<vector<int> > nxt(n, vector<int>(26, -1));
		vector<vector<int> > prv(n, vector<int>(26, n));
		for (int k = 0; k < 26; k++) {
			int last = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == (char)(k + 'a')) {
					for (int j = last; j < i; j++) nxt[j][k] = i;
					last = i;
				}
			}
			last = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (s[i] == (char)(k + 'a')) {
					for (int j = i + 1; j <= last; j++) prv[j][k] = i;
					last = i;
				}
			}			
		}

		dp.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) p[i][j] = make_pair(make_pair(0, -1), 0);
		for (int i = 0; i < n; i++) for (int j = i; j < n; j++) if (s[i] == s[j]) dp[i][j] = 1 + (i != j), p[i][j].second = s[i] - 'a';

		for (int d = 0; d < n; d++) {
			for (int L = 0; L + d < n; L++) {
				int R = L + d;
				for (int k = 0; k < 26; k++) {
					int nL = prv[L][k], nR = nxt[R][k];
					if (nL < nR && dp[nL][nR] <= dp[L][R] + 2) {
						dp[nL][nR] = dp[L][R] + 2;
						p[nL][nR] = make_pair(make_pair(L, R), k);
					}
				}
			}
		}
		int ans = -1, ansl = -1, ansr = -1;
		for (int l = 0; l < n; l++) for (int r = l; r < n; r++) if (ans < dp[l][r]) {
			ans = dp[l][r];
			ansl = l;
			ansr = r;
		}
		res = "";
		rec(ansl, ansr);
		for (int i = res.size() - 1 - f; i >= 0; i--) res += res[i];

		if (res.size() > 100) {
			for (int i = 0; i < 50; i++) cout << res[i];
			for (int i = 49; i >= 0; i--) cout << res[i];
			cout << endl;
		} else cout << res << endl;
	}

	return 0;
}