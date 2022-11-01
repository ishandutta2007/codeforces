#include <bits/stdc++.h>

#define FO(i,a,b) for (ll i = (a); i < (b); i++)
#define sz(v) ll(v.size())

using namespace std;

typedef long long ll;

vector<pair<ll,ll> > gen1(ll x) {
    vector<pair<ll,ll> > res;
    ll c = 0;
    while (1) {
        ll nx = x;
        ll nc = c;
        while (1) {
            res.push_back(make_pair(nx,nc));
            if (nx%2 == 0) {
                nc++;
                nx /= 2;
            } else break;
        }
        if (x%3 == 0) {
            c++;
            x /= 3;
            x *= 2;
        } else break;
    }
    return res;
}

struct P {
    ll first;
    ll second;
    ll f0, f1;

    P(ll first, ll second, ll f0, ll f1) : first(first), second(second), f0(f0), f1(f1) {}

    bool operator<(const P&o) const {
        if (first == o.first) return second < o.second;
        return first < o.first;
    }
};

vector<P> gen(ll a, ll b) {
    vector<pair<ll,ll> > fa = gen1(a), fb = gen1(b);
    vector<P> res;
    FO(i,0,sz(fa)) FO(j,0,sz(fb)) {
        res.push_back(P(fa[i].first*fb[j].first,fa[i].second+fb[j].second,fa[i].first,fb[j].first));
    }
    sort(res.begin(),res.end());
    vector<P> res2;
    FO(i,0,sz(res)) {
        if (res2.empty() || res2.back().first != res[i].first) res2.push_back(res[i]);
    }
    return res2;
}

int main() {
    ll a0,b0, a1,b1;
    scanf("%lld %lld %lld %lld", &a0, &b0, &a1, &b1);
    vector<P> v0 = gen(a0,b0), v1 = gen(a1,b1);
    ll best = 1e15;
    ll f0,f1,f2,f3;
    int p0 = 0, p1 = 0;
    while (p0 != sz(v0) && p1 != sz(v1)) {
        if (v0[p0].first == v1[p1].first) {
            if (best > v0[p0].second+v1[p1].second) {
                best = v0[p0].second+v1[p1].second;
                f0 = v0[p0].f0;
                f1 = v0[p0].f1;
                f2 = v1[p1].f0;
                f3 = v1[p1].f1;
            }
            p0++;
        } else if (v0[p0].first < v1[p1].first) p0++;
        else p1++;
    }
    if (best > 1e12) printf("-1\n");
    else {
        printf("%lld\n", best);
        printf("%lld %lld\n", f0, f1);
        printf("%lld %lld\n", f2, f3);
    }
}