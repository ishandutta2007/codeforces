#if 0
2019.04.20

 BalticOI 2004 

 a  b  a 
 a  x, y 
 x <= y  b 
 x > y  b  a 

 a 

 a  a  1 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }

struct Heap {
	int val;
	int ltid, rtid;
	int di;
	int size;
};

#define self pool[now]
#define lt pool[self.ltid]
#define rt pool[self.rtid]

const int maxn = 1000005;
Heap pool[maxn << 1];

int merge(int now, int x) {
	if(!now) return x;
	if(!x) return now;
	if(self.val < pool[x].val)
		std::swap(now, x);
	self.size += pool[x].size;
	self.rtid = merge(self.rtid, x);
	if(rt.di > lt.di)
		std::swap(self.ltid, self.rtid);
	self.di = rt.di + 1;
	return now;
}

int pop(int now) {
	int res = merge(self.ltid, self.rtid);
	self.ltid = self.rtid = 0;
	self.di = self.size = 1;
	self.val *= -1;
	return res;
}

int st_l[maxn], st_r[maxn], st_v[maxn], st_lh[maxn], st_rh[maxn], sp;

int main() {
	int n = input();

	for(int i = 1; i <= n; i ++) {
		pool[i].di = pool[i].size = 1;
		int x = pool[i].val = input() + 1000000000;
		int lh = i, rh = 0;

		while(sp and x < st_v[sp]) {
			lh = merge(st_lh[sp], lh);
			rh = merge(st_rh[sp], rh);

			while(pool[lh].size > pool[rh].size + 1) {
				int tmp = lh;
				lh = pop(tmp);
				rh = merge(rh, tmp);
			}

			while(pool[rh].size > pool[lh].size + 1) {
				int tmp = rh;
				rh = pop(tmp);
				lh = merge(lh, tmp);
			}

			if(pool[lh].size > pool[rh].size)
				x = pool[lh].val;
			else
				x = - pool[rh].val;

			sp --;
		}

		++ sp;
		st_l[sp] = st_r[sp - 1] + 1;
		st_r[sp] = i;
		st_v[sp] = x;
		st_lh[sp] = lh;
		st_rh[sp] = rh;
	}

	lolong ans = 0;

	for(int i = 1; i <= sp; i ++)
		for(int j = st_l[i]; j <= st_r[i]; j ++)
			ans += std::abs(std::abs(pool[j].val) - st_v[i]);

	printf("%lld\n", ans);
	/* for(int i = 1; i <= sp; i ++) */
	/* 	for(int j = st_l[i]; j <= st_r[i]; j ++) */
	/* 		debug(" %d", st_v[i] - 1000000000); */
	/* debug("\n"); */
}