#include<bits/stdc++.h>
#define MAX   100100
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
    vector<long long> v;
    int n;
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,long long d) {
        for (;x<=n;x+=x&-x) maximize(v[x],d);
    }
    long long getMax(int x) const {
        long long res=0;
        for (;x>=1;x&=x-1) maximize(res,v[x]);
        return (res);
    }
};
const double PI=acos(-1.0);
int n;
pair<int,int> a[MAX];
long long volume[MAX],f[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    FOR(i,1,n) volume[i]=1LL*a[i].fi*a[i].fi*a[i].se;
}
void process(void) {
    vector<long long> val;
    FOR(i,1,n) val.push_back(volume[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    FenwickTree bit(val.size());
    FOR(i,1,n) {
        int j=lower_bound(ALL(val),volume[i])-val.begin();
        f[i]=bit.getMax(j)+volume[i];
        bit.update(j+1,f[i]);
    }
    long long res=0;
    FOR(i,1,n) maximize(res,f[i]);
    printf("%.15lf\n",PI*res);
}
int main(void) {
    init();
    process();
    return 0;
}