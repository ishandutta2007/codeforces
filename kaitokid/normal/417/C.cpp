#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
scanf("%d%d",&n,&k);
if(n*(n-1)/2<n*k){printf("-1");return 0;}
printf("%d\n",n*k);
for(int i=1;i<=n;i++)
{
for(int j=i+1;j<=i+k;j++){if(j<=n)printf("%d %d\n",i,j);
else printf("%d %d\n",i,j-n);
}


}
return 0;}