#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
pair<int,int> a[MAX];
int n,m,dx,dy;
int cntX[MAX],cntY[MAX],cntMod[MAX];
map<pair<int,int>,int> cntCell;
void init(void) {
    scanf("%d%d%d%d",&m,&n,&dx,&dy);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
}
int inverse(int x) {
    REP(i,m) if (1LL*i*x%m==1) return (i);
    assert(false);
}
void process(void) {
    if (dx%m==0 && dy%m==0) {
        FOR(i,1,n) cntCell[a[i]]++;
        int res=0;
        FORE(it,cntCell) res=max(res,it->se);
        FORE(it,cntCell) if (res==it->se) {
            printf("%d %d",it->fi.fi,it->fi.se);
            return;
        }
    }
    if (dx%m==0) {
        FOR(i,1,n) cntX[a[i].fi]++;
        int res=0;
        REP(i,m) res=max(res,cntX[i]);
        REP(i,m) if (res==cntX[i]) {
            printf("%d %d",i,0);
            return;
        }
    }
    if (dy%m==0) {
        FOR(i,1,n) cntY[a[i].se]++;
        int res=0;
        REP(i,m) res=max(res,cntY[i]);
        REP(i,m) if (res==cntY[i]) {
            printf("%d %d",0,i);
            return;
        }
    }
    int dxInv=inverse(dx);
    int dyInv=inverse(dy);
    FOR(i,1,n) {
        int x=a[i].fi;
        int y=a[i].se;
        int tmp=(1LL*x*dxInv%m-1LL*y*dyInv%m+m)%m;
        cntMod[tmp]++;
    }
    int res=0;
    REP(i,m) res=max(res,cntMod[i]);
    REP(i,m) if (res==cntMod[i]) {
        FOR(j,1,n) {
            int x=a[j].fi;
            int y=a[j].se;
            int tmp=(1LL*x*dxInv%m-1LL*y*dyInv%m+m)%m;
            if (tmp==i) {
                printf("%d %d",x,y);
                return;
            }
        }
    }
}
int main(void) {
    init();
    process();
    return 0;
}