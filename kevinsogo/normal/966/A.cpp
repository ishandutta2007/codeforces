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

const int C = 200111;
const ll INF = 1LL<<60;

ll stairs[C];
ll elevs[C];

ll ceildiv(ll a, ll b) {
    assert(b >= 1);
    return (a + b - 1) / b;
}
int stairc, elevc;
ll n, m;
ll floora, posa, floorb, posb;
ll cand(ll x, ll spd) {
    // printf("(%lld %lld %lld)", llabs(posa - x), ceildiv(llabs(floorb - floorb), spd), llabs(x - posb));
    return llabs(posa - x) + ceildiv(llabs(floora - floorb), spd) + llabs(x - posb);
}
ll try_stair(int i) {
    if (0 <= i && i < stairc) {
        // printf("[%d:%lld]%lld ", i, stairs[i], cand(stairs[i], 1));
        return cand(stairs[i], 1);
    }
    return INF;
}
ll spd;
ll try_elev(int i) {
    if (0 <= i && i < elevc) {
        // printf("[%d:%lld]%lld ", i, elevs[i], cand(elevs[i], spd));
        return cand(elevs[i], spd);
    }
    return INF;
}
ll try_pos(ll pos) {
    int la = -1, ra = stairc;
    while (ra - la > 1) {
        int ma = la + ra >> 1;
        (stairs[ma] <= pos ? la : ra) = ma;
    }
    int lb = -1, rb = elevc;
    while (rb - lb > 1) {
        int mb = lb + rb >> 1;
        (elevs[mb] <= pos ? lb : rb) = mb;
    }
    // printf("trying %lld: %d %d %d %d... ", pos, la, ra, lb, rb);
    ll ans = INF;
    ans = min(ans, try_stair(la));
    ans = min(ans, try_stair(ra));
    ans = min(ans, try_elev(lb));
    ans = min(ans, try_elev(rb));
    // pln;
    return ans;
}

int main() {
    scanf("%lld%lld%d%d%lld", &n, &m, &stairc, &elevc, &spd);
    for (int i = 0; i < stairc; i++) scanf("%lld", &stairs[i]);
    for (int i = 0; i < elevc; i++) scanf("%lld", &elevs[i]);
    sort(stairs, stairs + stairc);
    sort(elevs, elevs + elevc);
    int q;
    for (scanf("%d", &q); q--;) {
        sf("%lld%lld%lld%lld", &floora, &posa, &floorb, &posb);
        ll ans = INF;
        if (floora == floorb) ans = min(ans, llabs(posa - posb));
        ans = min(ans, try_pos(posa));
        ans = min(ans, try_pos(posb));
        printf("%lld\n", ans);
    }

}