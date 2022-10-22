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

char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int len=strlen(s+1),tot=0;
		rep(i,1,len) tot+=s[i]-'a'+1;
		if(len%2==0) printf("Alice %d\n",tot);
		else
		{
			int t1=tot-min(s[1]-'a'+1,s[len]-'a'+1),t2=tot-t1;
			if(t1>t2) printf("Alice %d\n",t1-t2);
			else printf("Bob %d\n",t2-t1);
		}
	}
	return 0;
}