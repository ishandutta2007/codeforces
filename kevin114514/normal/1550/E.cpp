#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(Vector) (int)(Vector.size())
using namespace std;
const ll mod=1e9+7;
int nxt[200200][20];
bool ok[200200][20];
int dp[(1<<17)];
int n,k;
string s;
void upd(char c,int len)
{
	int cnt=0;
	for(int i=0;i<len;i++)
		if(s[i]==c||s[i]=='?')
			cnt++;
	if(cnt==len)
		ok[0][c-'a']=true; 
	for(int i=0;i+len<n;i++)
	{
		if(s[i+len]==c||s[i+len]=='?')
			cnt++;
		if(s[i]==c||s[i]=='?')
			cnt--;
		if(cnt==len)
			ok[i+1][c-'a']=true;
	}
	nxt[n+1][c-'a']=n+1;
	for(int i=n;i>=0;i--)
		if(ok[i][c-'a'])
			nxt[i][c-'a']=i;
		else	nxt[i][c-'a']=nxt[i+1][c-'a'];
}
bool check(int mid)
{
	memset(nxt,0,sizeof(nxt));
	memset(ok,0,sizeof(ok));
	for(int i=1;i<(1<<k);i++)
		dp[i]=n+1;
	for(int i=0;i<k;i++)
		upd((char)(i+'a'),mid);
	for(int i=0;i<(1<<k);i++)
		for(int j=0;j<k;j++)
			if(!(i>>j&1))
				dp[i|(1<<j)]=min(dp[i|(1<<j)],nxt[dp[i]][j]+mid);
	return dp[(1<<k)-1]<=n;
}
int main()
{
	cin>>n>>k>>s;
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
			l=mid;
		else	r=mid-1; 
	}
	cout<<l<<endl;
	return 0;
}