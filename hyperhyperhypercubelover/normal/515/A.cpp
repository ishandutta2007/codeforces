#include<cstdio>

int main()
{
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if(a<0)a=-a;
if(b<0)b=-b;
if(c<a+b)puts("No");
else if((c-(a+b))%2)puts("No");
else puts("Yes");
}