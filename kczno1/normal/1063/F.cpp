#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=5e5+5;
int n;
char s[N];
int sa[N],qa[2][N],*rk=qa[0],*tmp=qa[1],cnt[N],h[N];
int dp[N];
const int T=N*3;
int d,mn_h[T],mx_dp[T];

void init_sa()
{
	rep(i,1,n)++cnt[s[i]-'a'+1];
	rep(i,1,26)cnt[i]+=cnt[i-1];
	per(i,n,1)sa[cnt[s[i]-'a'+1]--]=i;
	rk[sa[1]]=1;
	rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(int l=1;rk[sa[n]]<n;l<<=1)
	{
		int top=0;
		rep(i,n-l+1,n)tmp[++top]=i;
		rep(i,1,n)
		if(sa[i]>l)tmp[++top]=sa[i]-l;
		
		int m=rk[sa[n]];
		rep(i,1,m)cnt[i]=0;
		rep(i,1,n)++cnt[rk[i]];
		rep(i,1,m)cnt[i]+=cnt[i-1];
		per(i,n,1)
		{
			int x=tmp[i];
			sa[cnt[rk[x]]--]=x;
		}
		
		swap(tmp,rk);
		rk[sa[1]]=1;
		rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(tmp[sa[i]]!=tmp[sa[i-1]]||tmp[sa[i]+l]!=tmp[sa[i-1]+l]);
	}
	
	rep(i,1,n)
	{
		int l=max(0,h[i-1]-1);
		while(s[i+l]==s[sa[rk[i]+1]+l])++l;
		mn_h[rk[i]+d]=h[i]=l;
	}
	per(i,(n+d)/2,1)mn_h[i]=min(mn_h[i*2],mn_h[i*2+1]);
}
bool ok_l(int i,int l)
{
	while(i>1)
	{
		if(i%2)
		{
			if(mn_h[i-1]<l)
			{
				--i;
				while(i<=d)
				if(mn_h[i*2+1]<l)i=i*2+1;
				else 
				{
					if(mx_dp[i*2+1]>=l)return 1;
					i=i*2;
				}
				return 0;
			}
			if(mx_dp[i-1]>=l)return 1;
		}
		i>>=1;
	}
	return 0;
}
bool ok_r(int i,int l)
{
	if(mn_h[i]<l)return 0;
	while(i>1)
	{
		if(i%2==0)
		{
			if(mn_h[i+1]<l)
			{
				++i;
				while(i<=d)
				if(mn_h[i*2]<l)i=i*2;
				else 
				{
					if(mx_dp[i*2]>=l)return 1;
					i=i*2+1;
				}
				return mx_dp[i]>=l;
			}
			if(mx_dp[i+1]>=l)return 1;
		}
		i>>=1;
	}
	return 0;
}
bool ok(int i,int l)
{
	i=rk[i]+d;
	return ok_l(i,l)||ok_r(i,l);
}
void add(int i)
{
	int x=dp[i];
	i=rk[i]+d;
	while(mx_dp[i]<x){mx_dp[i]=x;i>>=1;}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	scanf("%d%s",&n,s+1);
	for(d=1;d<n;d*=2);--d;
	init_sa();
	per(i,n,1)
	{
		dp[i]=dp[i+1]+1;
		//if(i==1)
		//	ok(2,1);
		while(dp[i]>1&&!ok(i,dp[i]-1)&&!ok(i+1,dp[i]-1))
		{
			--dp[i];
			add(i+dp[i]);
		}
	}
	int mx=0;
	rep(i,1,n)chmax(mx,dp[i]);
	cout<<mx;
}