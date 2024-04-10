#include<cstdio>
#include<algorithm>

int main()
{
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
if((a<=c&&b<=d)||a+b<=std::max(c,d))puts("Polycarp");
else puts("Vasiliy");
}