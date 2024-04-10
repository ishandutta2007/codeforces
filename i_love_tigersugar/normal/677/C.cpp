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
const int mod=(int)1e9+7;
int code(char c) {
    if ('0'<=c && c<='9') return (c-'0');
    if ('A'<=c && c<='Z') return (c-'A'+10);
    if ('a'<=c && c<='z') return (c-'a'+36);
    if (c=='-') return (62);
    if (c=='_') return (63);
    assert(false);
}
int cnt[111];
void process(void) {
    REP(i,64) REP(j,64) cnt[i&j]++;
    string s; cin>>s;
    int res=1;
    FORE(it,s) res=1LL*res*cnt[code(*it)]%mod;
    cout<<res<<endl;
}
int main(void) {
    process();
    return 0;
}