#include<bits/stdc++.h>
using namespace std;
int color[500500];
int cnt[500500];
int dp[500500];
int fst[500500],lst[500500];
bool islst[500500];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>color[i];
		cnt[color[i]]++;
		if(!fst[color[i]])
			fst[color[i]]=i;
		lst[color[i]]=i;
	}
	islst[n]=1;
	for(int i=n-1;i;i--)
		if(color[i]==color[i+1])
			islst[i]=1;
		else	break;
	for(int i=1;i<=n;i++)
		dp[i]=1e9;
	for(int i=1;i<=n;i++)
	{
//		cout<<i-1<<" "<<dp[i-1]<<endl;
		//skip all the amid ones
		if(fst[color[i]]==i)
			dp[lst[color[i]]]=min(dp[lst[color[i]]],dp[i-1]+lst[color[i]]-i+1-cnt[color[i]]);
		dp[n]=min(dp[n],dp[i-1]+n-i+1-cnt[color[i]]);
		//else
		if(islst[i])
			dp[n]=min(dp[n],dp[i-1]);
		dp[i]=min(dp[i],dp[i-1]+1);
		cnt[color[i]]--;
	}
	cout<<dp[n]<<endl;
	return 0;
}