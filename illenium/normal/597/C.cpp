#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
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

ll a[maxn],c[20][maxn],n,k;

inline void add(int a,int b,ll val)
{
	for(int i=a;i<=n;i+=i&-i) c[b][i]+=val;
}

inline ll q(int a,int b)
{
	ll res=0;
	for(int i=a;i;i-=i&-i) res+=c[b][i];
	return res;
}

int main()
{
	n=read(),k=read(); k++;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		add(a[i],1,1);
		for(int j=1;j<k;j++)
		{
			ll tmp=q(a[i]-1,j);
			add(a[i],j+1,tmp);
		}
	}
	cout<<q(n,k)<<endl;
	return 0;
}