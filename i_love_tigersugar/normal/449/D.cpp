#include<bits/stdc++.h>
#define MAX   1048576
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
const int mod=(int)1e9+7;
int pw[MAX],cnt[MAX],f[MAX];
inline void add(int &x,int y) {
    x=(x+y)%mod;
}
inline void sub(int &x,int y) {
    x=(x-y+mod)%mod;
}
inline int bitcount(int x) {
    int ret=0;
    REP(i,21) if (BIT(x,i)) ret++;
    return (ret);
}
void init(void) {
    int n;
    scanf("%d",&n);
    REP(zz,n) {
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }
}
void count(int l,int r) {
    if (l+1==r) {
        f[l]=cnt[l];
        return;
    }
    int m=(l+r)>>1;
    count(l,m);
    count(m,r);
    FOR(i,l,m-1) f[i]+=f[i+m-l];
}
void process(void) {
    count(0,MAX);
    pw[0]=1;
    FOR(i,1,MAX-1) pw[i]=2LL*pw[i-1]%mod;
    int res=0;
    REP(i,MAX) {
        if (bitcount(i)%2==0) add(res,pw[f[i]]);
        else sub(res,pw[f[i]]);
    }
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}