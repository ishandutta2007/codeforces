#include<bits/stdc++.h>
#define MAX   200200
#define LOG   18
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
int a[MAX],b[MAX],n;
int greaterPos[MAX],nonLessPos[MAX];
int rmqA[MAX][LOG+1],rmqB[MAX][LOG+1],lg2[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
}
void setupRMQ(void) {
    FOR(i,1,n) rmqA[i][0]=a[i];
    FOR(j,1,LOG) FOR(i,1,n-MASK(j)+1)
        rmqA[i][j]=max(rmqA[i][j-1],rmqA[i+MASK(j-1)][j-1]);
    FOR(i,1,n) rmqB[i][0]=b[i];
    FOR(j,1,LOG) FOR(i,1,n-MASK(j)+1)
        rmqB[i][j]=min(rmqB[i][j-1],rmqB[i+MASK(j-1)][j-1]);
    FOR(i,1,n) {
        while (MASK(lg2[i])<=i) lg2[i]++;
        lg2[i]--;
    }
}
int getA(int l,int r) {
    int k=lg2[r-l+1];
    return (max(rmqA[l][k],rmqA[r-MASK(k)+1][k]));
}
int getB(int l,int r) {
    int k=lg2[r-l+1];
    return (min(rmqB[l][k],rmqB[r-MASK(k)+1][k]));
}
void process(void) {
    int j=1;
    FOR(i,1,n) {
        while (j<i) j++;
        while (j<=n && getA(i,j)<=getB(i,j)) j++;
        greaterPos[i]=j;
    }
    j=1;
    FOR(i,1,n) {
        while (j<i) j++;
        while (j<=n && getA(i,j)<getB(i,j)) j++;
        nonLessPos[i]=j;
    }
    long long res=0;
    FOR(i,1,n) res+=greaterPos[i]-nonLessPos[i];
    cout<<res<<endl;
}
int main(void) {
    init();
    setupRMQ();
    process();
    return 0;
}