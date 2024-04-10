#include<bits/stdc++.h>
using namespace std;
bool t[1000005],b;
int a[1000005],n,i,j;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=n;i;i--)
	{
		for(j=a[i];j;j^=j&-j)b^=t[j];
		for(j=a[i];j<=n;j+=j&-j)t[j]=!t[j];
	}
	if((n&1)==b)puts("Petr");
	else puts("Um_nik");
	return 0;
}