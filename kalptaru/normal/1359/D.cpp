#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
struct va
{
	int sum=0,left=0,right=0,ms=0;
};
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
vector<int> pos[61];
int in[61];
int ans=0;
int a[100001];
va dnc(int l,int r,int n)
{
//	cout<<l<<' '<<r<<'s'<<'\n';
	va res,t,tem;
	if(l>r || n==-1)
	return res;
	if(l==r)
	{
		res.sum=res.ms=a[l];
		if(a[l]>0)
		{
			res.left=res.right=a[l];
		}
		in[a[l]+30]++;
//		cout<<l<<' '<<r<<' '<<n<<' '<<res.ms<<'\n';
		return res;
	}
	bool f=1;
	n++;
	while(f)
	{
		n--;
		int o=in[n];
		FOR(i,o,pos[n].size())
		{
			if(pos[n][i]>r)
			break;
			f=0;
			in[n]++;
			if(i==o)
			{
				res=dnc(l,pos[n][i]-1,n-1);
			}
			else
			{
				t=dnc(pos[n][i-1]+1,pos[n][i]-1,n-1);
				tem.sum=res.sum+t.sum+n-30;
				tem.left=max(res.left,res.sum+t.left+n-30);
				tem.right=max(t.right,t.sum+res.right+n-30);
				tem.ms=max(res.right+t.left+n-30,max(res.ms,t.ms));
				res=tem;
			}
		}
	}
	t=dnc(pos[n][in[n]-1]+1,r,n-1);
	tem.sum=res.sum+t.sum+n-30;
	tem.left=max(res.left,res.sum+t.left+n-30);
	tem.right=max(t.right,t.sum+res.right+n-30);
	tem.ms=max(res.right+t.left+n-30,max(res.ms,t.ms));
	res=tem;
	if(n>30)
	ans=max(ans,(res.ms-(n-30)));
//	cout<<l<<' '<<r<<' '<<n<<' '<<res.ms<<'\n';
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		FOR(i,0,n)
		{
			cin>>a[i];
			pos[a[i]+30].pb(i);
		}	
		va f=dnc(0,n-1,60);
		cout<<ans;
	}
	return 0;
}