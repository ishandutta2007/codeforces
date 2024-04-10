#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e5 + 5;
int n, m;
char s[N], t[N];
int dp[N * 101];
bool vis[N * 101];
int que[N * 101], ql, qr;

int id(int x, int y) {
	return x * (m + 1) + y - 1;
}

struct ac_automaton {
	int go[N][26], ed[N], fail[N], tot, que[N], ql, qr;
	ac_automaton() {
		tot = 1;
	}
	void ins(char *s) {
		int u = 1;
		for (int i = 0; s[i]; ++ i) {
			if (!go[u][s[i] - 'a']) go[u][s[i] - 'a'] = ++ tot;
			u = go[u][s[i] - 'a'];
		}
		ed[u] ++;
	}
	void build() {
		ql = qr = 0;
		for (int i = 0; i < 26; ++ i) {
			if (go[1][i]) {
				fail[go[1][i]] = 1;
				que[qr ++] = go[1][i];
			} else {
				go[1][i] = 1;
			}
		}
		while (ql < qr) {
			int u = que[ql ++];
			for (int i = 0; i < 26; ++ i) {
				if (go[u][i]) {
					fail[go[u][i]] = go[fail[u]][i];
					que[qr ++] = go[u][i];
				} else {
					go[u][i] = go[fail[u]][i];
				}
			}
		}
	}
} ac;

int main() {
	cin >> s >> t;
	n = strlen(s);
	m = strlen(t);
	ac.ins(t); ac.build();
	memset(dp, -0x3f, sizeof(dp)); dp[id(0, 1)] = 0;
	ql = qr = 0; que[qr ++] = id(0, 1); vis[id(0, 1)] = 1;
	int ans = -0x3f3f3f3f;
	while (ql < qr) {
		int u = que[ql ++], v = dp[u];
		int i = u / (m + 1), j = u % (m + 1) + 1;
//		cerr << i << " " << j << " " << v << endl;
		for (int c = 0; c < 26; ++ c) {
			if (s[i] != '?' && s[i] != c + 'a') continue;
			int nj = ac.go[j][c], nu = id(i + 1, nj), nv = v + ac.ed[nj];
//			cerr << " -> " << i + 1 << " " << nj << " " << nv << endl;
			ans = max(ans, nv);
			if (dp[nu] < nv) {
				dp[nu] = nv;
				if (!vis[nu] && i + 1 < n) {
					vis[nu] = 1;
					que[qr ++] = nu;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}