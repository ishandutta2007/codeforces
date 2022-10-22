#pragma GCC optimize(2)
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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn];

int main()
{
	ll T=read();
	while(T--)
	{
		ll n=read(),s=read(),tmp=0,tmp2=0,tot=0,f=0,fl=0;
		for(int i=1;i<=n;i++) a[i]=read(),tot+=a[i];
		if(tot<=s) puts("0");
		else
		{
			tot=0;
			for(int i=1;i<=n;i++)
			{
				tot+=a[i]; tmp2=max(tmp2,a[i]);
				if(tot-tmp2>s) break;
				if(a[i]>tmp) tmp=a[i],fl=i;
			}
			cout<<fl<<endl;
		}
	}
	return 0;
}