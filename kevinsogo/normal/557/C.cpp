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

#define LIM 100111

struct leg {
	ll l, d;
};

bool lcomp(const leg& a, const leg& b) {
	if (a.l != b.l) return a.l < b.l;
	return a.d > b.d;
}

leg legs[LIM];

int countcosts[LIM];

int main() {
	int n;
	sf("%d", &n);
	fr(i,n) sf("%lld", &legs[i].l);
	fr(i,n) sf("%lld", &legs[i].d);
	sort(legs, legs + n, lcomp);

	ll total = 0;
	fr(i,n) total += legs[i].d;


	fr(i,311) countcosts[i] = 0;
	int i = 0;
	ll ans = 1LL << 60;
	while (i < n) {
		int j = i+1;
		ll curr = total - legs[i].d;
		while (j < n && legs[j-1].l == legs[j].l) {
			curr -= legs[j].d;
			j++;
		}
		int kuha = j-i-1;
		ffr(k,311) {
			ll take = min(countcosts[k], kuha);
			curr -= k * take;
			kuha -= take;
			if (!kuha) break;
		}

		ans = min(ans, curr);

		fo(k,i,j) countcosts[legs[k].d]++;
		i = j;
	}

	pf("%I64d\n", ans);
}