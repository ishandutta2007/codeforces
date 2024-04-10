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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int dp[505][505];
int lst[505][505];
int nxt[505][505];
int a[505],b[505];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	memset(dp,inf,sizeof(dp));
	a[0]=-1;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			nxt[i][j]=m+1;
			for(int k=j;k<=m;k++)
				if(b[k]==a[i])
				{
					nxt[i][j]=k;
					break;
				}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++) if(dp[i][j]<m)
			for(int k=i+1;k<=n;k++) if(a[k]>a[i])
			{
				int nxtm=nxt[k][dp[i][j]+1];
				if(nxtm<dp[k][j+1])
				{
					dp[k][j+1]=nxtm;
					lst[k][j+1]=i;
				}
			}
	int len=0,lstp=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(dp[j][i]<=m)
				len=i,
				lstp=j;
	cout<<len<<endl;
	vector<int> v;
	for(int i=len;i;i--)
	{
		v.pb(a[lstp]);
		lstp=lst[lstp][i];
	}
	rev(v);
	for(auto x:v)
		cout<<x<<" ";
	return 0;
}