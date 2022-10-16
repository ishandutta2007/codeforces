#include<bits/stdc++.h>
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
const int base=7;
int numDig(int val,int base) {
    if (val==0) return (1);
    int res=0;
    while (val>0) {
        res++;
        val/=base;
    }
    return (res);
}
int process(void) {
    int m,n; scanf("%d%d",&m,&n);
    int digM=numDig(m-1,base);
    int digN=numDig(n-1,base);
    if (digM+digN>base) return (0);
    int res=0;
    REP(i,MASK(base)) if (__builtin_popcount(i)==digM+digN) {
        vector<int> dig;
        REP(j,base) if (BIT(i,j)) dig.push_back(j);
        do {
            int valM=0;
            REP(j,digM) valM=valM*base+dig[j];
            int valN=0;
            REP(j,digN) valN=valN*base+dig[j+digM];
            if (valM<m && valN<n) res++;
        } while (next_permutation(ALL(dig)));
    }
    return (res);
}
int main(void) {
    printf("%d\n",process());
    return 0;
}