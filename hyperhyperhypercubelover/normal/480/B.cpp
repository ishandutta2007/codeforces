#include<cstdio>

int a[100000];

int main()
{
int f1,f2;
int i,j,n,x,y;
scanf("%d%*d%d%d",&n,&x,&y);
for(i=0;i<n;i++)scanf("%d",&a[i]);
f1=f2=0;
i=j=0;
while(j<n)
{
if(a[j]-a[i]==x)
{
f1=1;
break;
}
if(a[j]-a[i]<x)j++;
else i++;
}
i=j=0;
while(j<n)
{
if(a[j]-a[i]==y)
{
f2=1;
break;
}
if(a[j]-a[i]<y)j++;
else i++;
}
if(f1&&f2)puts("0");
else if(f1&&!f2)printf("1\n%d",y);
else if(!f1&&f2)printf("1\n%d",x);
else
{
i=j=0;
while(j<n)
{
if(a[j]-a[i]==x+y)break;
if(a[j]-a[i]<x+y)j++;
else i++;
}
if(j<n)printf("1\n%d",a[i]+x);
else
{
i=j=0;
while(j<n)
{
if(a[j]-a[i]==y-x&&(a[i]-x>=0||a[j]+x<=a[n-1]))break;
if(a[j]-a[i]<y-x)j++;
else i++;
}
if(j<n)printf("1\n%d",a[i]-x>=0?a[i]-x:a[j]+x);
else printf("2\n%d %d",x,y);
}
}
}