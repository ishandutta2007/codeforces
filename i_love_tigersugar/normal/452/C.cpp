#include<bits/stdc++.h>
int main(void) {
    int m,n;
    scanf("%d%d",&n,&m);
    if (m==1) printf("%.9lf\n",1.0/n);
    else printf("%.9lf",1.0/n+(m-1.0)*(n-1.0)/n/(m*n-1.0));
    return 0;
}