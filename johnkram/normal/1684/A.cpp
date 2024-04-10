#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[10];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(m=0;n;n/=10)a[m++]=n%10;
		printf("%d\n",m==2?a[0]:*min_element(a,a+m));
	}
	return 0;
}