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
const string ansYes="prime";
const string ansNo="composite";
const string yes="yes";
const string no="no";
bool isPrime(int x) {
    if (x<2) return (false);
    FOR(i,2,x-1) if (x%i==0) return (false);
    return (true);
}
bool ask(int x) {
    cout<<x<<endl;
    string s; cin>>s;
    return (s==yes);
}
string process(void) {
    int cnt=0;
    int lastYes=-1;
    FOR(i,1,10) if (isPrime(i) && ask(i)) {
        cnt++;
        lastYes=i;
    }
    if (cnt>1) return (ansNo);
    if (cnt<1) return (ansYes);
    FOR(i,11,50) if (isPrime(i) && ask(i)) return (ansNo);
    return (!ask(lastYes*lastYes)?ansYes:ansNo);
}
int main(void) {
    cout<<process()<<endl;
    return 0;
}