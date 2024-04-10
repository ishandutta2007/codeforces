#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct RT {
	static constexpr int N = 300005;
	typedef pair<int,int> T;

	T v[4*N];
	static constexpr T IDENTITY = {-2e9,-2e9};
	T op(const T &a, const T &b) {
		return max(a,b);
	}

	T q(int i, int rs, int re, int qs, int qe) {
		if (rs==qs && re==qe) return v[i];
		else {
			int md=(rs+re)/2;
			T r = IDENTITY;
			if (qs<md) r = op(r, q(2*i+1, rs, md, qs, min(qe,md)));
			if (qe>md) r = op(r, q(2*i+2, md, re, max(qs,md), qe));
			return r;
		}
	}

	void u(int i, int rs, int re, int qi, T qv) {
		if (rs+1==re) v[i] = qv;
		else {
			int md=(rs+re)/2;
			if (qi<md) u(2*i+1, rs, md, qi, qv);
			else u(2*i+2, md, re, qi, qv);
			v[i] = op(v[2*i+1], v[2*i+2]);
		}
	}
} rt;

int n, k, a[300005], b[300005], c[1000005];
long long res;

void go(int s, int e, int mx) {
	int lh = mx-s, rh = e-mx;
	int mv = a[mx];
	if (lh < rh) {
		FO(i,s,mx+1) c[b[i]]--;
		FO(i,s,mx+1) res += c[(b[i]+mv)%k];
		if (e != mx) {
			int r = rt.q(0,0,n,mx+1,e+1).second;
			go(mx+1, e, r);
		} else FO(i,mx+1,e+2) c[b[i]]=0;

		if (s != mx) {
			FO(i,s,mx+1) c[b[i]]++;
			int l = rt.q(0,0,n,s,mx).second;
			go(s, mx-1, l);
		} else FO(i,s,mx+1) c[b[i]]=0;
	} else {
		FO(i,mx+1,e+2) c[b[i]]--;
		FO(i,mx+1,e+2) res += c[(k+b[i]-mv)%k];
		if (s != mx) {
			int l = rt.q(0,0,n,s,mx).second;
			go(s, mx-1, l);
		} else FO(i,s,mx+1) c[b[i]]=0;
		if (e != mx) {
			FO(i,mx+1,e+2) c[b[i]]++;
			int r = rt.q(0,0,n,mx+1,e+1).second;
			go(mx+1, e, r);
		} else FO(i,mx+1,e+2) c[b[i]]=0;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	FO(i,0,n) scanf("%d", a+i);
	FO(i,0,n) rt.u(0, 0, n, i, {a[i],i});
	FO(i,0,n) {
		b[i+1] = b[i] + a[i];
		b[i+1] %= k;
		a[i] %= k;
	}
	FO(i,0,n+1) c[b[i]]++;
	go(0,n-1,rt.q(0,0,n,0,n).second);
	res -= n;
	printf("%lld\n", res);
}