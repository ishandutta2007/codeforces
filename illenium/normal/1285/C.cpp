#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e18
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll ans,f;

int main()
{
	ll n; cin>>n; ans=inf;
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0&&__gcd(i,n/i)==1)
		{
			ll tmp=max(n/i,i);
			if(ans>tmp) ans=tmp,f=i;
		}
	}
	cout<<f<<" "<<n/f<<endl;
	return 0;
}