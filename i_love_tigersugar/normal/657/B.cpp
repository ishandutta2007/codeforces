#include<bits/stdc++.h>
#define MAX   300300
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
#define __builtin_popcount __builtin_popcountll
using namespace std;
const long long INF=(long long)1e18+7LL;
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
int n;
long long lim,a[MAX];
int val[MAX];
void init(void) {
    cin>>n>>lim;
    FOR(i,0,n) cin>>a[i];
}
void calcValue(void) {
    memset(val,0,sizeof val);
    FOR(i,0,n) {
        int tmp=Abs(a[i]);
        int sign=a[i]<0?-1:1;
        REP(j,30) if (BIT(tmp,j)) val[i+j]+=sign;
    }
    int lastNonZero=0;
    REP(i,MAX) if (val[i]!=0) lastNonZero=i;
    REP(i,MAX) {
        if (val[i]==-1 && i>=lastNonZero) {
            FOR(j,0,n) a[j]*=-1;
            return (calcValue());
        }
        while (val[i]>1) {
            val[i]-=2;
            val[i+1]++;
        }
        while (val[i]<0) {
            val[i]+=2;
            val[i+1]--;
        }
    }
}
void process(void) {
    /*FOR(i,0,n) printf("%d ",a[i]); printf("\n");
    REP(i,20) printf("%d ",val[i]); printf("\n");*/
    int firstNonZero=0;
    REP(i,MAX) if (val[i]!=0) {
        firstNonZero=i;
        break;
    }
    long long chs=0;
    FORD(i,MAX-1,firstNonZero+1) {
         chs=chs*2+val[i];
         minimize(chs,INF);
         maximize(chs,-INF);
    }
    int res=0;
    FORD(i,firstNonZero,0) {
        chs=chs*2+val[i];
        minimize(chs,INF);
        maximize(chs,-INF);
        long long chsVal=a[i]-chs;
        //printf("Change at %d: %lld - %lld = %lld\n",i,a[i],chs,chsVal);
        if (-lim<=chsVal && chsVal<=lim && i<=n && (i<n || chsVal!=0)) res++;
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    calcValue();
    process();
    return 0;
}