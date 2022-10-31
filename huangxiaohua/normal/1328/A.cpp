#include<stdio.h>
main(){int q,n,k,i,j;scanf("%d",&q);for(i=1;i<=q;i++){scanf("%d%d",&n,&k);printf("%d\n",(k-n%k)%k);}}