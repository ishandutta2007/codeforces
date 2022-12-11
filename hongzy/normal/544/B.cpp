#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 210;

int n, k, col[N][N];
int cnt[3];

int main() {
	scanf("%d%d", &n, &k);
	col[1][1] = 1;
	for(int i = 2; i <= n; i ++) {
		col[1][i] = 3 - col[1][i - 1];
		col[i][1] = 3 - col[i - 1][1];
	}
	for(int i = 2; i <= n; i ++) {
		for(int j = 2; j <= n; j ++) {
			col[i][j] = 3 - col[i - 1][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cnt[col[i][j]] ++;
		}
	}
	int c = 0;
	if(cnt[1] > cnt[2]) c = 1;
	else c = 2;
	if(cnt[c] < k) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(col[i][j] == c) {
					if(-- k >= 0) {
						putchar('L');
					} else putchar('S');
				} else {
					putchar('S');
				}
			}
			putchar('\n');
		}
	}
	return 0;
}