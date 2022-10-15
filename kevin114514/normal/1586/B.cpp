#include<bits/stdc++.h>
using namespace std;
bool vis[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int m;
		cin>>m;
		while(m--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			vis[b]=1;
		}
		int x=min_element(vis+1,vis+n+1)-vis;
		for(int i=1;i<=n;i++) if(i!=x)
			cout<<x<<" "<<i<<endl;
	}
}