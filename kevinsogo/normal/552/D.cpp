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

typedef pair<int,int> pt;
int gcd(int a,int b) {
	return b ? gcd(b, a % b) : a;
}

pt norm(int dx, int dy) {
	int s = 1;
	if (dx == 0) {
		if (dy < 0) s = -1;
	} else if (dx < 0) s = -1;
	dx *= s;
	dy *= s;
	int g = gcd(dx, dy);
	if (g < 0) g = -g;
	dx /= g;
	dy /= g;
	return make_pair(dx, dy);
}

pt pts[2015];
map<pt,int> iln;
int main() {
	int n;
	sf("%d", &n);
	ll ans = n*(n-1LL)*(n-2)/6;
	fr(i,n) {
		iln.clear();
		int x, y;
		sf("%d%d", &x, &y);
		pts[i] = make_pair(x, y);
		fr(j,i) {
			pt v = norm(pts[i].first - pts[j].first, pts[i].second - pts[j].second);
			if (iln.find(v) == iln.end()) iln[v] = 0;
			ans -= iln[v]++;
		}
	}
	pf("%I64d\n", ans);
}