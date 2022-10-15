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
int hav[22][800801];
int Mn[22];
int tot[22];
const int delta=400400;
int dp[(1<<20)];
int ans=0;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int mn=delta;
		int cnt=delta;
		string S;
		cin>>S;
		for(int j=0;j<sz(S);j++)
		{
			cnt+=(S[j]=='('?1:-1);
			mn=min(mn,cnt);
			if(cnt<=mn)
				hav[i][cnt]++;
		}
		Mn[i]=mn-delta;
		tot[i]=cnt-delta;
	}
	for(int i=0;i<(1<<20);i++)
		dp[i]=-inf;
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		int prvsum=0;
		for(int j=0;j<n;j++)
			if(i>>j&1)
				prvsum+=tot[j];
		for(int j=0;j<n;j++)
			if(!(i>>j&1))
			{
				if(Mn[j]+prvsum<0)
					ans=max(ans,dp[i]+hav[j][delta-prvsum]);
				else	dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+hav[j][delta-prvsum]);
			}
	}
	cout<<max(ans,dp[(1<<n)-1])<<endl;
	return 0;
}