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

int pre[30][maxn],n,m,ans[30];
char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=25;j++) pre[j][i]=pre[j][i-1];
			pre[s[i]-'a'][i]++; ans[s[i]-'a']++;
		}
		for(int i=1;i<=m;i++)
		{
			int x=read();
			for(int j=0;j<=25;j++) ans[j]+=pre[j][x];
		}
		for(int i=0;i<=25;i++) printf("%d ",ans[i]); puts("");
		for(int i=0;i<=25;i++) ans[i]=0;
	}
	return 0;
}