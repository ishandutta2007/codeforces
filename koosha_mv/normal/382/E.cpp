#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mod 1000000007
#define add(x,y) x=(x+y)%mod
const int N=53;
ll x,y,g,n,k,dp1[N][N],dp2[N][N],fac[N],two=mod/2+1,o,m;
//math 
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}

int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	Gett(n,k);
	dp2[1][0]=dp1[0][0]=1;
	f(i,2,n+1){
		f(j,1,i/2+1){
			m=0;
			f(l,0,i){
				f(p,0,j+1){
					o=(((dp1[l][p]*entekhab(l,i-1))%mod)*max(l,1ll)%mod*dp1[i-1-l][j-p]%mod*max(i-1-l,1ll))%mod;
					add(m,o);
				}
			}
			dp2[i][j]=(m*two)%mod;
			m=0;
			f(l,0,i){
				f(p,0,j){
					o=(((((dp2[l][p]*entekhab(l,i-1)%mod)*(dp1[i-1-l][j-p-1]*2+dp2[i-1-l][j-p-1]))%mod)*max(i-1-l,1ll))%mod)*max(l,1ll);o%=mod;
					add(m,o);
				}
			}
			dp1[i][j]=(m*two)%mod;
		}
	}
	cout<<(dp1[n][k]+dp2[n][k])%mod;
}