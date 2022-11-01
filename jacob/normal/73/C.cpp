#include <iostream>
#include <string>
#include <memory.h>
#include <climits>
#include <algorithm>
using namespace std;

string s;
int k;

int bonus[26][26];

int w[100][26][101];

int main(void) {
	cin >> s >> k;
	int n;
	cin >> n;
	memset(bonus, 0, sizeof(bonus));
	for (int i = 0; i < n; i++) {
		string s1, s2;
		int w;
		cin >> s1 >> s2 >> w;
		bonus[s1[0] - 'a'][s2[0] - 'a'] = w;
	}
	int m = (int)s.size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			for (int j2 = 0; j2 <= k; j2++) {
				w[i][j][j2] = INT_MIN / 2;
			}
		}
	}
	for (int j = 0; j < 26; j++) {
		if (s[0] == j + 'a') {
			w[0][j][0] = 0;
		} else
			w[0][j][1] = 0;
	}
	for (int i = 1; i < m; i++) {
		for (int c = 0; c < 26; c++) {
			int d = (c + 'a' == s[i]) ? 0 : 1;
			for (int j = d; j <= k; j++) {
				for (int c2 = 0; c2 < 26; c2++) {
					w[i][c][j] = max(w[i][c][j], w[i-1][c2][j-d] + bonus[c2][c]);
				}
			}
		}
	}
	int res = INT_MIN;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= k; j++) {
			res = max(res, w[m-1][i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}