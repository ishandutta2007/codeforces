#include <bits/stdc++.h>
using namespace std;

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
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;

const int N = 5111;

int a[N], c[N][N];
int main() {
    int n;
    sf("%d", &n);
    for (int i = 0; i < n; i++) sf("%d", &a[i]);
    for (int l = 0; l < n; l++) {
        int k = 0;
        while (1 << k + 1 < l) k++;
        // printf("%d %d\n", l, k);
        for (int i = 0; i + l < n; i++) {
            if (l == 0) {
                c[i][i + l] = a[i];
            } else {
                // printf("%d %d: %d %d and %d %d\n", i, i + l, i, i + l - (1 << k), i + (1 << k), i + l);
                c[i][i + l] = c[i][i + l - (1 << k)] ^ c[i + (1 << k)][i + l];
            }
            // printf("%d %d: %d\n", i, i + l, c[i][i + l]);
        }
    }
    for (int l = 1; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            c[i][i + l] = max(c[i][i + l], max(c[i][i + l - 1], c[i + 1][i + l]));
        }
    }
    int q;
    sf("%d", &q);
    while (q--) {
        int l, r;
        sf("%d%d", &l, &r);
        l--, r--;
        pf("%d\n", c[l][r]);
    }
}