#include<bits/stdc++.h>
#define MAX   1000100
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
class FenwickTree {
    private:
    vector<int> v;
    int n;
    public:
    FenwickTree(int n=0) {
        this->n=n;
        if (n>0) v.assign(n+7,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) v[x]^=d;
    }
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res^=v[x];
        return (res);
    }
};
int a[MAX],answer[MAX],n,q;
vector<pair<int,int> > queryHaveL[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&q);
    FOR(i,1,q) {
        int l,r; scanf("%d%d",&l,&r);
        queryHaveL[l].push_back(make_pair(r,i));
    }
}
void process(void) {
    map<int,int> lastPos;
    FOR(i,1,n) lastPos[a[i]]=n+1;
    FenwickTree bit(n);
    FORD(l,n,1) {
        bit.update(lastPos[a[l]],a[l]);
        lastPos[a[l]]=l;
        FORE(it,queryHaveL[l]) {
            int r=it->fi;
            int id=it->se;
            answer[id]=bit.get(r);
        }
    }
    FOR(i,1,q) printf("%d\n",answer[i]);
}
int main(void) {
    init();
    process();
    return 0;
}