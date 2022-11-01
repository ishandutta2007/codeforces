#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define mt make_tuple

using namespace std;

const int N = 200002;
int rt[4*N];

int q(int i, int rs, int re, int qs, int qe) {
	if (rs == qs && re == qe) {
		return rt[i];
	} else {
		int md = (rs+re)/2;
		int res = -2e9;
		if (qs<md) res = max(res, q(2*i+1, rs, md, qs, min(qe,md)));
		if (qe>md) res = max(res, q(2*i+2, md, re, max(qs,md), qe));
		return res;
	}
}

void u(int i, int rs, int re, int qi, int v) {
	if (rs + 1 == re) {
        rt[i] = max(rt[i], v);
	} else {
		int md = (rs+re)/2;
		if (qi<md) u(2*i+1, rs, md, qi, v);
        else u(2*i+2, md, re, qi, v);
		rt[i] = max(rt[2*i+1], rt[2*i+2]);
	}
}

int f[100005];
int n, m;
int mxi0[100005];
int mxi1[100005];

void smxi0(int i, int v) {
    mxi0[i] = v;
    u(0, 0, n, f[i], v);
}

void smxi1(int i, int v) {
    mxi1[i] = v;
    u(0, 0, n, f[i], v);
}

int main() {
    scanf("%d %d", &n, &m);
    fo(i,0,n) {
        int l, r;
        scanf("%d %d", &l, &r); l--;
        f[l]++; f[r]--;
    }
    fo(i,1,m) f[i] += f[i-1];
    n += 5;

    //fo(i,0,m) printf("f[%d]=%d\n", i, f[i]);

    fo(i,0,m) {
        int mp = q(0, 0, n, 0, f[i]+1);
        smxi0(i, mp+1);
    }
    memset(rt, 0, sizeof rt);

    //fo(i,0,m) printf("mxi0[%d]=%d\n", i, mxi0[i]);

    for (int i = m-1; i >= 0; i--) {
        int mp = q(0, 0, n, 0, f[i]+1);
        smxi1(i, mp+1);
    }

    //fo(i,0,m) printf("mxi1[%d]=%d\n", i, mxi1[i]);

    int res = 0;
    fo(i,0,m) res = max(res, mxi0[i] + mxi1[i] - 1);
    printf("%d\n", res);
}