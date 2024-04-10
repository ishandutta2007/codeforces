#if 0
2020.03.11

 Ynoi 

1) f[b][i]  b  belong[i] +- 1 
 i 
2) F[l][r]  l  r 


 O() 



 [l, r] l, r 
 F  f 

f  g[b][i]  b  i 

 F  f 

 O(nlogV) 
#endif
#include <cstdio>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005, maxs = 500, maxb = 500, inf = 1000000000;
int bl[maxn];
int L[maxs], R[maxs];
int a[maxn];
par s[maxn];
int f[maxs][maxn];
int bf[maxs][maxs];
int tmp1[maxb], tmp2[maxb], tmp3[maxb];

int block_sort(int l, int r, int *tmp = tmp1) {
	int b = bl[l], p = 0;
	for(int i = L[b]; i <= R[b]; i ++)
		if(l <= s[i].second and s[i].second <= r)
			tmp[++ p] = s[i].first;
	return p;
}

void calc(int p, int &tar, int *tmp = tmp1) {
	for(int i = 1; i < p; i ++)
		tar = std::min(tar, tmp[i + 1] - tmp[i]);
}

int main() {
	int n = read, B = int(sqrt(n));
	for(int i = 1; i <= n; i ++)
		s[i] = par(a[i] = read, i);

	int S = 0;
	for(int i = 1; i <= n; i ++) {
		if(!S or R[S] - L[S] + 1 == B)
			L[++ S] = i;
		bl[R[S] = i] = S;
	}

	for(int b = 1; b <= S; b ++)
		std::sort(s + L[b], s + R[b] + 1);

	for(int b = 1; b <= S; b ++)
		for(int c = 1; c <= S; c ++) {
			int p = L[b];
			for(int i = L[c]; i <= R[c]; i ++) {
				while(p <= R[b] and s[p].first < s[i].first)
					++ p;
				int &now = f[b][s[i].second] = inf;
				if(p <= R[b])
					now = std::min(now, s[p].first - s[i].first);
				if(p > L[b])
					now = std::min(now, s[i].first - s[p - 1].first);
			}
		}

	for(int b = 1; b <= S; b ++)
		for(int c = 1; c < b; c ++)
			for(int i = R[c] - 1; i >= L[c]; i --)
				f[b][i] = std::min(f[b][i], f[b][i + 1]);

	for(int b = 1; b <= S; b ++)
		for(int c = S; c > b; c --)
			for(int i = L[c] + 1; i <= R[c]; i ++)
				f[b][i] = std::min(f[b][i], f[b][i - 1]);

	for(int i = 1; i <= n; i ++) {
		f[bl[i]][i] = inf;
		for(int b = bl[i] + 1; b <= S; b ++)
			f[b][i] = std::min(f[b - 1][i], f[b][i]);
		for(int b = bl[i] - 1; b; b --)
			f[b][i] = std::min(f[b + 1][i], f[b][i]);
	}

	for(int b = S; b; b --) {
		calc(block_sort(L[b], R[b]), bf[b][b] = inf);
		for(int c = b + 1; c <= S; c ++)
			bf[b][c] = std::min({bf[b][c - 1], f[b][R[c]], bf[c][c]});
	}

	int q = read;
	while(q --) {
		int l = read, r = read, ans = inf;
		// debug("query %d %d\n", l, r);

		if(bl[l] == bl[r])
			calc(block_sort(l, r), ans);

		else {
			int lb = bl[l] + 1, rb = bl[r] - 1;

			int p2 = block_sort(l, R[lb - 1], tmp2);
			int p3 = block_sort(L[rb + 1], r, tmp3);
			std::merge(tmp2 + 1, tmp2 + p2 + 1,
					tmp3 + 1, tmp3 + p3 + 1, tmp1 + 1);
			int p1 = p2 + p3;
			calc(p1, ans);

			if(lb <= rb) {
				ans = std::min(ans, bf[lb][rb]);
				ans = std::min(ans, f[rb][l]);
				ans = std::min(ans, f[lb][r]);
			}
		}

		printf("%d\n", ans);
	}
}