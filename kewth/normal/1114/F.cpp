#if 0
2019.09.10


 phi(x)  x  p  p - 1  p 
 300  62 
 log 
#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() {
	int x = 0, c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while(c >= '0' and c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

const int maxn = 400005, maxm = 305, maxp = 64, mod = 1000000007;
int prime[maxp], pp;
lolong invp[maxp];
lolong shit_sta[maxm];

inline lolong power(lolong x, int k) {
	if(k < 0)
		k += mod - 1;
	lolong res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

struct Data {
	lolong val, sta;
	Data(lolong val=1, lolong sta=0): val(val), sta(sta) {}
};

inline void operator *= (Data &a, Data b) {
	(a.val *= b.val) %= mod;
	a.sta |= b.sta;
}

Data data[maxn << 2], lazy[maxn << 2];

inline void push_down(int now, int L, int R) {
	Data &l = lazy[now];
	int M = (L + R) >> 1;

	data[now << 1] *= Data(power(l.val, M - L + 1), l.sta);
	data[now << 1 | 1] *= Data(power(l.val, R - M), l.sta);
	lazy[now << 1] *= l;
	lazy[now << 1 | 1] *= l;

	lazy[now] = Data();
}

inline void update(int now) {
	data[now] = data[now << 1];
	data[now] *= data[now << 1 | 1];
}

void modify(int now, int L, int R, int l, int r, Data d) {
	if(r < L or l > R)
		return;

	if(l <= L and R <= r) {
		data[now] *= Data(power(d.val, R - L + 1), d.sta);
		lazy[now] *= d;
		return;
	}

	push_down(now, L, R);

	int M = (L + R) >> 1;
	modify(now << 1, L, M, l, r, d);
	modify(now << 1 | 1, M + 1, R, l, r, d);

	update(now);
}

Data query(int now, int L, int R, int l, int r) {
	if(r < L or l > R)
		return Data();

	if(l <= L and R <= r)
		return data[now];

	push_down(now, L, R);

	int M = (L + R) >> 1;
	Data res = query(now << 1, L, M, l, r);
	res *= query(now << 1 | 1, M + 1, R, l, r);

	return res;
}

int main() {
	for(int i = 2; i < maxm; i ++) {
		bool isprime = true;
		for(int j = 2; j < i; j ++)
			if(i % j == 0)
				isprime = false;
		if(isprime) {
			prime[pp] = i;
			invp[pp] = power(i, -1);
			pp ++;
		}
	}

	for(int i = 1; i < maxm; i ++)
		for(int k = 0; k < pp; k ++)
			if(not (i % prime[k]))
				shit_sta[i] |= 1ll << k;

	int n = input(), q = input();

	for(int i = 1; i <= n; i ++) {
		int x = input();
		modify(1, 1, n, i, i, Data(x, shit_sta[x]));
	}

	while(q --) {
		char s[20];
		scanf("%s", s);
		if(*s == 'M') {
			int l = input(), r = input(), x = input();
			modify(1, 1, n, l, r, Data(x, shit_sta[x]));
		}

		else {
			int l = input(), r = input();
			Data d = query(1, 1, n, l, r);
			lolong ans = d.val;
			for(int k = 0; k < pp; k ++)
				if(d.sta >> k & 1)
					(ans *= (prime[k] - 1) * invp[k] % mod) %= mod;
			printf("%lld\n", ans);
		}
	}
}