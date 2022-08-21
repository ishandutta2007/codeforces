#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
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


int main() {
	int n;
	sf("%d", &n);
	int c[5];
	fr(i,5) c[i] = 0;
	int t = 0;
	fr(i,n) {
		int x;
		sf("%d", &x);
		c[x]++;
		t += x;
	}
	int ans = 0;
	if (t == 1 || t == 2 || t == 5) {
		ans = -1;
	} else {
		if (c[1] <= c[2]) {
			int w = c[1];
			c[1] -= w;
			c[2] -= w;
			c[3] += w;
			ans += w;
		}
		if (c[1] > c[2]) {
			int w = c[2];
			c[1] -= w;
			c[2] -= w;
			c[3] += w;
			ans += w;
		}
		if (c[1]) {
			int q = c[1] / 3;
			c[1] -= 3*q;
			c[3] += q;
			ans += 2*q;
			/*
			while (c[1] >= 3) {//
				c[1] -= 3;
				c[3]++;
				ans += 2;
			}
			//*/
			if (c[1] == 1) {
				if (c[3]) {
					c[3]--;
					c[1]--;
					c[4]++;
					ans++;
				} else {
					c[4] -= 2;
					c[3] += 3;
					c[1]--;
					ans += 2;
				}
			} else if (c[1] == 2) {
				if (c[4]) {
					c[4]--;
					c[3] += 2;
					c[1] -= 2;
					ans += 2;
				} else {
					c[1] -= 2;
					c[3] -= 2;
					c[4] += 2;
					ans += 2;
				}
			}
		} else if (c[2]) {
			int q = c[2] / 3;
			c[3] += 2*q;
			c[2] -= 3*q;
			ans += 2*q;
			/*
			while (c[2] >= 3) {//
				c[3] += 2;
				c[2] -= 3;
				ans += 2;
			}
			//*/
			if (c[2] == 1) {
				if (c[4]) {
					c[4]--;
					c[3] += 2;
					c[2]--;
					ans++;
				} else {
					c[4] += 2;
					c[3] -= 2;
					c[2]--;
					ans += 2;
				}
			} else if (c[2] == 2) {
				c[4]++;
				c[2] -= 2;
				ans += 2;
			}
		}
	}
	pf("%d\n", ans);
}