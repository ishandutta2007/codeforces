#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;

int n, m;
char s[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		fill(s[i] + 1, s[i] + m + 1, '.');
	for(int i = 1; i <= n; i += 2)
		fill(s[i] + 1, s[i] + m + 1, '#');
	int cur = 1;
	for(int i = 2; i < n; i += 2, cur ^= 1) {
		if(cur == 1) s[i][m] = '#';
		else s[i][1] = '#';
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			putchar(s[i][j]);
		}
		putchar('\n');
	}
	return 0;
}