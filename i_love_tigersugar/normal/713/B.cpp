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
struct Rectangle {
    int top,bot,left,right;
    Rectangle() {
        top=bot=left=right=0;
    }
    Rectangle(int t,int l,int b,int r) {
        top=t; left=l; bot=b; right=r;
    }
    void print(void) const {
        printf(" %d %d %d %d\n",top,left,bot,right);
    }
};
int n;
int query(int x1,int y1,int x2,int y2,bool swapRowCol) {
    if (swapRowCol) {
        swap(x1,y1);
        swap(x2,y2);
    }
    assert(1<=x1 && x1<=x2 && x2<=n);
    assert(1<=y1 && y1<=y2 && y2<=n);
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    int ans; scanf("%d",&ans);
    return (ans);
}
int findTopLine(int x1,int y1,int x2,int y2,bool swapRowCol) {
    if (swapRowCol) {
        swap(x1,y1);
        swap(x2,y2);
    }
    int L=x1;
    int R=x2;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (query(R,y1,x2,y2,swapRowCol)>0?R:L);
        int M=(L+R)>>1;
        if (query(M,y1,x2,y2,swapRowCol)>0) L=M; else R=M-1;
    }
}
int findBotLine(int x1,int y1,int x2,int y2,bool swapRowCol) {
    if (swapRowCol) {
        swap(x1,y1);
        swap(x2,y2);
    }
    int L=x1;
    int R=x2;
    while (true) {
        if (L==R) return (L);
        if (R-L==1) return (query(x1,y1,L,y2,swapRowCol)>0?L:R);
        int M=(L+R)>>1;
        if (query(x1,y1,M,y2,swapRowCol)>0) R=M; else L=M+1;
    }
}
int rowLine(void) {
    int line=findBotLine(1,1,n,n,false);
    if (line<n && query(1,1,line,n,false)==1 && query(line+1,1,n,n,false)==1) return (line);
    return (-1);
}
int colLine(void) {
    int line=findBotLine(1,1,n,n,true);
    if (line<n && query(1,1,n,line,false)==1 && query(1,line+1,n,n,false)==1) return (line);
    return (-1);
}
Rectangle findRectangle(int x1,int y1,int x2,int y2) {
    int top=findTopLine(x1,y1,x2,y2,false);
    int bot=findBotLine(x1,y1,x2,y2,false);
    int left=findTopLine(x1,y1,x2,y2,true);
    int right=findBotLine(x1,y1,x2,y2,true);
    return (Rectangle(top,left,bot,right));
}
void process(void) {
    scanf("%d",&n);
    int line=rowLine();
    Rectangle first,second;
    if (line>0) {
        first=findRectangle(1,1,line,n);
        second=findRectangle(line+1,1,n,n);
    } else {
        line=colLine();
        assert(line>0);
        first=findRectangle(1,1,n,line);
        second=findRectangle(1,line+1,n,n);
    }
    printf("!"); first.print(); second.print(); printf("\n");
    fflush(stdout);
}
int main(void) {
    process();
    return 0;
}