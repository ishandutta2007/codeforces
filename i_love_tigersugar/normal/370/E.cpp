#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int a[MAX],res[MAX];
int cpos[MAX][7],caft[MAX][7];
vector<ii> fix;
int n,lrest;
void exitno(void) {
    printf("-1");
    exit(0);
}
bool ok(int x) {
    return (2<=x && x<=5);
}
bool canput(int x,int y) {
    return (2*y<=x && x<=5*y);
}
int canafter(int p,int x) {
    FOR(i,1,5) if (cpos[p][i]>=0 && ok(x+i)) return (i);
    return (-1);
}
bool canrest(int x) {
    return (x>=0 && x!=1);
}
void checksol(int x) {
    FOR(i,1,5) if (cpos[x][i]>=0) return;
    //printf("FAIL %d\n",x);
    exitno();
}
void init(void) {
    memset(cpos,-1,sizeof cpos);
    memset(caft,-1,sizeof caft);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    if (a[1]>1) exitno(); else a[1]=1;
    FOR(i,1,n) if (a[i]>0) fix.push_back(ii(a[i],i));
    FOR(i,1,fix.size()-1) if (fix[i].fi<fix[i-1].fi) exitno();
}
void buildsol(void) {
    //printf("BUILD\n");
    cpos[1][1]=1;
    FOR(i,1,fix.size()-1) {
        //printf("Processing %d %d\n",fix[i].fi,fix[i].se);
        if (fix[i].fi>fix[i-1].fi) {
            //printf("Normal case\n");
            REP(j,5) FOR(k,1,5)
                if (canafter(fix[i-1].se,j)>=0 && canput(fix[i].se-fix[i-1].se-j-k,fix[i].fi-fix[i-1].fi-1)) {
                    //printf("Req %d %d\n",fix[i].se-fix[i-1].se-j-k+1,fix[i].fi-fix[i-1].fi-1);
                    //printf("CASE OK %d %d\n",j,k);
                    caft[fix[i-1].se][j]=canafter(fix[i-1].se,j);
                    cpos[fix[i].se][k]=j;
                }
        }
        else {
            //printf("EQU case\n");
            FOR(j,2,5) if (j>fix[i].se-fix[i-1].se && cpos[fix[i-1].se][j-(fix[i].se-fix[i-1].se)]>=0)
                cpos[fix[i].se][j]=j-(fix[i].se-fix[i-1].se);
        }
        checksol(fix[i].se);
    }
    int lst=fix[fix.size()-1].se;
    lrest=-1;
    REP(i,5) if (canafter(lst,i)>=0 && canrest(n-lst-i)) {
        lrest=max(lrest,n-lst-i);
        caft[lst][i]=canafter(lst,i);
    }
    //printf("lrest %d\n",lrest);
    if (lrest<0) exitno();
}
void fill(int l,int r,int vl,int vr) {
    //printf("FILL from %d %d with %d to %d\n",l,r,vl,vr);
    assert(canput(r-l+1,vr-vl+1));
    int x;
    for (x=5;x>=2;x=x-1) if (r-l+1>=x*(vr-vl+1)) break;
    assert(ok(x));
    int add=r-l+1-x*(vr-vl+1);
    int pos=l;
    FOR(i,vl,vr) REP(j,x+(i<vl+add)) {
        res[pos]=i;
        pos++;
    }
}
void trace(void) {
    //printf("TRACE\n");
    FOR(i,1,n) res[i]=a[i];
    printf("%d\n",fix[fix.size()-1].fi+lrest/2);
    FOR(i,fix[fix.size()-1].se,n-lrest) res[i]=fix[fix.size()-1].fi;
    int val=fix[fix.size()-1].fi;
    FOR(i,1,lrest) {
        if (i%2==1) val++;
        res[n-lrest+i]=val;
    }
    res[n]=fix[fix.size()-1].fi+lrest/2;
    int y=caft[fix[fix.size()-1].se][n-lrest-fix[fix.size()-1].se];
    FORD(i,fix.size()-1,1) {
        if (fix[i].fi>fix[i-1].fi) {
            //printf("CUR pos %d\n",fix[i].se);
            //printf("CHOOS`E pos %d\n",y);
            int x=cpos[fix[i].se][y];
            //printf("Prev after %d\n",x);
            FOR(j,1,x) res[fix[i-1].se+j]=fix[i-1].fi;
            REP(j,y) res[fix[i].se-j]=fix[i].fi;
            fill(fix[i-1].se+x+1,fix[i].se-y,fix[i-1].fi+1,fix[i].fi-1);
            y=caft[fix[i-1].se][x];
        }
        else {
            FOR(j,fix[i-1].se+1,fix[i].se-1) res[j]=fix[i].fi;
            y=cpos[fix[i].se][y];
        }
    }
    FOR(i,1,n) printf("%d ",res[i]);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
    printf("Start\n");
#endif
    init();
    buildsol();
    trace();
    return 0;
}