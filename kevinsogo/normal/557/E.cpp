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

#define LIM 5011
char s[LIM];
int sa[LIM];
int sai[LIM];
int lcp[LIM];
int lcpm[20][LIM];
int blog[LIM];

bool ishalf[LIM][LIM];

int lcpmn(int i, int j) {
	if (j == i) return 100000;
	int k = j - i;
	k |= k >> 1;
	k |= k >> 2;
	k |= k >> 4;
	k |= k >> 8;
	k |= k >> 16;
	k |= k >> 32;
	k ^= k >> 1;
	k = blog[k];
	return min(lcpm[k][i], lcpm[k][j-(1<<k)]);
}

bool comp(int a, int b) {
	if (a == b) return 0;
	while (s[a] == s[b]) a++, b++;
	return s[a] < s[b];
}


struct subs {
	int i, j;
};

bool scomp(const subs& a, const subs& b) {
	int A = sai[a.i];
	int B = sai[b.i];
	int K = lcpmn(min(A,B),max(A,B));
	if (K > a.j - a.i || K > b.j - b.i) {
		return a.j - a.i < b.j - b.i;
	}
	return s[a.i + K] < s[b.i + K];
}

subs sz[LIM * LIM];

int main() {
	int vv = 0;
	while (1<<vv < LIM) {
		blog[1<<vv] = vv;
		vv++;
	}
	sf("%s", s);
	int n = strlen(s);
	fr(i,n) sa[i] = i;
	sort(sa, sa + n, comp);
	fr(i,n) sai[sa[i]] = i;
	fr(i,n-1) {
		int k = 0;
		while (s[sa[i]+k] == s[sa[i+1]+k]) k++;
		lcp[i] = k;
	}
	fe(i,0,n) lcpm[0][i] = lcp[i];
	vv = 1;
	while (1<<vv < LIM) {
		fr(i,n) {
			lcpm[vv][i] = min(lcpm[vv-1][i], lcpm[vv-1][i + (1<<vv-1)]);
		}
		vv++;
	}

	fr(l,n) {
		fr(i,n-l) {
			int j = i + l;
			ishalf[i][j] = false;
			if (s[i] == s[j]) {
				ishalf[i][j] = j - i <= 3 || ishalf[i+2][j-2];
			}
		}
	}

	int targ;
	sf("%d", &targ);
	bool fd = false;
	fr(p,n) {
		int i = sa[p];
		int x = p ? lcp[p-1] : 0;
		fo(j,i+x,n) {
			// pf("i=%d j=%d\n", i, j);
			
			int I = p;
			while (I < n && lcp[I] > j-i) I++;
			while (I --> p-1) {
				// pf("now %d %d\n", i, j);
				if (ishalf[i][j]) {
					targ--;
					// pf("pasok\n");
					if (!targ) {
						s[j+1] = 0;
						pf("%s\n", s + i);
						fd = true;
						break;
					}
				}
			}
			if (fd) break;
		}
		if (fd) break;
	}
}