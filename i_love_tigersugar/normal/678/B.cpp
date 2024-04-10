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
bool leapYear(int x) {
    if (x%400==0) return (true);
    if (x%100==0) return (false);
    if (x%4==0) return (true);
    return (false);
}
int nextStart(int s,int d) {
    return ((s+d)%7);
}
int main(void) {
    int fst; cin>>fst;
    int cur=fst;
    int sta=0;
    while (true) {
        sta=nextStart(sta,365+leapYear(cur));
        cur++;
        if (sta==0 && leapYear(cur)==leapYear(fst)) {
            cout<<cur<<endl;
            return 0;
        }
    }
    return 1;
}