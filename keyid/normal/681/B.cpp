#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for (int s=0;s<=n;s+=1234567)
		for (int s2=s;s2<=n;s2+=123456)
			if ((n-s2)%1234==0)
			{
				printf("YES");
				return 0;
			}
	printf("NO");
	return 0;
}