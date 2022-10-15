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
ll dp[200200];
int main()
{
	int n;
	ll m;
	cin>>n>>m;
	dp[1]=1;
	int sum=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=sum;
		for(int j=1;j<=sqrt(i);j++)
			dp[i]=(dp[i]+dp[j]*(i/j-i/(j+1)))%m;
		for(int j=2;j<=i/((int)(sqrt(i))+1);j++)
			dp[i]=(dp[i]+dp[i/j])%m;
		sum=(sum+dp[i])%m;
	}
	cout<<dp[n]<<endl;
	return 0;
}