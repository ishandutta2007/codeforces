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
int xa,ya,xb,yb,xc,yc;
bool oneCase(void) {
    if (xa==xb && xb==xc) return (true);
    if (ya==yb && yb==yc) return (true);
    return (false);
}
bool checkMid(int x,int y) {
    if (x!=xa && y!=ya) return (false);
    if (x!=xb && y!=yb) return (false);
    if (x!=xc && y!=yc) return (false);
    if (x==xa && x==xb && 1LL*(y-ya)*(y-yb)<0) return (false);
    if (y==ya && y==yb && 1LL*(x-xa)*(x-xb)<0) return (false);
    if (x==xb && x==xc && 1LL*(y-yb)*(y-yc)<0) return (false);
    if (y==yb && y==yc && 1LL*(x-xb)*(x-xc)<0) return (false);
    if (x==xc && x==xa && 1LL*(y-yc)*(y-ya)<0) return (false);
    if (y==yc && y==ya && 1LL*(x-xc)*(x-xa)<0) return (false);
    return (true);
}
bool twoCase(void) {
    vector<int> valX,valY;
    valX.push_back(xa);
    valX.push_back(xb);
    valX.push_back(xc);
    valY.push_back(ya);
    valY.push_back(yb);
    valY.push_back(yc);
    FORE(it,valX) FORE(jt,valY) if (checkMid(*it,*jt)) return (true);
    return (false);
}
int main(void) {
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    if (oneCase()) cout<<1<<endl;
    else if (twoCase()) cout<<2<<endl;
    else cout<<3<<endl;
    return 0;
}