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
typedef unsigned long long ull;
const ull INF=(ull)1e19+7LL;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
ull product(ull a,ull b) {
    if (a==0 || b==0) return (0);
    return (INF/a<b?INF:a*b);
}
ull gcd(ull a,ull b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
ull lcm(ull a,ull b) {
    return (product(a/gcd(a,b),b));
}
void process(void) {
    ull t,a,b;
    cin>>t>>a>>b;
    ull mod=lcm(a,b);
    if (t<mod) {
        ull p=min(t,min(a,b)-1);
        ull q=t;
        t=gcd(p,q);
        cout<<p/t<<"/"<<q/t<<endl;
        return;
    }
    ull cnt=t/mod;
    ull p=cnt*min(a,b)+min(min(a,b),t%mod+1)-1;
    ull q=t;
    t=gcd(p,q);
    cout<<p/t<<"/"<<q/t<<endl;
}
int main(void) {
    process();
    return 0;
}