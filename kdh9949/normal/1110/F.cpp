#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 500005, SZ = 524288;
const ll INF = ll(1e18);

int n, q, ps[N], pe[N];
ll ans[N];
vector<pii> e[N];
struct Qry{ int s, e, i; };
vector<Qry> qv[N];

struct Seg{
    ll d[2 * SZ], l[2 * SZ];
    void i(){
        fill(d + 1, d + 2 * SZ, INF);
    }
    void z(int x){
        l[2 * x] += l[x];
        d[2 * x] += l[x];
        l[2 * x + 1] += l[x];
        d[2 * x + 1] += l[x];
        l[x] = 0;
    }
    void u(int s, int e, ll v, int x = 1, int p = 1, int q = n){
        if(q < s || e < p) return;
        if(s <= p && q <= e){
            l[x] += v;
            d[x] += v;
            return;
        }
        z(x);
        u(s, e, v, 2 * x, p, p + q >> 1);
        u(s, e, v, 2 * x + 1, p + q + 2 >> 1, q);
        d[x] = min(d[2 * x], d[2 * x + 1]);
    }
    ll g(int s, int e, int x = 1, int p = 1, int q = n){
        if(q < s || e < p) return INF;
        if(s <= p && q <= e) return d[x];
        z(x);
        return min(g(s, e, 2 * x, p, p + q >> 1),
                   g(s, e, 2 * x + 1, p + q + 2 >> 1, q));
    }
} S;

int g(int x, ll d){
    ps[x] = pe[x] = x;
    for(pii i : e[x]) pe[x] = max(pe[x], g(i.x, d + i.y));
    if(ps[x] == pe[x]) S.u(ps[x], ps[x], d - INF);
    return pe[x];
}

void f(int x){
    for(Qry i : qv[x]){
        ans[i.i] = S.g(i.s, i.e);
    }
    for(pii i : e[x]){
        S.u(1, n, i.y);
        S.u(ps[i.x], pe[i.x], -2LL * i.y);
        f(i.x);
        S.u(1, n, -i.y);
        S.u(ps[i.x], pe[i.x], 2LL * i.y);
    }
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 2, x, y; i <= n; i++){
        scanf("%d%d", &x, &y);
        e[x].emplace_back(i, y);
    }
    for(int i = 0, x, y, z; i < q; i++){
        scanf("%d%d%d", &x, &y, &z);
        qv[x].push_back({y, z, i});
    }
    S.i();
    g(1, 0);
    f(1);
    for(int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}