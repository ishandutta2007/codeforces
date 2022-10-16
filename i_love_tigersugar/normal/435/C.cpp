#include<bits/stdc++.h>
#define MAX   3030
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX];
char r[MAX][MAX];
int ch[]={92,47};
int dx[]={1,-1};
int dy[]={1,1};
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void move(int &x,int &y,int d,int k) {
    REP(i,k) r[x-d+i*dx[d]][y+i*dy[d]]=ch[d];
    x+=dx[d]*k;
    y+=dy[d]*k;
}
int last(int x) {
    FORD(i,MAX-1,0) if (r[x][i]!=' ') return (i);
    return (-1);
}
void process(void) {
    int tmp=0;
    int del=0;
    FOR(i,1,n) {
        tmp+=dx[i&1]*a[i];
        if (del>tmp) del=tmp;
    }
    int x=-del;
    int y=0;
    REP(i,MAX) REP(j,MAX) r[i][j]=' ';
    FOR(i,1,n) move(x,y,i&1,a[i]);
}
void print(void) {
    int lim=0;
    REP(i,MAX) {
        int t=last(i);
        if (t<0) break;
        if (lim<t) lim=t;
    }
    REP(i,MAX) {
        if (last(i)<0) return;
        REP(j,lim+1) printf("%c",r[i][j]);
        printf("\n");
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    print();
    return 0;
}