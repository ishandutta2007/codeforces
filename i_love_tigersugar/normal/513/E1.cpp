#include<bits/stdc++.h>
#define MAXN   30030
#define MAXM   205
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int INF=(int)2e9+7;
int f[MAXN][MAXM][2][3][3];
int n,m;
int a[MAXN];
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void optimize(void) {
    memset(f,-0x3f,sizeof f);
    int res=-INF;
    f[0][1][0][1][2]=0;
    f[0][1][0][1][0]=0;
    REP(pos,n+1) REP(cur,m+1) REP(have,2) REP(fiSign,3) REP(seSign,3)
        if (f[pos][cur][have][fiSign][seSign]>-INF) {
            int val=f[pos][cur][have][fiSign][seSign];
            //printf("F %d %d %d %d %d is %d\n",pos,cur,have,fiSign,seSign,val);
            if (pos<n) {
                maximize(f[pos+1][cur][true][fiSign][seSign],val+a[pos+1]*(fiSign-1+seSign-1));
                if (!have) maximize(f[pos+1][cur][false][fiSign][seSign],val);
            }
            if (have) {
                if (cur==m) maximize(res,val);
                else {
                    if (cur+1==m) maximize(f[pos][cur+1][false][2-seSign][1],val);
                    else {
                        maximize(f[pos][cur+1][false][2-seSign][0],val);
                        maximize(f[pos][cur+1][false][2-seSign][2],val);
                    }
                }
            }
        }
    printf("%d\n",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("tmp.txt","r",stdin);
#endif // ONLINE_JUDGE
    init();
    optimize();
    return 0;
}