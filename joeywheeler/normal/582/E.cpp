#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define M (1<<16)
#define MOD 1000000007

using namespace std;

typedef vector<int> rt;

rt cor(rt a, rt b) {
	FO(i,0,16) FO(j,0,M) if (j&(1<<i)) {
		a[j] += a[j^(1<<i)];
		if (a[j] >= MOD) a[j] -= MOD;
		b[j] += b[j^(1<<i)];
		if (b[j] >= MOD) b[j] -= MOD;
	}
	FO(i,0,M) {
		a[i] = (a[i]*1ll*b[i])%MOD;
	}
	FO(i,0,16) FO(j,0,M) if (j&(1<<i)) {
		a[j] -= a[j^(1<<i)];
		if (a[j] < 0) a[j] += MOD;
	}
	return a;
}

rt cand(rt a, rt b) {
	FO(i,0,16) FO(j,0,M) if (~j&(1<<i)) {
		a[j] += a[j^(1<<i)];
		if (a[j] >= MOD) a[j] -= MOD;
		b[j] += b[j^(1<<i)];
		if (b[j] >= MOD) b[j] -= MOD;
	}
	FO(i,0,M) {
		a[i] = (a[i]*1ll*b[i])%MOD;
	}
	FO(i,0,16) FO(j,0,M) if (~j&(1<<i)) {
		a[j] -= a[j^(1<<i)];
		if (a[j] < 0) a[j] += MOD;
	}
	return a;
}

rt add(rt a, rt b) {
	FO(i,0,M) {
		a[i] += b[i];
		if (a[i] >= MOD) a[i] -= MOD;
	}
	return a;
}

char gc() {
	char ch; scanf(" %c", &ch);
	return ch;
}

rt getrt(char ch) {
	int ind = ch >= 'a' ? ch - 'a' : ch - 'A';
	rt res(M);
	FO(i,0,M) {
		res[i] = 1;
		FO(j,0,16) {
			int fres = !!(i&(1<<j));
			int ares = !!(j&(1<<ind));
			if (ch >= 'a') ares = !ares;
			if (fres != ares) res[i] = 0;
		}
	}
	return res;
}

rt rdexpr() {
	char ch = gc();
	rt res(M);
	if (ch == '(') {
		rt a = rdexpr();
		gc();
		char op = gc();
		gc();
		rt b = rdexpr();
		gc();

		if (op != '|') res = add(res,cand(a,b));
		if (op != '&') res = add(res,cor(a,b));
	} else {
		if (ch == '?') {
			FO(c,'a','e') res = add(res, getrt(c));
			FO(c,'A','E') res = add(res, getrt(c));
		} else {
			res = add(res, getrt(ch));
		}
	}
	return res;
}

int main() {
	rt r = rdexpr();
	int n; scanf("%d", &n);
	FO(i,0,n) {
		int a,b,c,d,e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		int x = (a<<0)|(b<<1)|(c<<2)|(d<<3);
		FO(j,0,M) {
			if (((j>>x)&1) != e) r[j] = 0;
		}
	}
	long long res = 0;
	FO(i,0,M) {
		res += r[i];
	}
	res %= MOD;
	printf("%lld\n", res);
}