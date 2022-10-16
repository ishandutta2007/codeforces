#include<bits/stdc++.h>
#define MAX   555
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
long long a[MAX][MAX];
int n;
long long sumRow(int row) {
    long long sum=0;
    FOR(i,1,n) sum+=a[row][i];
    FOR(i,1,n) if (a[row][i]==0) return (-sum);
    return (sum);
}
long long sumCol(int col) {
    long long sum=0;
    FOR(i,1,n) sum+=a[i][col];
    return (sum);
}
long long sumMainDiag(void) {
    long long sum=0;
    FOR(i,1,n) sum+=a[i][i];
    return (sum);
}
long long sumOtherDiag(void) {
    long long sum=0;
    FOR(i,1,n) sum+=a[i][n-i+1];
    return (sum);
}
void noAnswer(void) {
    cout<<-1<<endl;
    exit(0);
}
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) cin>>a[i][j];
    if (n==1) {
        printf("1\n");
        return;
    }
    long long reqSum=0;
    FOR(i,1,n) if (sumRow(i)>0) reqSum=sumRow(i);
    long long res;
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]==0) {
        res=reqSum+sumRow(i);
        if (res<=0) noAnswer();
        a[i][j]=res;
    }
    FOR(i,1,n) if (sumRow(i)!=reqSum) noAnswer();
    FOR(i,1,n) if (sumCol(i)!=reqSum) noAnswer();
    if (sumMainDiag()!=reqSum) noAnswer();
    if (sumOtherDiag()!=reqSum) noAnswer();
    cout<<res<<endl;
}
int main(void) {
    process();
    return 0;
}