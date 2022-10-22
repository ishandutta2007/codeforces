#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

char s[maxn],ans[maxn];
int len;

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); len=strlen(s+1); int f=0;
		for(int i=2;i<=len;i++)
			if(s[i]=='?') continue;
			else if(s[i]==s[i-1]) {f=1; break;}
		if(f==1) {puts("-1"); continue;}
		for(int i=1;i<=len;i++)
		{
			if(s[i]!='?') ans[i]=s[i];
			else
			{
				if(ans[i-1]=='a')
				{
					if(s[i+1]=='c') ans[i]='b';
					else ans[i]='c';
				}
				else if(ans[i-1]=='b')
				{
					if(s[i+1]=='a') ans[i]='c';
					else ans[i]='a';
				}
				else
				{
					if(s[i+1]=='a') ans[i]='b';
					else ans[i]='a';
				}
			}
		}
		for(int i=1;i<=len;i++) printf("%c",ans[i]); puts("");
	}
	return 0;
}