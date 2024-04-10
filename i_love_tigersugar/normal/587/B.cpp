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
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const int mod=(int)1e9+7;
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
    vector<int> v;
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) {
            v[x]+=d;
            if (v[x]>=mod) v[x]-=mod;
        }
    }
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) {
            res+=v[x];
            if (res>=mod) res-=mod;
        }
        return (res);
    }
};
int a[MAX],n,m;
long long len;
int f[MAX][3];
vector<int> val;
void init(void) {
    cin>>n>>len>>m;
    REP(i,n) cin>>a[i];
    REP(i,n) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    REP(i,n) a[i]=lower_bound(ALL(val),a[i])-val.begin()+1;
}
void optimize(void) {
    FenwickTree bit(val.size());
    REP(i,n) f[i][1]=1;
    REP(i,n) bit.update(a[i],f[i][1]);
    int res=len%mod;
    FOR(j,2,m) {
        int cur=j&1;
        int prev=cur^1;
        REP(i,n) f[i][cur]=bit.get(a[i]);
        REP(i,n) if (i+1LL*(j-1)*n<len) {
            int tmp=((len-1-i-1LL*(j-1)*n)/n+1)%mod;
            res=(res+1LL*tmp*f[i][cur])%mod;
        }
        if (j==m) break;
        bit=FenwickTree(val.size());
        REP(i,n) bit.update(a[i],f[i][cur]);
    }
    cout<<res<<endl;
}
int main(void) {
    ios::sync_with_stdio(false);
    init();
    optimize();
    return 0;
}