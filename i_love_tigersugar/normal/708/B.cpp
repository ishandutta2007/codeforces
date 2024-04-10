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
long long comb2(int x) {
    return (x<2?0:1LL*x*(x-1)/2);
}
const string noAns="Impossible";
void answerNo(void) {
    cout<<noAns<<endl;
    exit(0);
}
int a00,a01,a10,a11;
void noZero(void) {
    if (a00!=0 || a01!=0 || a10!=0) return;
    FOR(i,1,MAX) if (comb2(i)==a11) {
        REP(love,i) printf("1");
        printf("\n");
        exit(0);
    }
}
void noOne(void) {
    if (a11!=0 || a10!=0 || a01!=0) return;
    FOR(i,1,MAX) if (comb2(i)==a00) {
        REP(love,i) printf("0");
        printf("\n");
        exit(0);
    }
}
void onlyZero(void) {
    if (a00!=0) return;
    int numPrev=a10;
    int numNext=a01;
    if (comb2(numPrev+numNext)!=a11) return;
    REP(love,numPrev) printf("1");
    printf("0");
    REP(love,numNext) printf("1");
    printf("\n");
    exit(0);
}
void onlyOne(void) {
    if (a11!=0) return;
    int numPrev=a01;
    int numNext=a10;
    if (comb2(numPrev+numNext)!=a00) return;
    REP(love,numPrev) printf("0");
    printf("1");
    REP(love,numNext) printf("0");
    printf("\n");
    exit(0);
}
void normalCase(void) {
    int cnt0=-1;
    int cnt1=-1;
    REP(i,MAX) if (comb2(i)==a00) cnt0=i;
    REP(i,MAX) if (comb2(i)==a11) cnt1=i;
    if (cnt0<0 || cnt1<0) answerNo();
    int tot=cnt0+cnt1;
    if (comb2(cnt0)+comb2(cnt1)+a01+a10!=comb2(tot)) answerNo();
    vector<int> val;
    REP(love,cnt0) {
        val.push_back(min(a01,cnt1));
        a01-=min(a01,cnt1);
    }
    sort(ALL(val),greater<int>());
    if (a01!=0) answerNo();
    FORE(it,val) {
        while (cnt1>*it) {
            printf("1");
            cnt1--;
        }
        printf("0");
    }
    REP(love,cnt1) printf("1");
    printf("\n");
}
void process(void) {
    cin>>a00>>a01>>a10>>a11;
    noZero();
    noOne();
    onlyZero();
    onlyOne();
    normalCase();
}
int main(void) {
    process();
    return 0;
}