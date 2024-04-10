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
int gcd(int x,int y) {
    while (true) {
        if (x==0) return (y);
        if (y==0) return (x);
        if (x>y) x%=y; else y%=x;
    }
}
int lcm(int x,int y) {
    return (x/gcd(x,y)*y);
}
int main(void) {
    long long n;
    cin>>n;
    long long res=0;
    REP(i,MASK(11)) if (!BIT(i,0) && !BIT(i,1)) {
        int val=1;
        FOR(j,2,10) if (BIT(i,j)) val=lcm(val,j);
        long long tmp=n/val;
        if (__builtin_popcount(i)%2) res-=tmp; else res+=tmp;
    }
    cout<<res<<endl;
    return 0;
}