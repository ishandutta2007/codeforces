#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e6+5,D=1e9+7;
ll mi(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}
int n,k;
char miu[N];int pr[N/10],top;
ll b[N],mi_[N];

int main()
{
//	freopen("1.in","r",stdin);
	n=read();k=read(); 
	rep(i,1,k)mi_[i]=mi(i,n); 
	
	memset(miu,2,sizeof(miu));
	miu[1]=1;
	rep(i,2,k)
	{
		if(miu[i]==2){miu[i]=-1;pr[++top]=i;}
		for(int j=1,x;x=pr[j],i*x<=k;++j)
		{
			if(i%x==0){miu[i*x]=0;break;}
			miu[i*x]=-miu[i];
		}
	}
	
	rep(d,1,k)
	{
		if(!miu[d])continue;
		int i=d,j=1;
		while(1)
		{
			b[i]+=miu[d]*mi_[j];
			i+=d;
			if(i>k)break;
			b[i]-=miu[d]*mi_[j];
			++j;
		}
	}
	rep(i,1,k) (b[i]+=b[i-1])%=D;
	ll ans=0;
	rep(i,1,k) 
	{
		ans+=(b[i]+D)%D^i;
	}
	cout<<ans%D;
}