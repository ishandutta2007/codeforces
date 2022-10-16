#include<bits/stdc++.h>
#define MAX   111
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
int change[MAX*MAX];
int a[MAX][MAX],m,n,q;
void process(void) {
    scanf("%d%d%d",&m,&n,&q);
    int cnt=0;
    FOR(i,1,m) FOR(j,1,n) a[i][j]=++cnt;
    REP(love,q) {
        int t; scanf("%d",&t);
        if (t==1) {
            int x; scanf("%d",&x);
            int tmp=a[x][1];
            FOR(j,2,n) a[x][j-1]=a[x][j];
            a[x][n]=tmp;
        } else if (t==2) {
            int y; scanf("%d",&y);
            int tmp=a[1][y];
            FOR(i,2,m) a[i-1][y]=a[i][y];
            a[m][y]=tmp;
        } else if (t==3) {
            int x,y,v; scanf("%d%d%d",&x,&y,&v);
            change[a[x][y]]=v;
        }
    }
    cnt=0;
    FOR(i,1,m) {
        FOR(j,1,n) printf("%d ",change[++cnt]);
        printf("\n");
    }
}
int main(void) {
    process();
    return 0;
}