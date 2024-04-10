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
ll dp[2020][2020][2][2];
const ll mod=1e9+7;
int main()
{
	int n,m,d;
	string a,b;
	cin>>m>>d>>a>>b;
	n=sz(a);
	dp[0][0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) for(int f1=0;f1<2;f1++)
							 for(int f2=0;f2<2;f2++)
			for(int k=0;k<10;k++) if((k!=d)^(i%2))
			{
				if(!f1&&k<a[i]-'0')
					continue;
				if(!f2&&k>b[i]-'0')
					continue;
				dp[i+1][(j*10+k)%m][f1|(k!=a[i]-'0')][f2|(k!=b[i]-'0')]=(dp[i+1][(j*10+k)%m][f1|(k!=a[i]-'0')][f2|(k!=b[i]-'0')]+dp[i][j][f1][f2])%mod;
			}
	cout<<(dp[n][0][0][0]+dp[n][0][0][1]+dp[n][0][1][0]+dp[n][0][1][1])%mod<<endl;
	return 0;
}