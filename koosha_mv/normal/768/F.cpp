#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int N=5e6+99,mod=1e9+7;

int a,b,h,ans,all;

int fact[N],ifact[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void math(){fact[0]=1; f(i,1,N) fact[i]=1ll*fact[i-1]*i%mod; ifact[N-1]=pow(fact[N-1],mod-2,mod);f_(i,N-2,0) ifact[i]=1ll*ifact[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fact[n]*ifact[n-k]%mod*ifact[k]%mod;}

int G(int p,int t,int x){
	x-=p*t;
	if(x<0) return 0;
	if(p==0){
		return x==0;
	}
	return C(p-1,p+x-1);
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	math();
	cin>>a>>b>>h;
	f(i,1,a+b+1){
		int s=i/2,t=i-s;
		Add(all,1ll*G(s,1,a)*G(t,1,b)%mod);
		Add(all,1ll*G(t,1,a)*G(s,1,b)%mod);
		Add(ans,1ll*G(s,1,a)*G(t,h+1,b)%mod);
		Add(ans,1ll*G(t,1,a)*G(s,h+1,b)%mod);
	}
	cout<<1ll*ans*pow(all,mod-2,mod)%mod<<endl;
}