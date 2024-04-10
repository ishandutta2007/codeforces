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
ll dp[4000001];
ll delta[8000001];
int main()
{
	int n;
	ll m;
	cin>>n>>m;
	dp[1]=1;
	ll sum=1;
	ll del=0;
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			del+=delta[i];
			del%=m;
			dp[i]=(sum+del)%m;
			sum=(sum+dp[i])%m;
		}
		for(int j=2;j*i<=n;j++)
		{
			delta[i*j]+=dp[i];
			delta[i*j]=(delta[i*j]+m)%m;
			delta[i*j+j]-=dp[i];
			delta[i*j+j]=(delta[i*j+j]+m)%m;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}