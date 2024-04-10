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

int a[maxn];
map <int,int> mp;
vector <int> ans;

inline bool cmp(int a,int b){return a>b;}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int f=1;
	for(int i=31;i>=0;i--)
	{
		ll tmp=(1<<i),q=0;
		for(int j=1;j<=n;j++)
		{
			q=q+((a[j]>>i)&1);
			if(q==1&&((a[j]>>i)&1)==1) f=j;
		}
		if(q==1) break;
	}
	cout<<a[f]<<" ";
	for(int i=1;i<=n;i++) if(i!=f)  printf("%d ",a[i]);
	return 0;
}