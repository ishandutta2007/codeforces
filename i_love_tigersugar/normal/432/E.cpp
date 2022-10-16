#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX][MAX];
int m,n;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void init(void) {
    scanf("%d%d",&m,&n);
    memset(a,-1,sizeof a);
}
inline bool inside(int x,int y) {
    if (x<1) return (false);
    if (y<1) return (false);
    if (x>m) return (false);
    if (y>n) return (false);
    return (true);
}
inline int minval(int x,int y) {
    set<int> s;
    REP(i,4) if (inside(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]>=0) s.insert(a[x+dx[i]][y+dy[i]]);
    REP(i,MAX) if (s.find(i)==s.end()) return (i);
}
void fixrec(int x,int y,int k,int v) {
    REP(i,k) REP(j,k) a[x+i][y+j]=v;
}
bool expand(int x,int y,int k,int v) {
    if (k==1) return (true);
    if (x+k-1>m) return (false);
    if (y+k-1>n) return (false);
    REP(i,k) {
        if (a[x+k-1][y+i]>=0) return (false);
        if (a[x+i][y+k-1]>=0) return (false);
    }
    return (minval(x,y+k-1)==v);
}
void process(void) {
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]<0) {
        int t=1;
        int v=minval(i,j);
        while (expand(i,j,t,v)) t++;
        t--;
        fixrec(i,j,t,v);
    }
    FOR(i,1,m) {
        FOR(j,1,n) printf("%c",a[i][j]+'A');
        printf("\n");
    }
}
int main(void) {
    init();
    process();
    return 0;
}