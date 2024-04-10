#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
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
		int n=read(),x=read();
		scanf("%s",s+1);
		int tmp=0,tot=0,ans=0,f=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0') tmp++;
			else tmp--;
			if(tmp==x) f=1;
		}
		tot=tmp; tmp=0;
		if(tot==0)
		{
			if(f==1) puts("-1");
			else puts("0");
			continue;
		}
		else if(tot>0)
		{
			for(int i=1;i<=n;i++)
			{
				if(x>=tmp&&(x-tmp)%tot==0) ans++;
				if(s[i]=='0') tmp++;
				else tmp--;
			}
		}
		else
		{
			tot=-tot;
			for(int i=1;i<=n;i++)
			{
				if(tmp>=x&&(tmp-x)%tot==0) ans++;
				if(s[i]=='0') tmp++;
				else tmp--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}