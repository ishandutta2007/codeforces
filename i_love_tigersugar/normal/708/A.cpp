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
int main(void) {
    string s; cin>>s;
    REP(i,s.size()) if (s[i]!='a') {
        FOR(j,i,(int)s.size()) if (j==s.size() || s[j]=='a') {
            REP(k,i) printf("%c",s[k]);
            FOR(k,i,j-1) printf("%c",s[k]-1);
            FOR(k,j,(int)s.size()-1) printf("%c",s[k]);
            printf("\n");
            return 0;
        }
        assert(false);
    }
    REP(love,(int)s.size()-1) printf("%c",'a');
    printf("%c\n",'z');
    return 0;
}