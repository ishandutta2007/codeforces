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
struct Rational {
    long long p,q;
    Rational() {
        p=0;q=1;
    }
    Rational(long long _p,long long _q) {
        p=_p;q=_q;
        assert(q!=0);
        if (q<0) {
            p=-p;q=-q;
        }
    }
    Rational operator - (const Rational &x) const {
        return (Rational(p*x.q-q*x.p,q*x.q));
    }
    bool operator < (const Rational &x) const {
        return (p*x.q<q*x.p);
    }
};
int a[MAX],n;
long long sum[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    FOR(i,1,n) sum[i]=sum[i-1]+a[i];
}
Rational oddOutCome(int l,int r,int u,int v) {
    //printf("odd %d %d %d %d\n",l,r,u,v);
    long long tot=0;
    int cnt=0;
    if (l<=r) {
        tot+=sum[r]-sum[l-1];
        cnt+=r-l+1;
    }
    if (u<=v) {
        tot+=sum[v]-sum[u-1];
        cnt+=v-u+1;
    }
    return (Rational(tot,cnt)-Rational(a[r],1));
}
Rational evenOutCome(int l,int r,int u,int v) {
    //printf("even %d %d %d %d\n",l,r,u,v);
    long long tot=0;
    int cnt=0;
    if (l<=r) {
        tot+=sum[r]-sum[l-1];
        cnt+=r-l+1;
    }
    if (u<=v) {
        tot+=sum[v]-sum[u-1];
        cnt+=v-u+1;
    }
    return (Rational(tot,cnt)-Rational(a[r-1]+a[r],2));
}
void process(void) {
    Rational best;
    pair<pair<int,int>,pair<int,int> > bestSeg(make_pair(1,1),make_pair(0,-1));
    int j=1;
    FOR(i,1,n) {
        while (n-i<i-j) j++;
        while (j<i && oddOutCome(j,i,n-i+j+1,n)<oddOutCome(j+1,i,n-i+j+2,n)) j++;
        if (best<oddOutCome(j,i,n-i+j+1,n)) {
            best=oddOutCome(j,i,n-i+j+1,n);
            bestSeg=make_pair(make_pair(j,i),make_pair(n-i+j+1,n));
        }
    }
    j=1;
    FOR(i,1,n-1) {
        while (n-i<i-j-1) j++;
        while (j<i && evenOutCome(j,i+1,n-i+j+1,n)<evenOutCome(j+1,i+1,n-i+j+2,n)) j++;
        if (best<evenOutCome(j,i+1,n-i+j+1,n)) {
            best=evenOutCome(j,i+1,n-i+j+1,n);
            bestSeg=make_pair(make_pair(j,i+1),make_pair(n-i+j+1,n));
        }
    }
    set<int> id;
    FOR(i,bestSeg.fi.fi,bestSeg.fi.se) if (1<=i && i<=n) id.insert(i);
    FOR(i,bestSeg.se.fi,bestSeg.se.se) if (1<=i && i<=n) id.insert(i);
    printf("%d\n",(int)id.size());
    FORE(it,id) printf("%d ",a[*it]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}