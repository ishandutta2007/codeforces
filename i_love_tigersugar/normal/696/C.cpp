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
const int mod=(int)1e9+7;
int pw(int x,int k) {
    int res=1;
    int mul=x;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
int inverse(int x) {
    return (pw(x,mod-2));
}
void process(void) {
    bool odd=true;
    int n; cin>>n;
    int val=1;
    REP(love,n) {
        long long x; cin>>x;
        if (x%2==0) odd=false;
        x%=mod-1;
        val=1LL*val*x%(mod-1);
    }
    int q=pw(2,(val-1+mod-1)%(mod-1));
    int p=odd?(pw(2,val)-2+mod)%mod:(pw(2,val)+2)%mod;
    p=1LL*p*inverse(6)%mod;
    cout<<p<<"/"<<q<<endl;
}
int main(void) {
    process();
    return 0;
}