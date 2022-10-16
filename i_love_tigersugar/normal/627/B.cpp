#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
class FenwickTree {
    private:
    int n;
    vector<long long> v;
    long long get(int x) const {
        long long res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,long long d) {
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    long long getSum(int l,int r) const {
        return (get(r)-get(l-1));
    }
};
int n,dur,low,high,q;
long long cnt[MAX];
void init(void) {
    scanf("%d%d%d%d%d",&n,&dur,&high,&low,&q);
}
void process(void) {
    FenwickTree lowBit(n),highBit(n);
    REP(love,q) {
        int t,u,v;
        scanf("%d%d",&t,&u);
        if (t==1) {
            scanf("%d",&v);
            long long oldLow=min(1LL*low,cnt[u]);
            long long oldHigh=min(1LL*high,cnt[u]);
            cnt[u]+=v;
            long long curLow=min(1LL*low,cnt[u]);
            long long curHigh=min(1LL*high,cnt[u]);
            lowBit.update(u,curLow-oldLow);
            highBit.update(u,curHigh-oldHigh);
        } else cout<<lowBit.getSum(1,u-1)+highBit.getSum(u+dur,n)<<"\n";
    }
}
int main(void) {
    init();
    process();
    return 0;
}