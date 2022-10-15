#include<bits/stdc++.h>
using namespace std;
int DP[200200];
int sz[200200];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		for(int i=1;i<=N;i++)
			cin>>sz[i];
		for(int i=1;i<=N;i++)
			DP[i]=1;
		for(int i=1;i<=N;i++)
			for(int j=i+i;j<=N;j+=i)
				if(sz[j]>sz[i])
					DP[j]=max(DP[j],DP[i]+1);
		int ans=0;
		for(int i=1;i<=N;i++)
			ans=max(ans,DP[i]);
		cout<<ans<<endl;
	}
	return 0;
}