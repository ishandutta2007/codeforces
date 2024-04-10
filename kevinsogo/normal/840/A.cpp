#include <bits/stdc++.h>
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
using namespace std;

vector<ll> vs;
bool vcomp(int a, int b) {
    return vs[a] < vs[b];
}

#define N 211111
ll res[N];

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a;
    vector<ll> b;
    vector<int> ai;
    vector<int> bi;
    for (int i = 0; i < n; i++) {
        ll v;
        scanf("%lld", &v);
        a.push_back(v);
        ai.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        ll v;
        scanf("%lld", &v);
        b.push_back(v);
        bi.push_back(i);
    }
    vs = a;
    sort(ai.begin(), ai.end(), vcomp);
    vs = b;
    sort(bi.begin(), bi.end(), vcomp);

    for (int i = 0, j = n; i < n; i++) {
        res[bi[--j]] = ai[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[res[i]], " \n"[i == n - 1]);
    }
}