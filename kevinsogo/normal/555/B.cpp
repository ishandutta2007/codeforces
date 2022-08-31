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

struct pr {
	ll l, r;
	int i;
};

#define LIM 200111
bool comp(pr a, pr b) {
	if (a.r != b.r) return a.r < b.r;
	return a.l > b.l;
}
pr prs[LIM];
map<ll,vector<int> > aa;
int ans[LIM];
int main() {
	int n, m;
	sf("%d%d", &n, &m);
	ll a, b;
	sf("%I64d%I64d", &a, &b);
	n--;
	fr(i,n) {
		ans[i] = -1;
		ll c, d;
		sf("%I64d%I64d", &c, &d);
		prs[i].r = d - a;
		prs[i].l = c - b;
		prs[i].i = i;
		a = c; b = d;
	}
	sort(prs, prs + n, comp);
	fr(i,m) {
		ll v;
		sf("%I64d", &v);
		aa[v].push_back(i);
	}
	bool bad = false;
	fr(i,n) {
		map<ll,vector<int> >::iterator it = aa.lower_bound(prs[i].l);
		if (it == aa.end()) {
			bad = true;
			break;
		}
		ll x = it->first;
		if (x > prs[i].r) {
			bad = true;
			break;
		}
		ans[prs[i].i] = aa[x].back();
		aa[x].pop_back();
		if (aa[x].size() == 0) {
			aa.erase(x);
		}
	}
	if (bad) {
		pf("No\n");
	} else {
		pf("Yes\n");
		fr(i,n) {
			if (i) pf(" ");
			pf("%d", ans[i]+1); 
		}
		pln;
	}
}