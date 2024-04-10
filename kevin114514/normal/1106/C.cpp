#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main()
{
	int n;
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int point=0;
	for(int i=1;i*2<=n;i++)
		sum+=(a[point]+a[n-1-point])*(a[point]+a[n-1-point]),point++;
	printf("%I64d\n",sum);
	return 0;
}