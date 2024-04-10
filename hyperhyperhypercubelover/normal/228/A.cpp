#include<cstdio>
#include<algorithm>

int a[4];

int main()
{
	int i,r=0;
    for(i=0;i<4;i++)scanf("%d",&a[i]);
    std::sort(a,a+4);
    for(i=1;i<4;i++)r+=a[i]==a[i-1];
    printf("%d",r);
}