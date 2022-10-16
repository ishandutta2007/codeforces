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
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    Point(int _x,int _y) {
        x=_x;y=_y;
    }
    Point operator + (const Point &a) const {
        return (Point(x+a.x,y+a.y));
    }
};
const int board[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
const int m=4;
const int n=3;
const char yes[]="YES";
const char no[]="NO";
Point pos(int x) {
    REP(i,m) REP(j,n) if (board[i][j]==x) return (Point(i,j));
    assert(false);
}
char a[13];
int len;
Point dir[13];
bool inside(const Point &p) {
    if (p.x<0 || p.x>=m || p.y<0 || p.y>=n) return (false);
    return (board[p.x][p.y]>=0);
}
int main(void) {
    scanf("%d",&len);
    scanf("%s",a);
    FOR(i,-5,5) FOR(j,-5,5) if (i!=0 || j!=0) {
        bool ok=true;
        REP(k,len) if (!inside(pos(a[k]-'0')+Point(i,j))) ok=false;
        if (ok) {
            printf("%s\n",no);
            return 0;
        }
    }
    printf("%s\n",yes);
    return 0;
}