#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,i,j;
bool b[100005];
int main()
{
	cin>>n;
	for(i=2;i*i<=n+1;i++)if(!b[i])for(j=i*i;j<=n+1;j+=i)b[j]=1;
	if(n<3)
	{
		puts("1");
		while(n--)cout<<"1 ";
	}
	else
	{
		puts("2");
		for(i=2;i<=n+1;i++)printf("%d ",b[i]+1);
	}
	return 0;
}