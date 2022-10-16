#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
map<long long,long long> cost;
int high(long long x) {
    FOR(i,1,62) if (MASK(i)-1>=x) return (i);
    assert(false);
}
long long getCost(long long x) {
    __typeof(cost.begin()) it=cost.find(x);
    return (it==cost.end()?0LL:it->se);
}
long long totCost(long long u,long long v) {
    if (high(v)>high(u)) return (totCost(v,u));
    int hu=high(u);
    int hv=high(v);
    long long res=0;
    REP(love,hu-hv) {
        res+=getCost(u);
        u=u/2;
    }
    while (u!=v) {
        res+=getCost(u);
        res+=getCost(v);
        u=u/2;
        v=v/2;
    }
    return (res);
}
void update(long long u,long long v,int c) {
    if (high(v)>high(u)) return (update(v,u,c));
    int hu=high(u);
    int hv=high(v);
    REP(love,hu-hv) {
        cost[u]+=c;
        u=u/2;
    }
    while (u!=v) {
        cost[u]+=c;
        cost[v]+=c;
        u=u/2;
        v=v/2;
    }
}
void process(void) {
    int q; cin>>q;
    REP(love,q) {
        int t,c;
        long long u,v;
        cin>>t>>u>>v;
        if (t==1) {
            cin>>c;
            update(u,v,c);
        } else cout<<totCost(u,v)<<"\n";
    }
}
int main(void) {
    process();
    return 0;
}