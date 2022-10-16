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
int n,numSeq;
int a[MAX],seqID[MAX],seqPos[MAX],seqLen[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    numSeq=1;
    seqID[1]=seqID[n]=-1;
    FOR(i,2,n-1) {
        if (a[i]!=a[i-1] && a[i]!=a[i+1]) {
            seqID[i]=numSeq;
            seqPos[i]=++seqLen[numSeq];
        } else {
            seqID[i]=-1;
            if (seqLen[numSeq]>0) numSeq++;
        }
    }
    int res=0;
    FOR(i,1,numSeq) res=max(res,(seqLen[i]+1)/2);
    printf("%d\n",res);
    FOR(i,1,n) {
        int val;
        if (seqID[i]<0) val=a[i];
        else if (seqLen[seqID[i]]%2!=0) val=a[i-seqPos[i]];
        else if (seqPos[i]<=seqLen[seqID[i]]/2) val=a[i-seqPos[i]];
        else val=a[i-seqPos[i]]^1;
        printf("%d ",val);
    }
    printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}