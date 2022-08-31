#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
#define LIM 201111

// set and get
struct segtree {
    int i, j;
    int minvalue;
    int pvalue;
    segtree *l, *r;
    segtree(vector<int>& v, int I, int J): pvalue(-1), l(NULL), r(NULL) {
    	i = v[I];
    	j = v[J];
		minvalue = 0;
    	if (I == J) {
		} else{
            int K = I + J >> 1;
            l = new segtree(v, I, K);
            r = new segtree(v, K+1, J);
        }
    }
    void visit(){
    	if (minvalue < pvalue) {
    		minvalue = pvalue;
            if (l) {
                l->pvalue = max(l->pvalue, pvalue);
                r->pvalue = max(r->pvalue, pvalue);
            }
        }
        pvalue = -1;
    }
    void setmx(int I, int J, int v) {
        if (I <= i && j <= J) {
            pvalue = max(pvalue, v);
            visit();
        } else {
            visit();
            if (!(j < I || J < i)) {
                l->setmx(I, J, v);
                r->setmx(I, J, v);
                minvalue = min(l->minvalue, r->minvalue);
            }
        }
    }
    int get(int I) {
    	visit();
    	if (i == j) {
    		return minvalue;
    	} else if (l->i <= I && I <= l->j) {
    		return l->get(I);
    	} else {
    		return r->get(I);
    	}
    }
    void prstate() {
    	printf("[%d %d]:", i, j);
    	printf("%d (%d)", minvalue, pvalue);
    	printf("\n");
    	if (l) l->prstate();
    	if (r) r->prstate();
    }
};

struct qr {
	int x, y;
	bool left;
};
qr qrs[LIM];
vector<int> xs;
vector<int> ys;
char s[111];

int main() {
    int n, q;
    sf("%d%d", &n, &q);

    fr(i,q) {
    	int x, y;
    	sf("%d%d%s", &x, &y, s);
    	xs.push_back(x);
    	ys.push_back(y);
    	qrs[i].x = x;
    	qrs[i].y = y;
    	qrs[i].left = *s == 'L';
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.resize(distance(xs.begin(), unique(xs.begin(), xs.end())));
    ys.resize(distance(ys.begin(), unique(ys.begin(), ys.end())));


    segtree *tops = new segtree(xs, 0, xs.size()-1);
    segtree *lefts = new segtree(ys, 0, ys.size()-1);
    fr(i,q) {
    	int x = qrs[i].x;
    	int y = qrs[i].y;
    	// pln;
    	// pln;
    	// pln;
    	// pln;
    	// pf("state:\n");
    	// pf("tops\n"); tops->prstate();
    	// pf("lefts\n"); lefts->prstate();
    	int ans;
    	if (qrs[i].left) {
    		int X = lefts->get(y);
    		// pf("left %d %d: %d\n", x, y, X);
    		lefts->setmx(y, y, x);
    		if (X < x) tops->setmx(X+1, x, y);
    		ans = x - X;
    	} else {
    		int Y = tops->get(x);
    		// pf("top %d %d: %d\n", x, y, Y);
    		tops->setmx(x, x, y);
    		if (Y < y) lefts->setmx(Y+1, y, x);
    		ans = y - Y;
    	}
    	pf("%d\n", ans);
    }
}