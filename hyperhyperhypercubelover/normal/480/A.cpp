#include<cstdio>
#include<algorithm>

std::pair<int,int> a[5000];

int main()
{
int i,j=0,n;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d%d",&a[i].first,&a[i].second);
std::sort(a,a+n);
for(i=0;i<n;i++)
{
if(j<=a[i].second)j=a[i].second;
else j=a[i].first;
}
printf("%d",j);
}