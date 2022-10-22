#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
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

ll k,F,cnt;
string s="codeforces";

inline ll jud(int x)
{
	int t=x/10,t2=x%10; ll tot=1;
	for(int i=1;i<=t2;i++) tot*=(t+1);
	for(int i=1;i<=10-t2;i++) tot*=t;
	if(tot>=k)
	{
		F=1;
		while(cnt<t2)
		{
			for(int i=1;i<=t+1;i++) printf("%c",s[cnt]);
			cnt++;
		}
		while(cnt<=9)
		{
			for(int i=1;i<=t;i++) printf("%c",s[cnt]);
			cnt++;
		}
	}
	
}

int main()
{
	k=read();
	for(int i=10;i;i++) if(!F) jud(i); else break;
	return 0;
}