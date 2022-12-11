#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 16; 
const int M = N * N + 5;

int n, suma, sumb, t[N], lg[1 << N], a[N], b[N];
int cnta[1 << N], cntb[1 << N], f[1 << N][M];

int main() {
	scanf("%d", &n); char s[10]; 
	for(int i = 0; i < n; i ++) {
		scanf("%s%d%d", s, a + i, b + i);
		if(*s == 'R') t[i] = 0;
		if(*s == 'B') t[i] = 1;
		suma += a[i]; sumb += b[i];
	}
	for(int i = 0; i < n; i ++) {
		lg[1 << i] = i;
	}
	for(int i = 1; i < (1 << n); i ++) {
		cnta[i] = cnta[i & (i - 1)] + (t[lg[i & (-i)]] == 0);
		cntb[i] = cntb[i & (i - 1)] + (t[lg[i & (-i)]] == 1);
	}
	memset(f, -1, sizeof f); f[0][0] = 0;
	for(int S = 0; S < (1 << n); S ++) {
		for(int j = 0; j <= 120; j ++) if(~ f[S][j]) {
			for(int i = 0; i < n; i ++) if(!(S >> i & 1)) {
				int &dp = f[S | (1 << i)][j + min(a[i], cnta[S])];
				dp = max(dp, f[S][j] + min(b[i], cntb[S]));
			}
		}
	}
	int ans = 2e9;
	for(int i = 0; i <= 120; i ++) {
		if(~ f[(1 << n) - 1][i]) {
			ans = min(ans, max(suma - i, sumb - f[(1 << n) - 1][i]));
		}
	}
	printf("%d\n", ans + n);
	return 0;
}