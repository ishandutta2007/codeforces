#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
ll dp[11][2][2];
ll a[11];
ll g[40];
ll go(int x,bool bl1,bool bl2)
{
	if(x==10){if(bl1==false &&bl2==false)return 1;return 0;}
	if(dp[x][bl1][bl2]!=-1)return dp[x][bl1][bl2];
	int r=a[x];
	if(bl1)r--;
	//if(r<0)return 0;
	 dp[x][bl1][bl2]=g[r]*go(x+1,bl2,0) +g[r+10]*go(x+1,bl2,1);

	return dp[x][bl1][bl2];
	
	
}
int main () {
	for(int i=0;i<=9;i++)g[i]=i+1;
	for(int i=10;i<19;i++)g[i]=10-i+9;
	int t;
	cin>>t;
	while(t--)
	{int n;
		cin>>n;
		memset(dp,-1,sizeof dp);
		memset(a,0,sizeof a);
		int i=0;
		while(n>0)
		{
			a[i]=n%10;
			i++;
			n/=10;
		}
		cout<<go(0,0,0)-2<<endl;
		
	}
	return 0;
	
	
}