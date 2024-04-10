#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m;
char s[N][N];
int group[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%s", s[i]+1);
	}
	int ans = 0;
	for (int j=1; j<=m; j++) {
		bool pos = true;
		for (int i=2; i<=n; i++) {
			if (group[i-1][j-1] == group[i][j-1] && s[i-1][j] > s[i][j]) {
				pos = false;
				break;
			}
			if (group[i-1][j-1] == group[i][j-1] && s[i-1][j] == s[i][j])
				group[i][j] = group[i-1][j];
			else
				group[i][j] = group[i-1][j] + 1;
		}
		if (!pos) {
			for (int i=2; i<=n; i++)
				group[i][j] = group[i][j-1];
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}