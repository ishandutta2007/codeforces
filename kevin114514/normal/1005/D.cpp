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
int dp[3];
int main()
{
	string S;
	cin>>S;
	int n=S.length();
	int lst=0;
	int sum=0;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		sum+=S[i]-'0';
		sum%=3;
		lst=max(lst,dp[sum]+1);
		dp[sum]=max(dp[sum],lst);
//		cout<<lst<<endl;
	}
	cout<<lst<<endl;
	return 0;
}