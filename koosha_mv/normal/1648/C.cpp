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

int fenwik[N],fact[N],ifact[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void math(){fact[0]=1; f(i,1,N) fact[i]=1ll*fact[i-1]*i%mod; ifact[N-1]=pow(fact[N-1],mod-2,mod);f_(i,N-2,0) ifact[i]=1ll*ifact[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fact[n]*ifact[n-k]%mod*ifact[k]%mod;}

void add(int x, int val){ for(x+=4;x<N;x+=x&-x) Add(fenwik[x],val); }
int get(int x) { int res=0; for (x+=4;x>0;x-=x&-x) Add(res,fenwik[x]); return res; }

int n,m,res=1,ans,a[N],cnt[N];

void upd(int x){
	add(x,mod-fact[cnt[x]]*ifact[cnt[x]-1]%mod);
	res=1ll*res*fact[cnt[x]]%mod*ifact[cnt[x]-1]%mod;
	cnt[x]--;
	if(cnt[x]>0){
		add(x,fact[cnt[x]]*ifact[cnt[x]-1]%mod);
	}
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	math();
	cin>>n>>m;
	f(i,1,n+1){
		int x;
		cin>>x;
		cnt[x]++;
	}
	f(i,1,m+1) cin>>a[i];
	f(i,0,N) res=1ll*res*ifact[cnt[i]]%mod;
	f(i,0,N){
		if(cnt[i]==0) continue ;
		add(i,fact[cnt[i]]*ifact[cnt[i]-1]%mod);
	}
	f(i,1,m+1){
		//eror(res%mod);
		Add(ans,fact[(n-i)]*get(a[i]-1)%mod*res%mod);;
		if(cnt[a[i]]==0) break;
		upd(a[i]);
		if(i==n && i<m){
		//	eror(1000);
			Add(ans,1);
		}
		//eror(ans);
	}
	cout<<ans;
}