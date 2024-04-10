#include <stdio.h>
#define X ){puts("-1");return 0;}
#define Y ;continue;}
using namespace std;int n,m,i,a[100500],r[100500],t;long long s;main(){scanf("%d%d",&m,&n);for(i=1;i<=n;i++){scanf("%d",&a[i]);s+=a[i];if(a[i]>m+1-i X }if(s<m X s-=m;r[1]=1;for(i=2;i<=n;i++){if(s==0){r[i]=r[i-1]+a[i-1] Y t=a[i-1]-1;if(s>=t){r[i]=r[i-1]+1;s-=t Y else{r[i]=r[i-1]+a[i-1]-s;s=0 Y }for(i=1;i<=n;i++){printf("%d ",r[i]);}}