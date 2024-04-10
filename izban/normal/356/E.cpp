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
#include <cstring>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 100100;

const int mod[2] = {1e9 + 7, 1e9 + 9};
const int q[2] = {239, 997};
int p[maxn][2];
int h[maxn][2];

int n;
string s;
ll cans, ans[maxn][26];

void calcHashes() {
	memset(ans, 0, sizeof(ans));
	cans = 0;
	
	n = s.length();
	for (int k = 0; k < 2; k++) {
		p[0][k] = 1;
		for (int i = 1; i < maxn; i++) p[i][k] = 1LL * p[i - 1][k] * q[k] % mod[k];
		h[0][k] = s[0];
		for (int i = 1; i < n; i++) {
			h[i][k] = (h[i - 1][k] + 1LL * p[i][k] * s[i]) % mod[k];
		}
	}
}

pair<int, int> getHash(int l, int r) {
	pair<int, int> ans;
	ans.first = 1LL * (h[r][0] - (l ? h[l - 1][0] : 0) + mod[0]) * p[maxn - l - 1][0] % mod[0];
	ans.second = 1LL * (h[r][1] - (l ? h[l - 1][1] : 0) + mod[1]) * p[maxn - l - 1][1] % mod[1];
	return ans;
}

bool equal(int l1, int r1, int l2, int r2) {
	return getHash(l1, r1) == getHash(l2, r2);
}

int findDifference(int l1, int r1, int l2, int r2) {
	int len = r1 - l1 + 1;
	if (equal(l1, r1, l2, r2)) return -1;
	int l = -1, r = len - 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (equal(l1, l1 + m, l2, l2 + m)) {
			l = m;
		} else {
			r = m;
		}
	}
	if (!(equal(l1 + r + 1, r1, l2 + r + 1, r2))) return -1;
	return r;
}

vector<int> e[maxn];

bool isThere(int l, int r, char c) {
	int k = lower_bound(e[c - 'a'].begin(), e[c - 'a'].end(), l) - e[c - 'a'].begin();
	if (k == e[c - 'a'].size() || e[c - 'a'][k] > r) return 0;
	return 1;
}

void print(pair<int, int> a) {
	cout << a.first << " " << a.second << endl;
}

ll suf[maxn], pref[maxn];

ll fastsolve() {
	calcHashes();
	for (int i = 0; i < 26; i++) e[i].clear();
	for (int i = 0; i < n; i++) e[s[i] - 'a'].push_back(i);
	memset(suf, 0, sizeof(suf));
	memset(pref, 0, sizeof(pref));

	set<pair<int, int> > ok;
	for (int i = 0; i < n; i++) {
		cans++;
		ok.insert(make_pair(i, i));
		for (int j = 0; j < 26; j++) {
			ans[i][j] = n;
		}
	}
	for (int len = 3; len <= n; len = 2 * len + 1) {
		for (int l = 0; l + len <= n; l++) {
			int r = l + len - 1;
			int m = (l + r) / 2;
			if (equal(l, m - 1, m + 1, r) && ok.find(make_pair(l, m - 1)) != ok.end() && ok.find(make_pair(m + 1, r)) != ok.end()) {
				for (int j = 0; j < 26; j++) {
					if (isThere(l, m - 1, 'a' + j)) continue;
					if (s[m] != 'a' + j) {
						ans[m][j] += 1LL * len * len;
					} else {
						cans += 1LL * len * len;
						ok.insert(make_pair(l, r));
						if (r < n) suf[r + 1] += 1LL * len * len;
						if (l > 0) pref[l - 1] += 1LL * len * len;
					}
				}
			}
			int k = findDifference(l, m - 1, m + 1, r);
			if (k != -1) {
				if (ok.find(make_pair(m + 1, r)) != ok.end() && !isThere(m + 1, r, s[m])) {
					ans[l + k][s[m + 1 + k] - 'a'] += 1LL * len * len;
				}
				if (ok.find(make_pair(l, m - 1)) != ok.end() && !isThere(l, m - 1, s[m])) {
					ans[m + 1 + k][s[l + k] - 'a'] += 1LL * len * len;
				}
			}
		}
	}
	ll cur;
	cur = 0;
	for (int i = 0; i < n; i++) {
		cur += suf[i];
		for (int j = 0; j < 26; j++) ans[i][j] += cur;
	}
	cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		cur += pref[i];
		for (int j = 0; j < 26; j++) ans[i][j] += cur;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < 26; j++) if (s[i] != 'a' + j) cans = max(cans, ans[i][j]);
	return cans;
}

void stress() {

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	stress();
	
	while (cin >> s) cout << fastsolve() << endl;

    return 0;
}