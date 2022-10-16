#include<bits/stdc++.h>
#define MAX   111
typedef long long ll;
ll f[MAX][MAX];
int n,h;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&h); 
}
void optimize(void) {
    int i,j,k,l;    
    for (i=1;i<=n;i=i+1) f[0][i]=0LL;
    for (i=1;i<=n;i=i+1) f[i][0]=0LL;
    f[0][0]=1LL;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=n;j=j+1) {      
            for (k=1;k<=i;k=k+1) {
                for (l=0;l<j-1;l=l+1) {             
                    f[i][j]+=f[k-1][j-1]*f[i-k][l];
                    f[i][j]+=f[i-k][j-1]*f[k-1][l];
                }
                f[i][j]+=f[k-1][j-1]*f[i-k][j-1];               
                //printf("%d %d %d %d\n",k-1,j-1,n-k,j-1);
            }
            //printf("f(%d,%d)=%I64d\n",i,j,f[i][j]);
        }
    ll res=0LL;
    for (i=h;i<=n;i=i+1) res+=f[n][i];
    printf("%I64d",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}