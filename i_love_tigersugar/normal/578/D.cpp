#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
char s[MAX];
long long f[MAX][10];
int n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    FOR(i,1,n) s[i]-='a';
}
void optimize(void) {
    if (n==1) {
        cout<<m-1<<endl;
        return;
    }
    REP(i,m) f[1][((i!=s[1])<<1)|((i!=s[1] && i!=s[2])<<2)]+=1;
    FOR(i,1,n-1) REP(j,8) if (f[i][j]>0) {
        int cur[5];
        REP(k,3) cur[k]=min(i,i-1+k)-BIT(j,k);
        REP(t,m) {
            int next[5];
            int stt=0;
            REP(k,3) {
                next[k]=0;
                if (k>0) next[k]=max(next[k],next[k-1]);
                if (k<2) next[k]=max(next[k],cur[k+1]);
                if (t==s[i+k]) next[k]=max(next[k],cur[k]+1);
                if (min(i+1,i+k)-next[k]>1) stt=-1;
                else stt|=(min(i+1,i+k)-next[k])<<k;
            }
            if (stt>=0) f[i+1][stt]+=f[i][j];
        }
    }
    long long res=0;
    REP(i,8) if (BIT(i,1)) res+=f[n][i];
    cout<<res<<endl;
}
int main(void) {
    init();
    optimize();
    return 0;
}