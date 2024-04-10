#include<bits/stdc++.h>
#define MAX   2222
typedef long long ll;
const ll mod=(ll)1e9+7;
int n;
int p[MAX];
int f[MAX];
int a,b;
ll fac[MAX];
ll c[MAX][MAX];
ll r[MAX];
ll res;
void inc(ll &x,const ll &y) {
    x=(x+y%mod+mod)%mod;
}
void init(void) {
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i=i+1) {
        p[i]=-1;
        f[i]=-1;
    }
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&j);
        p[i]=j;
        if (j>0) f[j]=i;
    }
    for (i=1;i<=n;i=i+1) {
        c[i][0]=0LL;
        c[0][i]=1LL;
    }
    a=0;
    b=0;
    for (i=1;i<=n;i=i+1) {
        if (f[i]<0 && p[i]<0) b++;
        if (f[i]<0 && p[i]>0) a++;
    }
    c[0][0]=1LL;
    fac[0]=1LL;
    for (i=1;i<=n;i=i+1) fac[i]=(fac[i-1]*i)%mod;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=n;j=j+1) {
            if (i>j) c[i][j]=0LL;
            if (i==j) c[i][j]=1LL;
            if (i<j) c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
        }
}
ll result(const int &i) {
    return ((c[i][b]*fac[a+b-i])%mod);
}
void count(void) {
    res=fac[a+b];
    int i,j;
    ll t,v;
    for (i=1;i<=b;i=i+1) r[i]=1LL;
    for (i=1;i<=b;i=i+1) {
        t=-r[i];
        v=(t*result(i))%mod;
        inc(res,v);
        for (j=i+1;j<=b;j=j+1)
            inc(r[j],t*c[i][j]);
    }
    printf("%I64d",res);
}
int main(void) {
    init();
    count();
    return 0;
}