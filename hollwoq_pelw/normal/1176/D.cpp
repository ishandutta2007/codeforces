#include<stdio.h>
#define P 2750132
int n,p[P],c,d[P],b[P],i,j;main(){for(i=2;i<2000;i++)if(!p[i])for(j=i*i;j<P;j+=i)p[j]=-1;for(i=2;i<P;i++)p[i]=p[i]<0?0:++c;for(i=1;i<P;i++)for(j=2*i;j<P;j+=i)d[j]=i;for(scanf("%d",&n),n<<=1;n--;)scanf("%d",&i),b[i]++;for(i=P-1;i;i--){(p[i]?b[p[i]]:b[d[i]])-=b[i];while(b[i]--)printf("%d ",p[i]?p[i]:i);}}