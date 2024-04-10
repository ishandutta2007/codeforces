#if 0
date +%Y.%m.%d

 a[x][y]  (x, y)  b[x][y]  (x, y) 
 a[x][y] * b[x][y]  (x, y) 

 a[x][y] * b[x][y] = a[n][m]  (x, y) 
 (x, y) 
 0 
 1 2 

 a, b  long long  hash  cf  hash 
#endif
#include <cstdio>
#include <algorithm>
#include <ctime>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 2000005;
const int shit = 3;
bool ok[maxn << 1];
char map[maxn << 1];
lolong a[shit][maxn << 1], b[shit][maxn << 1];
int mod[shit];

int main() {
	int n = input(), m = input(), k = m + 2;

	for(int i = 1; i <= n; i ++)
		scanf("%s", map + i * k + 1);

	srand(unsigned(time(0)));
	for(int s = 0; s < shit; s ++)
		mod[s] = 1000000000 + (rand() % 1000000000);

	map[1 * k + 1] = '#';
	for(int s = 0; s < shit; s ++) {
		a[s][1 * k + 1] = 1;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				if(map[i * k + j] == '.')
					a[s][i * k + j] =
						(a[s][(i - 1) * k + j] + a[s][i * k + j - 1]) % mod[s];
	}
	map[1 * k + 1] = '.';

	map[n * k + m] = '#';
	for(int s = 0; s < shit; s ++) {
		b[s][n * k + m] = 1;
		for(int i = n; i; i --)
			for(int j = m; j; j --)
				if(map[i * k + j] == '.')
					b[s][i * k + j] =
						(b[s][(i + 1) * k + j] + b[s][i * k + j + 1]) % mod[s];
	}
	map[n * k + m] = '.';

	int zero = 0;
	for(int s = 0; s < shit; s ++) {
		zero += (a[s][n * k + m] == 0);
		zero += (b[s][1 * k + 1] == 0);
	}
	if(zero == shit * 2) {
		puts("0");
		return 0;
	}


	int tot = -2;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) {
			int fuck = 0;
			for(int s = 0; s < shit; s ++)
				if(a[s][i * k + j] * b[s][i * k + j] % mod[s] == a[s][n * k + m])
					fuck ++;
			if(fuck == shit)
				tot ++;
		}

#if 0
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++)
			debug(" %lld", a[i * k + j]);
		debug("\n");
	}
	debug("\n");

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++)
			debug(" %lld", b[i * k + j]);
		debug("\n");
	}
	debug("\n");

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++)
			debug(" %lld", a[i * k + j] * b[i * k + j]);
		debug("\n");
	}
	debug("\n");
#endif

	if(tot)
		puts("1");
	else
		puts("2");
}