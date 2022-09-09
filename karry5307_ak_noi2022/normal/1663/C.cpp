#include<cstdio>

using namespace std;

int a[2000];

int main()
{
	int n=0;scanf("%d",&n);int sum=0;for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];printf("%d",sum);
	
}