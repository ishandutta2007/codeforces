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

char s[maxn];
int s1,s2,t1,t2,tmp1,tmp2;

int main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n/2;i++)
	{
		if(s[i]=='?') t1++;
		else s1+=(s[i]-'0');
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(s[i]=='?') t2++;
		else s2+=(s[i]-'0');
	}
	if(s1<s2) swap(t1,t2),swap(s1,s2);
	if(s1==s2)
	{
		if(t1==t2) puts("Bicarp");
		else puts("Monocarp");
	}
	else
	{
		if(t1>t2) puts("Monocarp");
		else
		{
			tmp1=s1-s2;
			tmp2=(t2-t1)>>1;
			if(9*tmp2==tmp1) puts("Bicarp");
			else puts("Monocarp");
		}
	}
	return 0;
}