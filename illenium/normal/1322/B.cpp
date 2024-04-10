#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 400005
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

int a[maxn],b[maxn],p[50],ans,c[maxn];

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read(); p[0]=1;
	for(int i=1;i<=30;i++) p[i]=p[i-1]*2;
	for(int i=0;i<=28;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]%2==1) c[j]=c[j]+(1<<i);
			a[j]>>=1;
		}
		for(int j=1;j<=n;j++) b[j]=c[j];
		sort(b+1,b+n+1);
		ll cnt=0;
		for(int j=1;j<=n;j++)
		{
			int l=max(0,p[i]-b[j]),r=p[i+1]-1-b[j]; //cout<<b[j]<<" ";
			cnt+=(upper_bound(b+1,b+n+1,r)-b)-(lower_bound(b+1,b+n+1,l)-b);
			if(b[j]>=l&&b[j]<=r) cnt--;
			l=p[i+1]+p[i]-b[j],r=p[i+2]-1-b[j];
			cnt+=(upper_bound(b+1,b+n+1,r)-b)-(lower_bound(b+1,b+n+1,l)-b);
			if(b[j]>=l&&b[j]<=r) cnt--;
			//cout<<cnt<<endl;
		}
		cnt>>=1; //cout<<endl<<cnt<<endl;
		if(cnt%2==1) ans+=(1<<i);
	}
	cout<<ans<<endl;
	return 0;
}