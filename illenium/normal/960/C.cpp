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

ll n,d,cnt,base=1;
vector <ll> vec;

int main()
{
	n=read(); d=read();
	for(ll i=30;i>=0;i--)
	{
		if(n<(1<<i)-1) continue;
		else
		{
			for(ll j=1;j<=i;j++) vec.push_back(base);
			base+=(d+1);
			n-=((1<<i)-1);
		}
	}
	while(n)
	{
		vec.push_back(base);
		base+=(d+1);
		n--;
	}
	cout<<vec.size()<<endl;
	for(ll i=0;i<vec.size();i++) cout<<vec[i]<<" ";
	return 0;
}