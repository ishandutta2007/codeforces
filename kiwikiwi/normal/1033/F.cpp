#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 0 0
// 1 1
// 2 01

int w, n, m;
int cnt[6789], dp[567890];
int base2[23], base3[23];
char s[23];
void dfs(int dep, int s1, int s2) {
	if (dep == w) {
		dp[s2] += cnt[s1];
	} else {
		dfs(dep + 1, s1 , s2);
		dfs(dep + 1, s1 , s2 + 2 * base3[dep]);
		dfs(dep + 1, s1 | base2[dep], s2 + base3[dep]);
		dfs(dep + 1, s1 | base2[dep], s2 + 2 * base3[dep]);
	}
}

int answer;
void query(int dep, int s1, int s2) {
	if (dep == w) {
		answer += cnt[s1] * dp[s2];
	} else {
		if (s[dep] == 'A') {
			query(dep + 1, s1, s2 + 2 * base3[dep]);
			query(dep + 1, s1 | base2[dep], s2);
		} else if (s[dep] == 'a') {
			query(dep + 1, s1 | base2[dep], s2 + base3[dep]);
		} else if (s[dep] == 'O') {
			query(dep + 1, s1 , s2);
		} else if (s[dep] == 'o') {
			query(dep + 1, s1, s2 + base3[dep]);
			query(dep + 1, s1 | base2[dep], s2 + 2 * base3[dep]);
		} else if (s[dep] == 'X') {
			query(dep + 1, s1, s2);
			query(dep + 1, s1 | base2[dep], s2 + base3[dep]);
		} else {
			query(dep + 1, s1, s2 + base3[dep]);
			query(dep + 1, s1 | base2[dep], s2);
		}
	}
}

int main() {
	scanf("%d%d%d", &w, &n, &m);
	base2[0] = base3[0] = 1;
	for (int i = 1; i <= w; i++) {
		base2[i] = base2[i - 1] * 2;
		base3[i] = base3[i - 1] * 3;
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	dfs(0, 0, 0);
	for (int i = 0; i < m; i++) {
		scanf("%s", s);
		reverse(s, s + w);
		answer = 0;
		query(0, 0, 0);
		printf("%d\n", answer);
	}
}