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

int a[maxn],ans;

int main()
{
	int n=read(),cnt=0;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	cnt=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=2*a[i];j<=2e6;j+=a[i])
		{
			int tmp=lower_bound(a+1,a+cnt+1,j)-a;
			ans=max(ans,a[tmp-1]%a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}