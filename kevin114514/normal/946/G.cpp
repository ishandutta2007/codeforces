#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int a[400200];
int bit1[400200];
void update1(int p,int v)
{
	while(p<400200)
	{
		bit1[p]=min(bit1[p],v);
		p+=(p&(-p));
	}
}
int query1(int p)
{
	int ans=inf;
	while(p)
	{
		ans=min(ans,bit1[p]);
		p-=(p&(-p));
	}
	return ans;
}
int bit2[400200];
void update2(int p,int v)
{
	while(p<400200)
	{
		bit2[p]=min(bit2[p],v);
		p+=(p&(-p));
	}
}
int query2(int p)
{
	int ans=inf;
	while(p)
	{
		ans=min(ans,bit2[p]);
		p-=(p&(-p));
	}
	return ans;
}
int bit3[400200];
void update3(int p,int v)
{
	while(p<400200)
	{
		bit3[p]=min(bit3[p],v);
		p+=(p&(-p));
	}
}
int query3(int p)
{
	int ans=inf;
	while(p)
	{
		ans=min(ans,bit3[p]);
		p-=(p&(-p));
	}
	return ans;
}
int dp[400200][2];
int x[400200];
signed main()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]-=i;
		x[i]=a[i];
	}
	a[0]=-n;
	vector<int> vec;
	for(int i=0;i<=n;i++)
	{
		vec.pb(a[i]+1);
		vec.pb(a[i]);
	}
	srt(vec);
	uni(vec);
	for(int i=0;i<=n;i++)
		a[i]=lb(vec,a[i])+1;
	memset(dp,inf,sizeof(dp));
	memset(bit1,inf,sizeof(bit1));
	memset(bit2,inf,sizeof(bit2));
	memset(bit3,inf,sizeof(bit3));
	dp[0][0]=0;
	a[n+1]=n+n+5;
	x[n+1]=1145151919810ll;
	for(int i=0;i<=n+1;i++)
	{
		if(i)
		{
			dp[i][0]=query1(a[i])+i;
			dp[i][1]=min(query3(lb(vec,x[i]+1)+1),query2(a[i]))+i;
		}
		update2(a[i],dp[i][1]-i-1);
		update1(a[i],dp[i][0]-i-1);
		if(i)
			update3(a[i-1],dp[i-1][0]-i);
	}
	cout<<max(0ll,min(dp[n+1][1],dp[n+1][0])-1)<<endl;
	return 0;
}