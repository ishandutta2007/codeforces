#include<bits/stdc++.h>
#define MAXS   100100
#define MAXT   33
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
char s[MAXS],t[MAXT];
int ls,lt,f[MAXS][MAXT],next[MAXT][MAXT],kmp[MAXT];
void init(void) {
    scanf("%s",s+1);
    scanf("%s",t+1);
    ls=strlen(s+1);
    lt=strlen(t+1);
}
void prepare(void) {
    int j=kmp[1]=0;
    FOR(i,2,lt) {
        while (j>0 && t[j+1]!=t[i]) j=kmp[j];
        if (t[j+1]==t[i]) j++;
        kmp[i]=j;
    }
    REP(i,lt+1) REP(j,26) {
        int k=i;
        while (k>0 && (k==lt || t[k+1]!=j+'a')) k=kmp[k];
        if (k<lt && t[k+1]==j+'a') k++;
        next[i][j]=k;
    }
}
void optimize(void) {
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    REP(i,ls) REP(j,lt) if (f[i][j]<=ls) {
        minimize(f[i+1][0],f[i][j]+1);
        if (next[j][s[i+1]-'a']<lt) minimize(f[i+1][next[j][s[i+1]-'a']],f[i][j]);
    }
    int res=ls;
    REP(j,lt) minimize(res,f[ls][j]);
    printf("%d\n",res);
}
int main(void) {
    init();
    prepare();
    optimize();
    return 0;
}