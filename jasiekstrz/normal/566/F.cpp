#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
int tab[1000010];
int dp[1000010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m=0,w=0,a,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		m=max(m,a);
		tab[a]++;
	}
	for(i=1;i<=m;i++)
	{
		dp[i]+=tab[i];
		w=max(w,dp[i]);
		for(j=2*i;j<=m;j+=i)
			dp[j]=max(dp[j],dp[i]);
	}
	cout<<w<<"\n";
	return 0;
}