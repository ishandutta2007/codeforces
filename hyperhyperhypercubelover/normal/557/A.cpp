#include<cstdio>
#include<algorithm>

int main()
{
	int a,b,c,d,e,f,x,y,z,n;
	scanf("%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,&e,&f);
    x=std::min(b,n-c-e);
    n-=x;
    y=std::min(d,n-e);
    n-=y;
    z=n;
    printf("%d %d %d\n",x,y,z);
}