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
int dp[2][4040];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		dp[0][0]=0;
		for(int i=1;i<=3000;i++)
			dp[0][i]=3000;
		bool f=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=3000;j++)
				dp[f^1][j]=3000;
			int x;
			cin>>x;
			for(int j=0;j<=3000;j++)
			{
				if(j+x<=3000)
					dp[f^1][j+x]=min(dp[f^1][j+x],max(dp[f][j],j+x));
				if(j<=x)
					dp[f^1][0]=min(dp[f^1][0],dp[f][j]+x-j);
				else	dp[f^1][j-x]=min(dp[f^1][j-x],dp[f][j]);
			}
			f^=1;
		}
		cout<<*min_element(dp[f],dp[f]+3001)<<endl;
	}
	return 0;
}