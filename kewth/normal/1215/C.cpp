#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005;
char s[maxn], t[maxn];
int ans_x[maxn << 1], ans_y[maxn << 1], ap;

int main() {
	int n = input();
	scanf("%s", s + 1);
	scanf("%s", t + 1);

	int cnt[2] = {0, 0};
	for(int i = 1; i <= n; i ++)
		cnt[s[i] - 'a'] ++;
	for(int i = 1; i <= n; i ++)
		cnt[t[i] - 'a'] ++;

	if(cnt[0] % 2 and cnt[1] % 2) {
		puts("-1");
		return 0;
	}

	int que[2] = {0, 0};
	for(int i = 1; i <= n; i ++)
		if(s[i] != t[i]) {
			if(not que[s[i] - 'a'])
				que[s[i] - 'a'] = i;
			else {
				ap ++;
				ans_x[ap] = que[s[i] - 'a'];
				ans_y[ap] = i;
				que[s[i] - 'a'] = 0;
			}
		}

	if(que[0] and que[1]) {
		ap ++;
		ans_x[ap] = que[1 - (t[1] - 'a')];
		ans_y[ap] = 1;
		ap ++;
		ans_x[ap] = que[t[1] - 'a'];
		ans_y[ap] = 1;
	}

	printf("%d\n", ap);
	for(int i = 1; i <= ap; i ++)
		printf("%d %d\n", ans_x[i], ans_y[i]);
}