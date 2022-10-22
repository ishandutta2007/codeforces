#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
map<ll,int> s,a;
int n;
ll m,x,l,r,mid,ans;
pair<ll,int> t;
ll a2(ll m)
{
	l=1;
	r=2000000000;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(mid*mid<=m)l=mid;
		else r=mid;
	}
	return l;
}
ll a3(ll m)
{
	l=1;
	r=2000000;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(mid*mid*mid<=m)l=mid;
		else r=mid;
	}
	return l;
}
ll a4(ll m)
{
	l=1;
	r=40000;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(mid*mid*mid*mid<=m)l=mid;
		else r=mid;
	}
	return l;
}
ll gcd(ll x,ll y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	cin>>n;
	ans=1;
	while(n--)
	{
		cin>>m;
		x=a4(m);
		if(x*x*x*x==m)
		{
			s[x]+=4;
			continue;
		}
		x=a3(m);
		if(x*x*x==m)
		{
			s[x]+=3;
			continue;
		}
		x=a2(m);
		if(x*x==m)
		{
			s[x]+=2;
			continue;
		}
		for(auto it:s)if(m%it.first==0)
		{
			x=it.first;
			s[x]++;
			s[m/x]++;
			m=0;
			break;
		}
		if(!m)continue;
		for(auto it:a)if(it.first==m)
		{
			a[m]++;
			m=0;
			break;
		}
		else
		{
			x=gcd(it.first,m);
			if(x==1)continue;
			s[x]++;
			s[m/x]++;
			s[x]+=it.second;
			s[it.first/x]+=it.second;
			a.erase(it.first);
			m=0;
			break;
		}
		if(m)a.insert(make_pair(m,1));
	}
	for(auto it:a)for(auto it1:s)if(it.first%it1.first==0)
	{
		s[it1.first]+=it.second;
		s[it.first/it1.first]+=it.second;
		a[it.first]=0;
		break;
	}
	for(auto it:s)ans=ans*(it.second+1)%P;
	for(auto it:a)ans=ans*(it.second+1)%P*(it.second+1)%P;
	cout<<ans<<endl;
	return 0;
}