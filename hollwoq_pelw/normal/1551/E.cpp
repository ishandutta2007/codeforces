#include<stdio.h>
int t,i,j,n,k,r,f[2002],a[2002];
main(){
if(!t)scanf("%d",&t);
scanf("%d %d",&n,&k),r=n;
for (i=1;i<=n;i++) {
scanf("%d",a+i),f[i]=i>=a[i];
for (j=1;j<i;j++)
if(j>=a[j]&&i-a[i]>=j-a[j]&&a[i]>a[j]&&f[i]<f[j]+1)
f[i]=f[j]+1;
if(f[i]>=k&&r>i-a[i])r=i-a[i];
}
printf("%d\n", r>=n?-1:r);
if(--t)main();
}