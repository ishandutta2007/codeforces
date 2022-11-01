#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,i,j,vis[100005];

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		rep(i,n) vis[i]=0;
		
		rep(i,m)
		{
			int a,b,c;
			cin>>a>>b>>c;
			vis[b]=1;
		}
		
		i=1;while(vis[i])i++;
		rep(j,n) if(i!=j)
		{
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}