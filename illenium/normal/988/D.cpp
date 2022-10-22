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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],cnt,tot;
map <ll,int> mp;
map <ll,int> mp2;

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),mp2[a[i]]=1;
	ll tmp=1;
	while(tmp>0) mp[tmp]=1,mp[-tmp]=1,tmp*=2;
	sort(a+1,a+n+1);
	tot=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=tot;i++)
	{
		for(ll j=1;j<2e9;j*=2)
		{
			if(mp2[a[i]+j]&&mp2[a[i]+j+j])
			{
				cout<<3<<endl;
				cout<<a[i]<<" "<<a[i]+j<<" "<<a[i]+j+j<<endl;
				return 0;
			}
		}
	}
	for(int i=2;i<=tot;i++) if(mp[a[i]-a[i-1]])
	{
		cout<<2<<endl;
		cout<<a[i]<<" "<<a[i-1];
		return 0;
	}
	cout<<1<<endl<<a[1];
	return 0;
}