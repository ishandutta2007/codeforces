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
const int N = 52;
const int P = 5211;
const ll INF = 1LL<<40;

struct task {
    ll power, procs;
};
map<ll,vector<int>> procsp;
task ts[N];
ll fcurr[N][P], fprev[N][P];
int main() {
    int n;
    sf("%d", &n);
    fr(i,n) sf("%lld", &ts[i].power);
    ll t = 0;
    fr(i,n) {
        sf("%lld", &ts[i].procs);
        t += ts[i].procs;
        procsp[ts[i].power].push_back(ts[i].procs);
    }
    fe(sk,0,n) fe(s,0,t) {
        fcurr[sk][s] = s == 0 ? 0 : INF;
    }
    for (auto& it: procsp) {
        // pf("\n\ndoing pw %lld\n", it.first);
        sort(it.second.begin(), it.second.end());
        // fr(i,it.second.size()) pf("%d ", it.second[i]); pln;
        fe(sk,0,n) fe(s,0,t) fprev[sk][s] = fcurr[sk][s];
        ll ttl = 0;
        fr(i,it.second.size()) ttl += it.second[i];
        fe(sk,0,n) fe(s,0,t) {
            fcurr[sk][s] = INF;
            ll t1 = ttl, t2 = ttl;
            fe(gp,0,it.second.size()) {
                if (gp > sk) break;
                if (s >= t1)
                fcurr[sk][s] = min(fcurr[sk][s],
                        fprev[sk - gp + it.second.size() - gp][s - t1]
                        + it.first * ll(it.second.size() - gp)
                    );
                if (s >= t2)
                fcurr[sk][s] = min(fcurr[sk][s],
                        fprev[sk - gp + it.second.size() - gp][s - t2]
                        + it.first * ll(it.second.size() - gp)
                    );
                if (gp < it.second.size()) {
                    t1 -= it.second[gp];
                    t2 -= it.second[it.second.size() - gp - 1];
                }
            }
        }
        // fe(sk,0,n) fe(s,0,t) {
        //     if (fcurr[sk][s] < INF) {
        //         pf("for sk=%d s=%d: %lld\n", sk, s, fcurr[sk][s]);
        //     }
        // }
    }
    ll bestn = INF, bestd = 1;
    fe(s,1,t) {
        ll tp = fcurr[0][s];
        // if (bestn / bestd > tp / s) {
        if (bestn * s > bestd * tp) {
            bestn = tp;
            bestd = s;
        }
    }
    bestn *= 1000;
    pf("%lld\n", (bestn + bestd - 1) / bestd);
}