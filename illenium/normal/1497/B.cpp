#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,a[maxn],cnt[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); rep(i,1,n) a[i]=read()%m,cnt[a[i]]++;
		int ans=0; if(cnt[0]) ans++;
		for(int i=1,j=m-1;i<j;i++,j--)
		{
			if(abs(cnt[i]-cnt[j])>1)
			{
				if(cnt[i]>cnt[j]) ans+=(cnt[i]-cnt[j]-1);
				else ans+=(cnt[j]-cnt[i]-1); ans++;
			}
			else if(cnt[i]!=0||cnt[j]!=0) ans++;
		}
		if(m%2==0&&cnt[m/2]!=0) ans++;
		printf("%d\n",ans);
			
		for(int i=1;i<=n;i++) cnt[a[i]]=0;
	}
	return 0;
}