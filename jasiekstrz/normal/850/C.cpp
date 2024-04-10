#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=20;
int dp[(1<<(N+1))+10];
map<int,int> id;
int msk[1000010];
inline int lsb(int x)
{
	int i=0;
	for(;x%2==1;x/=2,i++);
	return i;
}
int f(int x)
{
	if(x<(1<<(N+1)))
		return dp[x];
	int a=0;
	for(int j=1;(1<<j)<=x;j++)
	{
		a|=(1<<f((x&((1<<j)-1))|(x>>j)));
	}
	return lsb(a);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ans=0,i;
	for(i=2;i<(1<<(N+1));i++)
	{
		for(int j=1;(1<<j)<=i;j++)
		{
			dp[i]|=(1<<dp[(i&((1<<j)-1))|(i>>j)]);
		}
		dp[i]=lsb(dp[i]);
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=2;j*j<=x;j++)
		{
			if(x%j==0)
			{
				int tmp=0;
				while(x%j==0)
				{
					tmp++;
					x/=j;
				}
				if(id[j]==0)
					id[j]=id.size();
				msk[id[j]]|=(1<<tmp);
			}
		}
		if(x>1)
		{
			if(id[x]==0)
				id[x]=id.size();
			//cerr<<x<<" "<<id[x]<<"\n";
			msk[id[x]]|=2;
		}
	}
	for(i=1;i<=id.size();i++)
	{
		ans^=f(msk[i]);
	}
	cout<<(ans==0 ? "Arpa":"Mojtaba")<<"\n";
	return 0;
}