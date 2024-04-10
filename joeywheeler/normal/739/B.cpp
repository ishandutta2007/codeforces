#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

int n;
ll a[200005];
vector<pair<int,ll> > u[200005];
int res[200005];

multiset<ll> *go(int i, ll dp) {
    multiset<ll> *o = new multiset<ll>;
    o->insert(dp-a[i]);
    for (auto e : u[i]) {
        int j; ll w; tie(j,w) = e;
        multiset<ll> *p = go(j, dp+w);

        if (o->size() < p->size()) swap(o,p);
        for (auto x : *p) {
            o->insert(x);
        }
    }
    while (!o->empty() && *(o->rbegin()) > dp) o->erase(*(o->rbegin()));
    res[i] = o->size();
    return o;
}

int main() {
    scanf("%d", &n);
    FO(i,1,n+1) scanf("%lld", a+i);
    FO(i,2,n+1) {
        int p; ll w;
        scanf("%d %lld", &p, &w);
        u[p].emplace_back(i, w);
    }
    go(1,0);
    FO(i,1,n+1) printf("%d%c", res[i]-1, " \n"[i==n]);
}