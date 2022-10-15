#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
int dp[100005][513];
int x[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",x+i);
	for(int i=0;i<100005;i++)
		for(int j=0;j<513;j++)
			dp[i][j]=513;
	dp[0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<513;j++)
		{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(x[i]>dp[i][j])
				dp[i+1][j^x[i]]=min(dp[i+1][j^x[i]],x[i]);
		}
	vector<int> v;
	for(int i=0;i<513;i++)
		if(dp[n][i]<513)
			v.pb(i);
	cout<<sz(v)<<endl;
	for(int i=0;i<sz(v);i++)
		cout<<v[i]<<" ";
	return 0;
}