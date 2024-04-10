#include<bits/stdc++.h>
#define MAX   5555
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
int x[MAX],a[MAX],b[MAX],c[MAX],d[MAX],n,s,e;
long long fromBig[MAX],fromSmall[MAX],toBig[MAX],toSmall[MAX];
void init(void) {
    scanf("%d%d%d",&n,&s,&e);
    FOR(i,1,n) scanf("%d",&x[i]);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,n) scanf("%d",&c[i]);
    FOR(i,1,n) scanf("%d",&d[i]);
}
long long moveCost(int from,int to) {
    long long fromCost=from>to?fromBig[from]:fromSmall[from];
    long long toCost=to>from?toBig[to]:toSmall[to];
    return (fromCost+toCost);
}
void process(void) {
    FOR(i,1,n) {
        fromBig[i]=x[i]+c[i];
        fromSmall[i]=-x[i]+d[i];
        toBig[i]=x[i]+a[i];
        toSmall[i]=-x[i]+b[i];
    }
    vector<int> cur;
    cur.push_back(s);
    cur.push_back(e);
    long long totCost=moveCost(s,e);
    int nextVal=n+1;
    while (true) {
        nextVal--;
        while (nextVal>0 && (nextVal==s || nextVal==e)) nextVal--;
        if (nextVal<=0) break;
        int bestPos=-1;
        long long bestCost=-1;
        REP(i,(int)cur.size()-1) {
            long long moreCost=moveCost(cur[i],nextVal)+moveCost(nextVal,cur[i+1])
                -moveCost(cur[i],cur[i+1]);
            if (bestPos<0 || moreCost<bestCost) {
                bestCost=moreCost;
                bestPos=i;
            }
        }
        cur.insert(cur.begin()+bestPos+1,nextVal);
        totCost+=bestCost;
    }
    cout<<totCost<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}