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
#define modc 1000000007
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int q,n,bin[maxn],bas[maxn][25],cnt[maxn];

inline bool check(int l,int x)
{
	for(int i=20;i>=0;i--)
	{
		if(x&bin[i])
		{
			if(!bas[l][i]) return 0;
			x^=bas[l][i];
		}
	}
	if(x==0) return 1;
	return 0;
}

int main()
{
	n=read(); q=read();
	bin[0]=1;
	for(int i=1;i<=max(n,20);i++) bin[i]=bin[i-1]*2%modc;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<20;j++) bas[i][j]=bas[i-1][j];
		cnt[i]=cnt[i-1];
		int x=read();
		for(int j=20;j>=0;j--)
		{
			if(x&bin[j])
			{
				if(!bas[i][j])
				{
					bas[i][j]=x;
					cnt[i]++;
					break;
				}
				else x^=bas[i][j];
			}
		}
	}
	while(q--)
	{
		int l=read(),x=read();
		if(!check(l,x)) puts("0");
		else printf("%d\n",bin[l-cnt[l]]);
	}
	return 0;
}