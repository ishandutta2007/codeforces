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

const int maxn = 105;
const int inf = 1000000007;
const int mod = 1000000007;

int nxt[maxn][maxn];
int dp[maxn][maxn][maxn];
pair<pair<int, int>, int> p[maxn][maxn][maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a, b, s;
	while (cin >> a >> b >> s) {
		memset(nxt, 0, sizeof(nxt));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) for (int k = 0; k < maxn; k++) p[i][j][k] = make_pair(make_pair(-1, -1), -1);

		string cur = "";
		for (int i = 0; i < s.length(); i++) {
			for (char c = 'A'; c <= 'Z'; c++) {
				string o = cur + c;
				for (int j = i + 1; j > 0; j--) {
					bool f = true;
					for (int k = 0; k < j; k++) f &= s[k] == o[(int)o.length() - j + k];
					if (f) {
						nxt[i][c] = j;
						break;
					}
				}
			}
			cur += s[i];
		}
		p[0][0][0] = make_pair(make_pair(-2, -2), -2);
		for (int i = 0; i <= a.length(); i++) {
			for (int j = 0; j <= b.length(); j++) {
				for (int k = 0; k < s.length(); k++) if (p[i][j][k] != make_pair(make_pair(-1, -1), -1)) {
					if (dp[i + 1][j][k] <= dp[i][j][k]) {
						dp[i + 1][j][k] = dp[i][j][k];
						p[i + 1][j][k] = make_pair(make_pair(i, j), k);
					}
					if (dp[i][j + 1][k] <= dp[i][j][k]) {
						dp[i][j + 1][k] = dp[i][j][k];
						p[i][j + 1][k] = make_pair(make_pair(i, j), k);
					}
					if (i < a.length() && j < b.length() && a[i] == b[j] && dp[i + 1][j + 1][nxt[k][a[i]]] <= dp[i][j][k] + 1) {
						dp[i + 1][j + 1][nxt[k][a[i]]] = dp[i][j][k] + 1;
						p[i + 1][j + 1][nxt[k][a[i]]] = make_pair(make_pair(i, j), k);
					}
				}
			}
		}

		int o1 = -1, o2 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (dp[a.length()][b.length()][i] > o2) {
				o1 = i;
				o2 = dp[a.length()][b.length()][i];
			}
		}

		if (o1 == -1) {
			cout << 0 << endl;
			continue;
		}
		
		string ans = "";
		int a1 = a.length(), a2 = b.length(), a3 = o1;
		while (a1 != -2 && a2 != -2) {
			if (a1 - p[a1][a2][a3].first.first == 1 && a2 - p[a1][a2][a3].first.second == 1) ans = a[a1 - 1] + ans;
			pair<pair<int, int>, int> o = p[a1][a2][a3];
			a1 = o.first.first;
			a2 = o.first.second;
			a3 = o.second;
		}

		cout << ans << endl;
	}

	return 0;
}