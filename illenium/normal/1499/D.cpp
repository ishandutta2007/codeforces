#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 20000005
#define N 100005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

bool is[maxn];
int pri[maxn],cnt;
ll num[maxn];

inline void pre()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!is[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			int k=pri[j]*i; if(k>maxn-5) break; is[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}

inline ll Q(ll i)
{
	if(num[i]) return num[i];
	ll tmp=1,p=i;
	for(int j=1;pri[j]*pri[j]<=p&&j<=cnt;j++)
	{
		if(p%pri[j]==0)
		{
			while(p%pri[j]==0) p/=pri[j];
			tmp<<=1;
		}
		if(!is[p]) break;
	}
	if(p!=1) tmp<<=1; num[i]=tmp;
	return num[i];
}

int main()
{
	pre(); int T=read();
	while(T--)
	{
		ll c=read(),d=read(),x=read(),ans=0;
		
		for(int i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				if((x+i*d)%(i*c)==0) ans+=Q((x+i*d)/(i*c));
				if(i*i!=x&&(x+(x/i)*d)%((x/i)*c)==0) ans+=Q((x+(x/i)*d)/((x/i)*c));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}