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
const char dir[]="UDLR";
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
bool ok(const string &s) {
    int x=0;
    int y=0;
    FORE(it,s) REP(i,4) if (*it==dir[i]) {
        x+=dx[i];
        y+=dy[i];
    }
    return (x==0 && y==0);
}
int main(void) {
    string s;
    cin>>s>>s;
    int res=0;
    REP(i,s.size()) FOR(j,i,(int)s.size()-1) if (ok(s.substr(i,j-i+1))) res++;
    printf("%d\n",res);
    return 0;
}