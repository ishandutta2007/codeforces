#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(Vector) (int)(Vector.size())
using namespace std;
const ll mod=1e9+7;
int dp[1010][1010];
pair<int,int> nxt[1010][1010];
int a[1010];
int n;
int dfs(int x,int lft)
{
	int &ans=dp[x][lft];
	if(ans!=-1)
		return ans;
	ans=1e9;
	if(x==n)
		return ans=a[lft];
	if(x==n-1)
		return ans=max(a[lft],a[x]);
	int b[3]={a[lft],a[x],a[x+1]};
	int c[3]={lft,x,x+1};
	for(int i=0;i<3;i++)
	{
		int xx=0;
		for(int j=0;j<3;j++)
			if(i!=j)
				xx=max(xx,b[j]);
		if(dfs(x+2,c[i])+xx<ans)
		{
			ans=dfs(x+2,c[i])+xx;
//			cout<<x+2<<","<<c[i]<<"->"<<x<<","<<lft<<endl; 
			nxt[x][lft]=mp(x+2,c[i]);
		}
	}
	return ans;
}
void getch(int x,int lft)
{
	if(x==n)
	{
		cout<<lft+1<<endl;
		return ;
	}
	if(x==n-1)
		cout<<lft+1<<" "<<n<<endl;
	else
	{
		int a=nxt[x][lft].first,b=nxt[x][lft].second;
		if(b==lft)
		{
			cout<<x+1<<" "<<x+2<<endl;
			getch(x+2,b);
		}
		else if(b==x)
		{
			cout<<lft+1<<" "<<x+2<<endl;
			getch(x+2,b); 
		}
		else
		{
			cout<<lft+1<<" "<<x+1<<endl;
			getch(x+2,b); 
		}
	}
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<dfs(1,0)<<endl;
	getch(1,0);
	return 0;
}