#include<bits/stdc++.h>
#define MAX   1010
typedef long long ll;
const ll mod=(ll)1e9+7;
ll c[MAX][MAX];
ll f[MAX][3][3][MAX];
ll p[MAX];
ll g[MAX];
int n,q;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&q);
}
void add(ll &x,const ll &y) {
    x=(x+y)%mod;
}
void optimize(void) {
    f[0][1][0][0]=1LL;
    int i,lo,le,j;
    for (i=0;i<n;i=i+1)
        for (j=0;j<=i;j=j+1)
            for (lo=0;lo<2;lo=lo+1)
                for (le=0;le<2;le=le+1)
                    if (f[i][lo][le][j]>0LL) {
                        //printf("f(%d,%d,%d,%d)=%I64d\n",i,lo,le,j,f[i][lo][le][j]);
                        if ((i+1)%2==0) {                           
                            add(f[i+1][true][le][j],f[i][lo][le][j]);
                            //printf("\tUpdate to %d %d %d %d\n",i+1,true,le,j);
                            if (lo) {
                                add(f[i+1][true][le][j+1],f[i][lo][le][j]);
                                //printf("\tUpdate to %d %d %d %d\n",i+1,true,le,j+1);
                            }
                            if (i+2<=n) {
                                add(f[i+1][false][le][j+1],f[i][lo][le][j]);
                                //printf("\tUpdate to %d %d %d %d\n",i+1,false,le,j+1);
                            }
                        }
                        else {
                            add(f[i+1][lo][true][j],f[i][lo][le][j]);
                            //printf("\tUpdate to %d %d %d %d\n",i+1,lo,true,j);
                            if (le) {
                                add(f[i+1][lo][true][j+1],f[i][lo][le][j]);
                                //printf("\tUpdate to %d %d %d %d\n",i+1,lo,true,j+1);
                            }
                            if (i+2<=n) {
                                add(f[i+1][lo][false][j+1],f[i][lo][le][j]);
                                //printf("\tUpdate to %d %d %d %d\n",i+1,lo,false,j+1);
                            }
                        }
                    }
}
void combination(void) {
    int i,j,lo,le;
    p[0]=1LL;
    for (i=1;i<=1000;i=i+1) {
        c[i][0]=0LL;
        c[0][i]=1LL;
        p[i]=(p[i-1]*i)%mod;
    }
    c[0][0]=1LL;
    for (i=1;i<=1000;i=i+1)
        for (j=1;j<=1000;j=j+1) {
            if (i>j) c[i][j]=0LL;
            if (i==j) c[i][j]=1LL;
            if (i<j) c[i][j]=(c[i-1][j-1]+c[i][j-1])%mod;
        }
    for (i=n;i>=0;i=i-1) {
        for (lo=0;lo<2;lo=lo+1)
            for (le=0;le<2;le=le+1)
                add(g[i],f[n][lo][le][i]);
        //printf("g(%d) = %I64d\n",i,g[i]);
        g[i]=(g[i]*p[n-i])%mod;
        //printf("g(%d) = %I64d\n",i,g[i]);
        for (j=i+1;j<=n;j=j+1)
            g[i]=(g[i]-(g[j]*c[i][j])%mod+mod)%mod;
        //printf("g(%d) = %I64d\n",i,g[i]);
    }
    printf("%I64d",g[q]);
}
int main(void) {
    init();
    optimize();
    combination();
    return 0;
}