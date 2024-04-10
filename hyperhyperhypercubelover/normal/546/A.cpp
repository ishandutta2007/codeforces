#include<cstdio>
#include<algorithm>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&c,&b);
	printf("%d",std::max(0,a*b*(b+1)/2-c));
}