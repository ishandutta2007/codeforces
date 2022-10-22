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

int n,c1,c2,cnt,s1,s0,ans;
char s[maxn],t[maxn];

int main()
{
	n=read(); scanf("%s",s+1); scanf("%s",t+1);
	rep(i,1,n) c1+=(s[i]=='1'),c2+=(t[i]=='1');
	if(c1!=c2) return puts("-1"),0;
	rep(i,1,n) if(s[i]==t[i]) continue;
	else s[++cnt]=s[i],t[cnt]=t[i];
	rep(i,1,cnt)
	{
		if(s[i]=='1')
		{
			s1++;
			if(s0) s0--;
			else ans++;
		}
		else
		{
			s0++;
			if(s1) s1--;
			else ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}