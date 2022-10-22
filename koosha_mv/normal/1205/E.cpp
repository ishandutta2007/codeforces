#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99,mod=1e9+7;

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

ll n,k,ans,d[N],cnt[N];
vector<ll> v[N];

int main(){
	cin>>n>>k;
	f_(i,n-1,1){
		ll x=(n-1)/i;
		v[i].pb(0);
		v[i].pb(0);
		f(j,2,x*2+1){
			ll m=abs(x-abs(x+1-j));
			v[i].pb(m);
		}
		for(int j=i*2;j<n;j+=i){
			f(k,0,v[j].size())
				v[i][k*j/i]-=v[j][k];
		}
		f(j,0,v[i].size())
			cnt[max(1ll*i,1ll*j*i-n)]+=v[i][j];
	}
	f(i,1,n)
		Add(ans,pow(k,i,mod)*cnt[i]%mod);
	cout<<ans*pow(pow(k,n,mod),mod-2,mod)%mod;
}