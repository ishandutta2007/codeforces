#include<bits/stdc++.h>
using namespace std;
int n,a[20],i,j;
bool f[20][1000];
int main()
{
	cin>>n;
	f[0][0]=1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(j=0;j<360;j++)f[i][j]=f[i-1][(j+a[i])%360]||f[i-1][(j+360-a[i])%360];
	}
	if(f[n][0])puts("YES");
	else puts("NO");
	return 0;
}