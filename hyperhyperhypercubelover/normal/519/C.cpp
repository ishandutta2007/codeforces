#include<cstdio>
#include<algorithm>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
    printf("%d",std::min(std::min(a,b),(a+b)/3));
}