#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e5+10;
const ll mod=1e9+7;
struct Line{
    mutable ll m,b,x;
    bool operator<(const Line&o)const{return m>o.m;}
    bool operator<(ll x)const{return this->x<x;}
};
struct ConvexHull:multiset<Line,less<>>{
    const static ll inf=LLONG_MAX;
    ll div(ll a,ll b){return a/b-((a^b)<0&&a%b);}
    bool isect(iterator a,iterator b){
        if(b==end()){a->x=inf;return 0;}
        if(a->m==b->m)a->x=a->b<b->b?inf:-inf;
        else a->x=div(b->b-a->b,a->m-b->m);
        return a->x>=b->x;
    }
    void add(ll m,ll b){
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->x >= y->x)isect(x, erase(y));
    }
    ll query(ll x){
        auto l=lower_bound(x);
        return l->m*x+l->b;
    }
};
ConvexHull*cvx[mn];
ll a[mn],b[mn];
vector<int>g[mn];
ll ans[mn];
void dfs(int x,int p){
    int lar=-1;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        if(lar==-1||cvx[y]->size()>cvx[lar]->size())lar=y;
    }
    if(lar==-1)cvx[x]=new ConvexHull();
    else cvx[x]=cvx[lar];
    for(int y:g[x])if(y!=p&&y!=lar){
        for(Line z:*cvx[y])cvx[x]->add(z.m,z.b);
    }
    if(cvx[x]->size())ans[x]=cvx[x]->query(a[x]);
    cvx[x]->add(b[x],ans[x]);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)scanf("%lld", b + i);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)printf("%lld ", ans[i]);
}