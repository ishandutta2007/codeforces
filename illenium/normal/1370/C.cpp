#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline bool jud(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}

int main()
{
	int T=read();
	while(T--)
	{
		int x=read(),cnt=0,F=0,ans=0;
		if(x==1) ans=0; else if(x==2) ans=1; else if(x%2==1) ans=1;
		else
		{
			while(x%2==0) x/=2,cnt++;
			if(x==1) ans=0;
			else if(cnt==1&&jud(x)) ans=0;
			else ans=1;
		}
		puts(ans==0?"FastestFinger":"Ashishgup");
	}
	return 0;
}