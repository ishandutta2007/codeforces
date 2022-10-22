#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=302,mod=1e9+7;
ll dp[N][N],a[N],prime[N],fac[N],x,y,g,n,b[N],sb=1,c1,c2,cnt,sfr;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r>n) return 0;if(r==0) return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
int main(){
	fac[0]=1; f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++){
			while(a[i]%(j*j)==0)
				a[i]=a[i]/(j*j);
		}
	}
	sort(a,a+n);
	f(i,0,n){
		if(i!=0 && a[i]!=a[i-1]){
			sb++;
			b[sb]++;
		}
		else b[sb]++;
	}
	a[0]=0,n=sb+1;
	f(i,1,n) a[i]=b[i]+a[i-1];
	dp[1][b[1]-1]=1;
	f(i,2,n){
		f(j,0,a[i]){
			f(k,0,a[i-1]){
				f(l,max(sfr,k-j),min(k,b[i])+1){
					c1=b[i]-l;
					c2=j-(k-l);
					c1-=c2;
					if(c1>=0){
						cnt=(((dp[i-1][k]*entekhab(l,k))%mod)*entekhab(c1,a[i-1]-k+1))%mod;
						c1+=l;
						cnt=(cnt*entekhab(c1-1,c1+c2-1))%mod;
						dp[i][j]=(dp[i][j]+cnt)%mod;
					}
				}
			}
		}
	}
	f(i,0,n) dp[n-1][0]=(dp[n-1][0]*fac[b[i]])%mod;
	cout<<dp[n-1][0];
}