#include <bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=300005, sz=524288;

struct Seg{ int s, e; ll x; };

int n, d[N], ps[N], pe[N], ori[N], pc, q;
vector<int> e[N];
vector<Seg> v[N];
ll r[N];

void f(int x, int y, int z){
    d[x]=z;
    ps[x]=++pc;
    ori[ps[x]]=x;
    for(int i:e[x]) if(i!=y) f(i, x, z+1);
    pe[x]=pc;
}

struct SS{
    ll d[2*sz];
    void u(int x, int y, ll z){
        for(x+=sz, y+=sz; x<=y; x>>=1, y>>=1){
            if( x&1) d[x++]+=z;
            if(~y&1) d[y--]+=z;
        }
    }
    ll g(int x){
        ll r=0;
        for(x+=sz; x; x>>=1) r+=d[x];
        return r;
    }
} S;

int main(){
    scanf("%d", &n);
    for(int i=0, x, y; i<n-1; i++){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    f(1, 0, 1);
    scanf("%d", &q);
    for(; q--; ){
        int x, y; ll z; scanf("%d%d%lld", &x, &y, &z);
        y=min(y, n-d[x]);
        v[ps[x]].push_back({d[x], d[x]+y, z});
        v[pe[x]+1].push_back({d[x], d[x]+y, -z});
    }
    for(int i=1; i<=n; i++){
        for(Seg j:v[i]) S.u(j.s, j.e, j.x);
        r[ori[i]]=S.g(d[ori[i]]);
    }
    for(int i=1; i<=n; i++) printf("%lld ", r[i]);
}