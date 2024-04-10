#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof(((v).begin()) i=(v).begin();i!=(v).end();i++)
char a[MAX][MAX];
int n,m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char ch[]="RDLU";
void init(void) {
    int k;
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) scanf("%s",a[i]+1);
}
bool contain(int x,int y,int d) {
    if (x<1 || x>m) return (false);
    if (y<1 || y>n) return (false);
    return (a[x][y]==ch[d]);
}
void process(void) {
    FOR(j,1,n) {
        int cnt=0;
        FOR(i,1,m) REP(d,4) if (contain(i-dx[d]*(i-1),j-dy[d]*(i-1),d)) cnt++;
        printf("%d",cnt);
        if (j<n) printf(" ");
    }
}
int main(void) {
    init();
    process();
    return 0;
}