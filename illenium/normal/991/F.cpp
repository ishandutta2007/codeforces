#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

map<ll,string>Map;
map<ll,string>::iterator it;

inline string Get(ll x)
{
	string ans="";
	int s[13],cnt=0;
	while(x) {
		s[++cnt]=x%10;
		x/=10;
	}
	for(int i=cnt; i>=1; i--)ans+=char(s[i]+'0');
	return ans;
}

int main()
{
	ll n;
	scanf("%lld",&n);
	ll len=sqrt(n);
	for(ll i=2;i<=len;i++)
	{
		for(ll j=i*i,k=2;j<=n;j*=i,k++)
		{
			string gg=Get(i)+"^"+Get(k);
			if(gg.size()>=Get(j).size())continue;
			if(Map[j].size()==0) Map[j]=gg;
			else if(Map[j].size()>gg.size())Map[j]=gg;
		}
	}
	string ans=Get(n);
	for(it=Map.begin();it!=Map.end();it++)
	{
		ll k=(*it).first;
		string gg=(*it).second;
		if(n/k>=2)
		{
			gg+="*";
			gg+=(Map.count(n/k))?Map[n/k]:Get(n/k);
		}
		if(n%k)
		{
			gg+="+";
			gg+=(Map.count(n%k))?Map[n%k]:Get(n%k);
		}
		if(ans.size()>gg.size())ans=gg;
	}
	cout<<ans<<endl;
	return 0;
}