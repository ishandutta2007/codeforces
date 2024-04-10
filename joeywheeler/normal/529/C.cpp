#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct RT {
	typedef int T;

	T v[400005];
	static const T IDENTITY = 2e9;
	T op(const T &a, const T &b) {
		return min(a,b);
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
} r;

int h, w, k, q;
int x[200005], y[200005];
int x2[200005], y2[200005], x3[200005], y3[200005];
bool c[200005];

vector<int> op[200005];
vector<int> qu[200005];

void go() {
	memset(&r, 0, sizeof(r));
	FO(i,0,w+1) op[i].clear(), qu[i].clear();
	FO(i,0,k) op[x[i]].push_back(y[i]);
	FO(i,0,q) qu[x3[i]].push_back(i);
	FO(X,1,w+1) {
		for (int Y : op[X]) r.u(0, 1, h+1, Y, X);
		for (int o : qu[X]) if (r.q(0, 1, h+1, y2[o], y3[o]+1) >= x2[o]) c[o] = true;
	}
}

int main() {
	scanf("%d%d%d%d", &w, &h, &k, &q);
	FO(i,0,k) scanf("%d%d", x+i, y+i);
	FO(i,0,q) scanf("%d%d%d%d", x2+i, y2+i, x3+i, y3+i);
	go();
	swap(h,w);
	FO(i,0,k) swap(x[i],y[i]);
	FO(i,0,q) {
		swap(x2[i],y2[i]);
		swap(x3[i],y3[i]);
	}
	go();
	FO(i,0,q) printf(c[i]?"YES\n":"NO\n");
}