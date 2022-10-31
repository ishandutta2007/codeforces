// Hydro submission #62cf88d83a0e0c031110a141@1657768153498
#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],m;
bool f;
int main()
{
	int n,k,b,i;
	cin>>n>>k;
	if(k>1)
	{
		printf("Yes\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	cin>>a[i];cin>>b;
	for(i=2;i<=n;i++)
	{
		if(!a[i-1]) a[i-1]=b;
		if(!a[i]) a[i]=b;
		if(a[i-1]>=a[i])
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}