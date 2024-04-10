#include<stdio.h>
int i,n;main(){scanf("%d",&n);n++;printf("%d\n0 0\n0 1\n",n*3+1);for(i=1;i<n;i++){printf("%d %d\n%d %d\n%d %d\n",i,i-1,i,i,i,i+1);}printf("%d %d\n%d %d",n,n-1,n,n);}