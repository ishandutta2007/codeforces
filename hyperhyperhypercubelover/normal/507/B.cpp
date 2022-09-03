#include<cstdio>

int main()
{
    int i,a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    for(i=0;4LL*i*i*a*a<1LL*(b-d)*(b-d)+1LL*(e-c)*(e-c);i++);
    printf("%d",i);
}