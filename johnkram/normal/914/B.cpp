#include<bits/stdc++.h>
using namespace std;
int n,i,a[100005],b[100005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)b[a[i]]++;
	for(i=100000;i;i--)if(b[i]&1)break;
	if(i)puts("Conan");
	else puts("Agasa");
	return 0;
}