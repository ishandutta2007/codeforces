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

char _s[11111];
char *s = _s + 1;

int main() {
    sf("%s", s);
    s[-1] = '*';
    int n = strlen(s);
    s[n] = '*';
    ll ti = 0, di = 1;
    ll ans = 0;
    fe(i,-1,n) {
        if (s[i] == '+') ti += di, di = 1;
        if ('1' <= s[i] && s[i] <= '9') di *= s[i] - '0';

        if (s[i] == '*') {
            ll tj = 0, dj = 1;
            ffe(j,i+1,n) {
                if (s[j] == '+') tj += dj, dj = 1; 
                if ('1' <= s[j] && s[j] <= '9') dj *= s[j] - '0';

                if (s[j] == '*') {
                    ll tk = 0, dk = 1;
                    fo(k,i,j) {
                        if (s[k] == '+') tk += dk, dk = 1;
                        if ('1' <= s[k] && s[k] <= '9') dk *= s[k] - '0';
                    }

                    ll bag = ti + tj + di * dj * (tk + dk);
                    ans = max(ans, bag);

                }
            }
        }
    }
    pf("%I64d\n", ans);
}