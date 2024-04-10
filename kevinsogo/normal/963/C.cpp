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
const int N = 411111;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
bool muls_to(ll a, ll b, ll c) {
    if (!a || !b) return a * b == c;
    return c % a == 0 && b == c / a;
}

map<pair<ll,ll>,ll> ct;
vector<ll> wseq, hseq;
ll wcg, hcg;
ll wc[N], hc[N];
bool validated = false;
bool validate_result;
bool compute_validate() {
    for (int i = 0; i < wseq.size(); i++) {
        for (int j = 0; j < hseq.size(); j++) {
            if (!muls_to(wc[i], hc[j], ct[{wseq[i], hseq[j]}])) {
                return false;
            }
        }
    }
    return true;
}
bool subok(ll w0c, ll h0c) {
    assert(muls_to(w0c, h0c, ct[{wseq[0], hseq[0]}]));

    if(validated && !validate_result) return false;
    if (wcg % h0c) return false;
    if (hcg % w0c) return false;

    if (!validated) {
        validated = true;
        for (int i = 0; i < wseq.size(); i++) {
            // wc[i] * h0c == ct[{wseq[i], hseq[0]}];
            ll cc = ct[{wseq[i], hseq[0]}];
            assert(cc % h0c == 0);
            wc[i] = cc / h0c;
        }
        for (int j = 0; j < hseq.size(); j++) {
            // w0c * hc[j] == ct[{wseq[0], hseq[j]}];
            ll cc = ct[{wseq[0], hseq[j]}];
            assert(cc % w0c == 0);
            hc[j] = cc / w0c;
        }
        validate_result = compute_validate();
    }
    return validate_result;
}

int main() {
    int n;
    sf("%d", &n);
    set<ll> wset, hset;
    fr(i,n) {
        ll w, h, c;
        sf("%lld%lld%lld", &w, &h, &c);
        wset.insert(w);
        hset.insert(h);
        ct[{w, h}] = c;
    }
    wseq = vector<ll>(wset.begin(), wset.end());
    hseq = vector<ll>(hset.begin(), hset.end());
    ll ans = 0;
    if (muls_to(wseq.size(), hseq.size(), n)) {
        ll ct0 = ct[{wseq[0], hseq[0]}];
        wcg = hcg = ct0;
        for (int i = 0; i < wseq.size(); i++) {
            wcg = gcd(wcg, ct[{wseq[i], hseq[0]}]);
        }
        for (int j = 0; j < hseq.size(); j++) {
            hcg = gcd(hcg, ct[{wseq[0], hseq[j]}]);
        }
        for (ll d = 1; d * d <= ct0; d++) {
            if (ct0 % d == 0) {
                ll e = ct0 / d;
                if (subok(d, e)) ans++;
                if (d != e && subok(e, d)) ans++;
            }
        }
    }
    pf("%lld\n", ans);
}