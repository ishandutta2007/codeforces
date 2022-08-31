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

int *a = alok(1111111, int);
int *b = alok(1111111, int);
int la, lb;

set<ll> hs;
ll gh() {
    ll t = 0;
    fr(i,la) {
        t *= 11;
        t += a[i];
    }
    t *= 11;
    fr(i,lb) {
        t *= 11;
        t += b[i];
    }
    return t;
}
int main() {
    int n;
    sf("%d", &n);
    sf("%d", &la);
    fr(i,la) sf("%d", a + i);
    sf("%d", &lb);
    fr(i,lb) sf("%d", b + i);
    int seq = 0;
    int win = 0;
    while (1) {
        if (!la) {
            win = 2;
            break;
        } else if (!lb) {
            win = 1;
            break;
        }
        ll hsh = gh();
        if (hs.find(hsh) != hs.end()) {
            break;
        }
        hs.insert(hsh);
        if (a[0] < b[0]) {
            b[lb++] = a[0];
            b[lb++] = b[0];
        } else {
            a[la++] = b[0];
            a[la++] = a[0];
        }
        a++, b++;
        la--, lb--;
        seq++;
    }
    if (win) {
    	pf("%d %d\n", seq, win);
    } else {
    	pf("-1\n");
    }
}