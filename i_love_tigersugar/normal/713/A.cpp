#include<bits/stdc++.h>
#define MAX   1000100
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
multiset<long long> match[MAX];
int getMask(long long x) {
    int res=0;
    REP(i,20) {
        if (x%2!=0) res|=MASK(i);
        x/=10;
    }
    return (res);
}
int main(void) {
    ios::sync_with_stdio(false);
    int q; cin>>q;
    REP(love,q) {
        string s; cin>>s;
        if (s=="+") {
            long long x; cin>>x;
            match[getMask(x)].insert(x);
        }
        if (s=="-") {
            long long x; cin>>x;
            multiset<long long> &cur=match[getMask(x)];
            cur.erase(cur.find(x));
        }
        if (s=="?") {
            string path; cin>>path;
            int mask=0;
            FORE(it,path) mask=mask*2+*it-'0';
            printf("%d\n",mask<MAX?(int)match[mask].size():0);
        }
    }
    return 0;
}