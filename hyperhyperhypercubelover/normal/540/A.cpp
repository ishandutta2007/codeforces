#include<cstdio>
#include<algorithm>

char a[1111];
char b[1111];

int main()
{
int i,n,r=0;
scanf("%d%s%s",&n,a,b);
for(i=0;i<n;i++)
{
r+=std::min((a[i]-b[i]+10)%10,(b[i]-a[i]+10)%10);
}
printf("%d",r);
}