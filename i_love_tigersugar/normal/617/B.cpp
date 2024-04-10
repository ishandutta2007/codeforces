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
int main(void) {
    int n;
    scanf("%d",&n);
    vector<int> one;
    FOR(i,1,n) {
        int x;
        scanf("%d",&x);
        if (x==1) one.push_back(i);
    }
    if (one.empty()) {
        cout<<0<<endl;
        return 0;
    }
    long long res=1;
    FOR(i,1,(int)one.size()-1) res=1LL*res*(one[i]-one[i-1]);
    cout<<res<<endl;
    return 0;
}