#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	if(sum-x[a]>=x[a] && sum%2==0) printf("YES");
	else printf("NO");
}