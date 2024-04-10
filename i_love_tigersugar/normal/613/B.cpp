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
pair<int,int> a[MAX];
int n,maxVal,costMax,costMin;
long long sum[MAX],lim;
void init(void) {
    cin>>n>>maxVal>>costMax>>costMin>>lim;
    FOR(i,1,n) cin>>a[i].fi;
    FOR(i,1,n) a[i].se=i;
    sort(a+1,a+n+1);
    FOR(i,1,n) sum[i]=sum[i-1]+a[i].fi;
}
long long getCost(int numMin,int val) {
    int t=lower_bound(a+1,a+numMin+1,make_pair(val,-1))-a-1;
    return (1LL*t*val-sum[t]);
}
int findMinValue(int numMax,long long lim) {
    if (numMax==n) return (maxVal);
    int L=0;
    int R=maxVal;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (getCost(n-numMax,R)<=lim?R:L);
        int M=(L+R)>>1;
        if (getCost(n-numMax,M)<=lim) L=M; else R=M-1;
    }
}
bool CompSe(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.se<b.se);
}
void process(void) {
    long long res=-1;
    pair<int,int> best;
    FOR(i,0,n) {
        long long tmp=1LL*maxVal*i-(sum[n]-sum[n-i]);
        if (tmp>lim) continue;
        tmp=lim-tmp;
        int minVal=findMinValue(i,tmp);
        long long val=1LL*costMax*i+1LL*costMin*minVal;
        if (val>res) {
            res=val;
            best.fi=i;
            best.se=minVal;
        }
    }
    FOR(i,n-best.fi+1,n) a[i].fi=maxVal;
    FOR(i,1,n-best.fi) maximize(a[i].fi,best.se);
    sort(a+1,a+n+1,CompSe);
    cout<<res<<"\n";
    FOR(i,1,n) cout<<a[i].fi<<" ";
    cout<<"\n";
}
int main(void) {
    init();
    process();
    return 0;
}