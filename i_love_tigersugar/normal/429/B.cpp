#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
int dx[]={1,0,-1};
int dy[]={0,1,0};
int a[MAX][MAX];
ll fr[2][MAX][MAX],to[2][MAX][MAX];
int m,n;
inline void maximize(ll &x,const ll &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
}
inline bool inside(int x,int y) {
    if (x<1) return (false);
    if (x>m) return (false);
    if (y<1) return (false);
    if (y>n) return (false);
    return (true);
}
void optimize(void) {
    FOR(i,1,m) FOR(j,1,n) {
        if (i==1 && j==1) fr[0][i][j]=a[i][j];
        else {
            fr[0][i][j]=-INF;
            FOR(k,0,1) if (inside(i-dx[k],j-dy[k])) maximize(fr[0][i][j],fr[0][i-dx[k]][j-dy[k]]+a[i][j]);
        }
    }
    FORD(i,m,1) FOR(j,1,n) {
        if (i==m && j==1) fr[1][i][j]=a[i][j];
        else {
            fr[1][i][j]=-INF;
            FOR(k,1,2) if (inside(i-dx[k],j-dy[k])) maximize(fr[1][i][j],fr[1][i-dx[k]][j-dy[k]]+a[i][j]);
        }
    }
    FORD(i,m,1) FORD(j,n,1) {
        if (i==m && j==n) to[0][i][j]=a[i][j];
        else {
            to[0][i][j]=-INF;
            FOR(k,0,1) if (inside(i+dx[k],j+dy[k])) maximize(to[0][i][j],to[0][i+dx[k]][j+dy[k]]+a[i][j]);
        }
    }
    FOR(i,1,m) FORD(j,n,1) {
        if (i==1 && j==n) to[1][i][j]=a[i][j];
        else {
            to[1][i][j]=-INF;
            FOR(k,1,2) if (inside(i+dx[k],j+dy[k])) maximize(to[1][i][j],to[1][i+dx[k]][j+dy[k]]+a[i][j]);
        }
    }
}
void process(void) {
    ll res=-INF;
    FOR(i,1,m) FOR(j,1,n)
        FOR(k,0,1) FOR(l,1,2) if (k+l!=2) {
            if (inside(i-dx[k],j-dy[k]) && inside(i-dx[l],j-dy[l]))
            if (inside(i+dx[k],j+dy[k]) && inside(i+dx[l],j+dy[l]))
                maximize(res,fr[0][i-dx[k]][j-dy[k]]+fr[1][i-dx[l]][j-dy[l]]+to[0][i+dx[k]][j+dy[k]]+to[1][i+dx[l]][j+dy[l]]);
    }
    cout<<res;
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    optimize();
    process();
    return 0;
}