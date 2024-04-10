#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,a[maxn],c[maxn],ans;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),c[a[i]]=1;
	per(i,1000000,1)
	{
		if(c[i]) continue;
		int tmp=0;
		for(int j=2*i,k=2;j<=1000000;j+=i,k++)
		{
			if(!c[j]) continue;
			if(!tmp) tmp=k;
			else tmp=__gcd(tmp,k);
			if(tmp==1) {c[i]=1; ans++; break;}
		}
	}
	cout<<ans<<endl;
	return 0;
}