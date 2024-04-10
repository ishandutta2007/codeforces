#include<bits/stdc++.h>
#define MAXV   10001000
#define MAXS   100100
#define RANGE   10
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
int costAdd,costMul;
long long minCost[MAXV];
void calcSmall(void) {
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
    FOR(i,1,MAXS) q.push(make_pair(minCost[i],i));
    while (!q.empty()) {
        long long cost=q.top().fi;
        int u=q.top().se;
        q.pop();
        if (u>MAXS || cost>minCost[u]) continue;
        if (minCost[u-1]>minCost[u]+costAdd) {
            minCost[u-1]=minCost[u]+costAdd;
            q.push(make_pair(minCost[u-1],u-1));
        }
        if (minCost[u+1]>minCost[u]+costAdd) {
            minCost[u+1]=minCost[u]+costAdd;
            q.push(make_pair(minCost[u+1],u+1));
        }
        if (minCost[2*u]>minCost[u]+costMul) {
            minCost[2*u]=minCost[u]+costMul;
            q.push(make_pair(minCost[2*u],2*u));
        }
    }
}
void calcBig(void) {
    FOR(i,MAXS+1,MAXV-1) FOR(j,i-RANGE,i+RANGE) if (j%2==0)
        minimize(minCost[i],1LL*Abs(i-j)*costAdd+costMul+minCost[j/2]);
}
int main(void) {
    int n; cin>>n>>costAdd>>costMul;
    REP(i,MAXV) minCost[i]=1LL*costAdd*i;
    calcSmall();
    calcBig();
    cout<<minCost[n]<<endl;
    return 0;
}