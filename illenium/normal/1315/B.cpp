#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		ll a=read(),b=read(),p=read(),res=0; scanf("%s",s+1);
		int len=strlen(s+1),ans=len;
		for(int i=len-2;i>=1;i--)
		{
			//cout<<i<<" "<<res<<endl;
			if(s[i]!=s[i+1])
			{
				if(s[i+1]=='A') res+=a;
				else res+=b;
				if(res<=p) ans=i+1;
				else break;
			}
			//cout<<i<<" "<<res<<endl;
		}
		if(s[1]=='A') res+=a; else res+=b;
		if(res<=p) puts("1");
		else cout<<ans<<endl;
	}
	return 0;
}