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

int n,a,b,ans;
char ch[maxn];

int main()
{
	//freopen("CF962B.in","r",stdin);
	n=read(); a=read(); b=read();
	scanf("%s",ch+1); ch[n+1]='*'; ch[n+2]='*';
	int j;
	for(int i=1;i<=n;i=j+1)
	{
		while(ch[i]=='*'&&i<=n) i++;
		if(i>n) break;
		for(j=i+1;j<=n;j++) if(ch[j]=='*') break;
		int len=j-i;
		if(len%2==0)
		{
			int p=len/2;
			if(a>=p) a-=p,ans+=p;
			else
			{
				ans+=a;
				a=0;
			}
			if(b>=p) b-=p,ans+=p;
			else
			{
				ans+=b;
				b=0;
			}
		}
		else
		{
			int p=len/2;
			if(a>b)
			{
				if(a>=(p+1)) a-=(p+1),ans+=(p+1);
				else
				{
					ans+=a;
					a=0;
				}
				if(b>=p) b-=p,ans+=p;
				else
				{
					ans+=b;
					b=0;
				}
			}
			else
			{
				if(a>=(p)) a-=(p),ans+=(p);
				else
				{
					ans+=a;
					a=0;
				}
				if(b>=(p+1)) b-=(p+1),ans+=(p+1);
				else
				{
					ans+=b;
					b=0;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}