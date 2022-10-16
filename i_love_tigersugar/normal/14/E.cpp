#include<bits/stdc++.h>
typedef long long ll;
ll f[22][22][22][6][6];
int n,q;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&q); 
}
void optimize(void) {
    int i,j,k,l,m,t;
    for (i=1;i<=4;i=i+1)
        for (j=1;j<=4;j=j+1)
            if (i!=j)
                f[2][0][0][i][j]++;
    for (i=1;i<n;i=i+1)
        for (j=0;j<=n;j=j+1)
            for (k=0;k<=n;k=k+1)
                for (l=1;l<=4;l=l+1)
                    for (m=1;m<=4;m=m+1)
                        if (f[i][j][k][l][m]>0LL)
                            for (t=1;t<=4;t=t+1)
                                if (t!=m)
                                    f[i+1][j+(l<m && m>t)][k+(l>m && m<t)][m][t]+=f[i][j][k][l][m];
    ll res=0LL;
    for (i=1;i<=4;i=i+1)
        for (j=1;j<=4;j=j+1)
            if (i!=j)
                res+=f[n][q][q-1][i][j];
    printf("%I64d",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}