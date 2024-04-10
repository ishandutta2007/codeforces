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
const string symmetric="AHIMOoTUVvWwXxY";
const string yes="TAK";
const string no="NIE";
bool good(char c) {
    FORE(it,symmetric) if (*it==c) return (true);
    return (false);
}
bool goodPair(char x,char y) {
    if (x=='b' && y=='d') return (true);
    if (x=='d' && y=='b') return (true);
    if (x=='p' && y=='q') return (true);
    if (x=='q' && y=='p') return (true);
    return (x==y && good(x));
}
bool ok(const string &s) {
    REP(i,s.size()) if (i<(int)s.size()-1-i && !goodPair(s[i],s[s.size()-1-i])) return (false);
    return (s.size()%2==0?true:good(s[s.size()/2]));
}
int main(void) {
    string s; cin>>s;
    cout<<(ok(s)?yes:no)<<endl;
    return 0;
}