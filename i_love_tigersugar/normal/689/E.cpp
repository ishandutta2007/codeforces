#include<bits/stdc++.h>
#define MAX   500500
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
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    public:
    FenwickTree(int n=0) {
        this->n=n;
        v.assign(n+7,0);
    }
    void updateRange(int l,int r) {
        if (l>r) return;
        update(l,1);
        if (r<n) update(r+1,-1);
    }
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
};
const int mod=(int)1e9+7;
const int INF=(int)1e9+7;
pair<int,int> a[MAX];
vector<int> val;
int n,m;
int frac[MAX],finv[MAX];
int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void precalc(void) {
    frac[0]=finv[0]=1;
    FOR(i,1,MAX-1) {
        frac[i]=1LL*frac[i-1]*i%mod;
        finv[i]=inverse(frac[i]);
    }
}
int comb(int k,int n) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    FOR(i,1,n) {
        val.push_back(a[i].fi);
        val.push_back(a[i].se+1);
    }
    val.push_back(-INF);
    val.push_back(INF);
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
}
void process(void) {
    FenwickTree bit(val.size());
    FOR(i,1,n) {
        int L=lower_bound(ALL(val),a[i].fi)-val.begin()+1;
        int R=lower_bound(ALL(val),a[i].se+1)-val.begin();
        bit.updateRange(L,R);
    }
    int res=0;
    REP(i,val.size()-1) {
        int L=val[i];
        int R=val[i+1];
        int len=(R-L)%mod;
        int cnt=bit.get(i+1);
        if (cnt>=m) res=(res+1LL*len*comb(m,cnt))%mod;
    }
    printf("%d\n",res);
}
int main(void) {
    precalc();
    init();
    process();
    return 0;
}