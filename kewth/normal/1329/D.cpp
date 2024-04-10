#if 0
2020.04.05

 D 




  =  + 1 


1) 
2) 
 max  sum 
max(ceil(sum / 2), max).






#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005;
char s[maxn], t[maxn];
int pos[maxn];
int tot[26];
int ansx[maxn], ansy[maxn], ap;
int seg[maxn << 2], tag[maxn << 2];
#define ls (now << 1)
#define rs (now << 1 | 1)

int query (int now, int L, int R, int l, int r, bool c) {
	if (r < L or l > R) return 0;
	c |= tag[now];
	if (l <= L and R <= r) return c ? R - L + 1 : seg[now];
	int M = (L + R) >> 1;
	return query(ls, L, M, l, r, c) +
		query(rs, M + 1, R, l, r, c);
}

void modify (int now, int L, int R, int l, int r) {
	if (r < L or l > R) return;
	if (l <= L and R <= r) return tag[now] = 1, seg[now] = R - L + 1, void();
	int M = (L + R) >> 1;
	modify(ls, L, M, l, r);
	modify(rs, M + 1, R, l, r);
	seg[now] = tag[now] ? R - L + 1 : seg[ls] + seg[rs];
}

int n;
void erase (int l, int r) {
	/* debug("%d %d\n", l, r); */
	++ ap;
	ansx[ap] = l - query(1, 1, n, 1, l - 1, 0);
	ansy[ap] = r - query(1, 1, n, 1, r, 0);
	modify(1, 1, n, l, r);
}

int f () {
	int sum = 0, max = 0;
	for (int c = 0; c < 26; c ++) max = std::max(max, tot[c]);
	for (int c = 0; c < 26; c ++) sum += tot[c];
	return std::max(max, (sum + 1) >> 1);
}

int main() {
	int T = read, shit = 0;
	while (T --) {
		++ shit;
		scanf("%s", s + 1);
		n = int(strlen(s + 1));

		ap = 0;
		std::fill(seg + 1, seg + n * 4 + 1, 0);
		std::fill(tag + 1, tag + n * 4 + 1, 0);
		std::fill(tot, tot + 26, 0);

		for (int i = 1; i < n; i ++)
			if (s[i] == s[i + 1])
				++ tot[s[i] - 'a'];

		int m = 0, now = f();
		for (int i = 1; i < n; i ++)
			if (s[i] == s[i + 1]) {
				if (m and t[m] != s[i]) {
					-- tot[t[m] - 'a'];
					-- tot[s[i] - 'a'];
					int neo = f();
					if (neo == now) {
						++ tot[t[m] - 'a'];
						++ tot[s[i] - 'a'];
						goto ifelse;
					}
					now = neo;
					erase(pos[m --], i);
				}
				else {
ifelse:
					++ m;
					t[m] = s[i];
					pos[m] = i + 1;
				}
			}

		pos[m + 1] = n + 1;
		for (int i = 1; i <= m; i ++)
			erase(pos[i], pos[i + 1] - 1);
		erase(1, n);

		/* if (shit + T == 4) { */
			printf("%d\n", ap);
			for (int i = 1; i <= ap; i ++)
				printf("%d %d\n", ansx[i], ansy[i]);
		/* } else if (shit == 4206) */
		/* 	puts(s + 1); */
	}
}