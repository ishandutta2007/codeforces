#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2.5e5+20;

#define int ll

int n;
ll a[maxn];

map<ll,int>mp;
map<ll,int>::iterator it;

ll rk[maxn+100000],tot;
int s[maxn],sm[maxn];

#define fi first
#define se second

const int mod=998244353;

signed main()
{
	n=read();
	REP(i,1,n)cin>>a[i],s[i]=2;
	REP(i,1,n)
	{
		ll x=(ll)(pow(a[i],1.0/4)+1e-8);
		if(x*x*x*x==a[i])mp[x]+=4,a[i]=1,s[i]=0;
		else {
			x=(ll)(pow(a[i],1.0/3)+1e-8);
			if(x*x*x==a[i])mp[x]+=3,a[i]=1,s[i]=0;
			else{
				x=(ll)(sqrt(a[i])+1e-8);
				if(x*x==a[i])mp[x]+=2,a[i]=1,s[i]=0;
			}
		}
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		rk[++tot]=it->fi;
	}
	REP(i,1,n)REP(j,i+1,n)
	{
		if(a[i]==a[j])a[j]=1,sm[i]++,s[j]=0;
		if(__gcd(a[i],a[j])>1)rk[++tot]=__gcd(a[i],a[j]);
	}
	sort(rk+1,rk+tot+1); tot=unique(rk+1,rk+tot+1)-(rk+1);
	REP(i,1,n)REP(j,1,tot)if(a[i]%rk[j]==0)
	{
		while(a[i]%rk[j]==0)a[i]/=rk[j],mp[rk[j]]+=1+sm[i],s[i]--;
	}
	ll ans=1;
	for(it=mp.begin();it!=mp.end();it++)
	{
		ans=(ll)ans*(it->se+1)%mod;
	}
	REP(i,1,n)REP(j,1,s[i])ans=(ll)ans*(2+sm[i])%mod;
	printf("%lld\n",ans);
	return 0;
}