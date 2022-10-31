// Hydro submission #6247f1c60bc575b66aa57962@1648882119240
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x[100],d[100],n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>x[i]>>d[i];
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(x[i]+d[i]==x[j]&&x[j]+d[j]==x[i])
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}