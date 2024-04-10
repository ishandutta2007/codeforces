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
#define CUBE(x) (1LL*(x)*(x)*(x))
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
int maxCube(long long x) {
    int tmp=pow(x,1.0/3);
    FOR(i,tmp-3,tmp+3) if (i>0 && CUBE(i)>x) return (i-1);
    assert(false);
}
pair<int,long long> best(long long x) {
    if (x<8) return (make_pair(x,x));
    pair<int,long long> res(-1,-1);
    int t=maxCube(x);
    pair<int,long long> tmp=best(x-CUBE(t));
    maximize(res,make_pair(tmp.fi+1,tmp.se+CUBE(t)));
    tmp=best(CUBE(t)-1-CUBE(t-1));
    maximize(res,make_pair(tmp.fi+1,tmp.se+CUBE(t-1)));
    return (res);
}
int main(void) {
    long long x; cin>>x;
    pair<int,long long> res=best(x);
    cout<<res.fi<<" "<<res.se<<endl;
    return 0;
}