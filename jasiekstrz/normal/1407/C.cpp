#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int ans[10010];
int main()
{
	int n,i,j;
	cin>>n;
	for(i=1,j=2;j<=n;j++)
	{
		int x,y;
		cout<<"? "<<i<<" "<<j<<endl;
		cin>>x;
		cout<<"? "<<j<<" "<<i<<endl;
		cin>>y;
		if(x>y)
		{
			ans[i]=x;
			i=j;
		}
		else
		{
			ans[j]=y;
		}
	}
	ans[i]=n;
	cout<<"! ";
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}