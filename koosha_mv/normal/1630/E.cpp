#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99,mod=998244353;

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}
int P(int k,int n){if(k>n) return 0; return 1ll*ifac[n]*fac[n-k]%mod*fac[k]%mod;}

int n,t,a[N],cnt[N];
vector<int> v;

pair<int,int> calc(int x){
	int m=n/x,res1=1,res2=1,now=m,alp;
	for(auto id : v){
		res1=1ll*res1*C(cnt[id]/x,now)%mod;
		now-=cnt[id]/x;
	}
	alp=res1;
	res2=res1;
	for(auto id : v){
		if(cnt[id]/x>1){
			//cout<<alp*P(cnt[id]/x,m)%mod<<endl;
			Add(res1,mod-1ll*alp*P(cnt[id]/x,m)%mod*C(cnt[id]/x-2,m-2)%mod);
		}
	}
	//eror(res1);
	res1=1ll*res1*n%mod;
	//res1=1ll*res1*pow(x,mod-2,mod)%mod;
	//res2=1ll*res2*pow(x,mod-2,mod)%mod;
	return {res1,res2};
}
void Main(){
	f(i,0,n+9) cnt[i]=0; v.clear();
	vector<int> div;
	vector<pair<int,int>> dp;
	int ans=0,tgh=0;
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x; x--;
		cnt[x]++;
	}
	f(i,0,n){
		if(cnt[i]==n){
			cout<<1<<'\n';
			return ;
		}
	}
	int gcd=0;
	f(i,0,n){
		gcd=__gcd(gcd,cnt[i]);
		if(cnt[i]) v.pb(i);
	}
	f(j,1,gcd+1){
		if(gcd%j==0){
			div.pb(j);
			dp.pb(calc(j));
			//cout<<j<<" -> "<<dp.back().F<<" "<<dp.back().S<<endl;
		}
	}
	f_(i,div.size()-1,0){
		f(j,i+1,div.size()){
			if(div[j]%div[i]==0){
				Add(dp[i].F,mod-dp[j].F);
				Add(dp[i].S,mod-dp[j].S);
			}
		}
		int res=dp[i].F;
		Add(ans,1ll*dp[i].F*pow(n/div[i],mod-2,mod)%mod);
		Add(tgh,1ll*dp[i].S*pow(n/div[i],mod-2,mod)%mod);
	}
	cout<<1ll*ans*pow(tgh,mod-2,mod)%mod<<'\n';
}
main(){
	make_fac();
	cin>>t;
	while(t--){
		Main();
	}
}