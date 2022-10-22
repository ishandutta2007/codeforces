#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first

const int N=3e5+99;

ll n,gc,mod=1e9+7,fac[N],cnt[N],mark[N],x,y,g,a[N],di[N];
vector<int> p;

//math
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r>n) return 0;if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
ll tavan(ll x,ll y){ll p;if(y==0) return 1;if(y%2==0){p=tavan(x,y/2);return (p*p)%mod;}return (tavan(x,y-1)*x)%mod;}

ll calc(ll x){
	ll ans=0;
	f(i,2,N){
		if(di[i]==1)
			ans=(ans+entekhab(x,cnt[i]))%mod;
		if(di[i]==0)
			ans=(ans+mod-entekhab(x,cnt[i]))%mod;
	}
	return ans;
}
int main(){
	f(i,2,N){
		if(mark[i]==0){
			p.pb(i);
			for(int j=i*2;j<N;j+=i)
				mark[j]=1;
		}
	}
	fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(a[i]==1) return cout<<1,0;
		gc=__gcd(gc,a[i]);
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				cnt[j]++;
				if(j*j!=a[i])
					cnt[a[i]/j]++;
			}
		}
	}
	if(gc>1) return cout<<-1,0;
	f(i,2,N){
		ll c=i;
		for(int j=0;p[j]*p[j]<=i;j++){
			if(i%(p[j]*p[j])==0){di[i]=-1;break;}
			if(i%p[j]==0){
				c/=p[j];
				di[i]=1-di[i];
			}
		}
		if(c>1 && di[i]!=-1)
			di[i]=1-di[i];
	}
	f(i,2,7){
		if(calc(i)!=entekhab(i,n))
			return cout<<i,0;
	}
	cout<<7;
}