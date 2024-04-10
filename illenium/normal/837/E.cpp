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

ll x,y,c,a,b,z,j;
vector <ll> v;

int main()
{
	cin>>x>>y;
	ll tt=__gcd(x,y);
	x/=tt; y/=tt;
	for(ll i=2;i*i<=x;i++)
	{
		while(x%i==0)
		{
			x/=i;
			v.push_back(i);
		}
	}
	if(x>1) v.push_back(x);
	ll ans=0;
	while(y)
	{
		ll hh=y;
		for(int i=0;i<v.size();i++) hh=min(hh,y%v[i]);
		y-=hh;
		ans+=hh;
		vector <ll> v1;
		for(int i=0;i<v.size();i++)
		{
			if(y%v[i]==0) y/=v[i];
			else v1.push_back(v[i]);
		}
		v.swap(v1);
	}
	cout<<ans<<endl;
	return 0;
}