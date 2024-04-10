#if 0
date +%Y.%m.%d

   lucky number  31 
 lucky number 
 sqrt(31) 
#endif
#include <cstdio>
#include <cmath>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator char () { char x[10]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005, maxb = 340, maxw = 10005;
int a[maxn];
int t[maxb][maxw], ts[maxb];
int tag[maxb];
bool iss[maxw];

int main () {
	int n = read, q = read, B = int(sqrt(n * 32));
	for (int i = 1; i <= n; i ++)
		++ t[i / B][a[i] = read];

	int shit[] = {
		4, 7,
		44, 47, 74, 77,
		444, 447, 474, 477, 744, 747, 774, 777,
		4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777,
		7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777,
	};

	for (int s : shit)
		iss[s] = 1;

	while (q --) {
		char o = read;
		if (o == 'c') {
			int l = read, r = read, ans = 0;
			int lb = l / B, rb = r / B;
			if (lb == rb) {
				for (int i = l; i <= r; i ++)
					if (iss[a[i] + tag[lb]])
						++ ans;
			}
			else {
				for (int i = l; i / B == lb; i ++)
					if (iss[a[i] + tag[lb]])
						++ ans;
				for (int i = r; i / B == rb; i --)
					if (iss[a[i] + tag[rb]])
						++ ans;
				for (int b = lb + 1; b < rb; b ++)
					for (int s : shit)
						if (s - tag[b] >= 0)
							ans += t[b][s - tag[b]];
			}
			printf("%d\n", ans);
		}
		if (o == 'a') {
			int l = read, r = read, x = read;
			int lb = l / B, rb = r / B;
			if (lb == rb) {
				for (int i = l; i <= r; i ++) {
					-- t[lb][a[i]];
					a[i] += x;
					++ t[lb][a[i]];
				}
			}
			else {
				for (int i = l; i / B == lb; i ++) {
					-- t[lb][a[i]];
					a[i] += x;
					++ t[lb][a[i]];
				}
				for (int i = r; i / B == rb; i --) {
					-- t[rb][a[i]];
					a[i] += x;
					++ t[rb][a[i]];
				}
				for (int b = lb + 1; b < rb; b ++)
					tag[b] += x;
			}
		}
	}
}