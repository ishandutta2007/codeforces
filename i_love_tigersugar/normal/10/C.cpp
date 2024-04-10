#include<bits/stdc++.h>
typedef long long ll;
int n;
ll s;
int p[13];
int main(void) {
    s=0LL;
    scanf("%d",&n);
    if (n<=13) {
        int i,j,k;
        for (i=1;i<=n;i=i+1)
            for (j=1;j<=n;j=j+1)
                for (k=1;k<=n;k=k+1)
                    if ((i*j!=k) && ((i*j-k)%9==0)) s++;
        printf("%I64d",s);
        return 0;
    }
    int i,j;
    for (i=0;i<9;i=i+1) p[i]=(n-i)/9+(i>0);
    for (i=0;i<9;i=i+1)
        for (j=0;j<9;j=j+1)
            s=s+(ll)p[i]*p[j]*p[(i*j)%9];
    //printf("%I64d\n",s);
    for (i=1;i<=n;i=i+1) s=s-(n/i);
    printf("%I64d",s);
    return 0;
}