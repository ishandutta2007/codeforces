
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <random>
//#include "optimization.h"

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;

const int MX = 4e5;
int g[MX][26];
int ans[MX], ter[MX], pr[MX];

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<string> all;
	int ret = 0;
	string cur = "";
	char c;
	while (c = getchar()) {
		if (c == EOF) {
			break;
		}
		if (c == ',' || c == '.' || c == '?' || c == '!' || c == '-' || c == '\'' || c == ' ' || c == '\n') {
			if (cur.size()) {
				all.push_back(cur);
				cur = "";
			}
			ret++;
		} else {
			cur += c;
		}
	}

	//vector<vector<int>> g(MX, vector<int>(26, -1));
	//vector<int> ans(MX, 0), pr(MX, -1), ter(MX, 0);
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < 26; j++) {
			g[i][j] = -1;
		}
	}
	ans[0] = 2;
	pr[0] = -1;
	int cn = 1;

	for (string &s : all) {
		for (char &c : s) {
			c -= 'a';
		}
	}

	for (string &s : all) {
		int v = 0;
		bool checked = 0;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (g[v][c] == -1) {
				ret++;
				int last = cn++;
				pr[last] = v;
				g[v][c] = last;
				v = last;
			} else {
				if (ans[v] == 1 && !checked) {
					bool good = 1;
					int st = s.size() - 1;
					int _v = v;
					for (int j = i; j < s.size(); j++) {
						if (j > i && ter[_v]) {
							st = j - 1;
							break;
						}
						if (g[_v][s[j]] == -1) {
							good = 0;
							break;
						} else {
							_v = g[_v][s[j]];
						}
					}
					if (good && ter[_v]) {
					} else {
						good = 0;
					}
					if (good) {
						v = _v;
						i = st;
						ret++;
					} else {
						ret++;
						v = g[v][c];
					}
					checked = 1;
				} else {
					ret++;
					v = g[v][c];
				}
			}
		}
		if (!ter[v]) {
			ter[v] = 1;
			ans[v]++;
			while (v) {
				v = pr[v];
				ans[v]++;
			}
		}
	}

	cout << ret << '\n';

    return 0;
}