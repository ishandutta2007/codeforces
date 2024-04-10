#include<bits/stdc++.h>
#define MAX   111
#define LIM   58
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
const int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
const int np=16;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
int f[MAX][1<<np];
ii t[MAX][1<<np];
int a[MAX],s[MAX];
int n;
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
inline int Abs(int x) {
    return (x<0?-x:x);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,LIM) REP(j,np) if (i%pr[j]==0) s[i]|=1<<j;
}
void optimize(void) {
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    REP(i,n) REP(j,1<<np) if (f[i][j]<INF)
        FOR(k,1,LIM) if ((j&s[k])==0) {
            int v=f[i][j]+Abs(a[i+1]-k);
            if (v<f[i+1][j|s[k]]) {
                f[i+1][j|s[k]]=v;
                t[i+1][j|s[k]]=ii(j,k);
            }
        }
}
void trace(void) {
    int j=-1;
    REP(i,1<<np) if (f[n][i]<INF && (j<0 || f[n][i]<f[n][j])) j=i;
    assert(j>=0);
    cerr<<f[n][j]<<endl;
    vector<int> res;
    FORD(i,n,1) {
        //printf("STATE %d %d\n",j,f[i][j]);
        res.push_back(t[i][j].se);
        j=t[i][j].fi;
    }
    reverse(res.begin(),res.end());
    REP(i,n) printf("%d ",res[i]);
}
int main(void) {
    init();
    optimize();
    trace();
    return 0;
}