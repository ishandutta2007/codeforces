#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn];

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	if(n==1)
	{
		puts("1 1"); cout<<-a[1]<<endl;
		puts("1 1\n0");
		puts("1 1\n0");
		return 0;
	}
	puts("1 1");
	cout<<n-a[1]<<endl; a[1]=n;
	cout<<2<<" "<<n<<endl;
	rep(i,2,n)
	{
		ll tmp=a[i]%n;
		a[i]+=tmp*(n-1);
		printf("%lld ",tmp*(n-1));
	}
	puts("");
	cout<<1<<" "<<n<<endl;
	rep(i,1,n) printf("%lld ",-a[i]);
	return 0;
}