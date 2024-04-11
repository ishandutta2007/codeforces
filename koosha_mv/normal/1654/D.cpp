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

const int N=2e5+99,mod=998244353;

ll n,t,cnt,sum,a[N],st[N],inv[N],ft[N];
int lazy[N<<2],seg[N<<2];
vector<pair<ll,ll>> vec[N];
vector<pair<ll,pair<ll,ll>>> g[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

ll merge(ll u,ll v){
	return max(u,v);
}
void shift(ll id){
   seg[id*2+0]+=lazy[id];
   seg[id*2+1]+=lazy[id];
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void add(ll L,ll R,ll val,ll id=1, ll l=1,ll r=n+1){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id]+=val;
      return ;   
   }
   ll mid=(l+r)>>1;
   shift(id);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
ll query(ll L,ll R,ll id=1,ll l=1,ll r=n+1){
   if(r<=L || R<=l) return N;
   if(L<=l && r<=R){
      return seg[id];
   }
   shift(id);
   ll mid=(l+r)>>1;
   return merge(query(L,R,id*2+0,l,mid),query(L,R,id*2+1,mid,r));
}
void dfs1(ll u,ll p){
	st[u]=cnt++;
	for(auto P : g[u]){
		ll v=P.F;
		pair<ll,ll> e=P.S;
		if(v==p) continue ;
		dfs1(v,u);
		for(ll i=2;i*i<=e.F;i++){
			while(e.F%i==0){
				vec[i].pb({v,-1});
				e.F/=i;
			}
		}
		if(e.F>1) vec[e.F].pb({v,-1});
		for(ll i=2;i*i<=e.S;i++){
			while(e.S%i==0){
				vec[i].pb({v,+1});
				e.S/=i;
			}
		}
		if(e.S>1) vec[e.S].pb({v,+1});
	}
	ft[u]=cnt;
}
void dfs2(ll u,ll p,ll res){
	Add(sum,res);
	for(auto v : g[u]){
		if(v.F==p) continue ;
		dfs2(v.F,u,1ll*res*v.S.F%mod*inv[v.S.S]%mod);
	}
}
void Main(){
	ll ans=1;
	sum=cnt=0;
	cin>>n;
	fill(seg,seg+(n<<2),0);
	fill(lazy,lazy+(n<<2),0);
	f(i,1,n){
		ll u,v,x,y,gcd;
		cin>>u>>v>>x>>y;
		gcd=__gcd(x,y);
		x/=gcd;
		y/=gcd;
		g[u].pb({v,{y,x}});
		g[v].pb({u,{x,y}});
	}
	dfs1(1,0);
	f(i,2,n+1){
		vector<pair<ll,ll>> v=vec[i];
		for(auto x : v){
			ll v=x.F,d=x.S;
			add(st[v],ft[v],d);
		}
		ll res=seg[1];
		while(res--){
			ans=1ll*ans*i%mod;
		}
		for(auto x : v){
			ll v=x.F,d=x.S;
			add(st[v],ft[v],-d);
		}
	}
	dfs2(1,0,ans);
	cout<<sum<<'\n';
	f(i,1,n+1) vec[i].clear(),g[i].clear();
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,1,N) inv[i]=pow(i,mod-2,mod);
	cin>>t;
	while(t--) Main();
}