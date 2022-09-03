#include<cstdio>
#include<algorithm>

int a[2222];
int t[2222];

int main()
{
int i,n;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
t[i]=a[i];
}
std::sort(t,t+n);
for(i=0;i<n;i++)printf("%d ",n-(std::upper_bound(t,t+n,a[i])-t)+1);
}