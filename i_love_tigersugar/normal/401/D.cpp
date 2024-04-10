#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define bit(x,i) ((x)&(1<<(i)))
#define add(x,y) (x)+=(y)
using namespace std;
typedef long long ll;
ll f[(1<<18)+7][107];
char s[22];
int n,m;
void init(void) {
    scanf("%s",s);
    n=strlen(s);
    REP(i,n) s[i]-=48;
    scanf("%d",&m);
}
void optimize(void) {
    f[0][0]=1;
    REP(i,1<<n) REP(j,m) if (f[i][j]>0) {
        bool c[11];
        REP(k,10) c[k]=false;
        REP(k,n) if (!bit(i,k) && !c[s[k]]) {
            c[s[k]]=true;
            if (i>0 || s[k]>0) add(f[i^(1<<k)][(j*10+s[k])%m],f[i][j]);
        }
    }
    cout << f[(1<<n)-1][0];
}
int main(void) {
    init();
    optimize();
    return 0;
}