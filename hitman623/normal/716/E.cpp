#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define endl 		'\n'
using namespace std;

uint64_t hash_f(uint64_t x){ 
	x ^= x >> 33; x *= 0xff51afd7ed558ccd;
	x ^= x >> 33; x *= 0xc4ceb9fe1a85ec53;
	x ^= x >> 33; return x; 
}
struct chash {
	int operator()(int x) const { return hash_f(x);}
};

int n,powers[200005],inv[200005],mod;
int expo(int base,int exponent){
	int ans=1;
	while(exponent!=0){
		if(exponent&1) ans=(1LL*ans*base)%mod;
		base=(1LL*base*base)%mod;
		exponent>>=1;
	}
	return ans%mod;
}
void pre(){
	int phi=1,d=mod;;
	for(int i=2;i*i<=d;i++){
		if(d%i) continue;
		int f=1;
		while(d%i==0){
			d/=i;
			f*=i;
		}
		f/=i;
		phi*=f*(i-1);
	}
	if(d>1) phi*=(d-1);
	powers[0]=1;
	rep(i,1,2*n+1) powers[i]=(10*powers[i-1])%mod;
	inv[2*n]=expo(powers[2*n],phi-1);
	for(int i=2*n-1;i>=0;i--) inv[i]=(inv[i+1]*10)%mod;
}

int strt[100005],stop[100005],s[100005],depth[100005];
int heavy[100005],res;
gp_hash_table<int,int,chash> store1,store2;
vii a[100005];

void dfs(int node,int par){
	s[node]=1;
	int mx=0;
	for(auto i:a[node]){
		if(i.x==par) continue;
		strt[i.x]=(strt[node]+i.y*powers[depth[node]])%mod;
		depth[i.x]=depth[node]+1;
		stop[i.x]=(stop[node]*10+i.y)%mod;
		dfs(i.x,node);
		if(s[i.x]>mx){
			mx=s[i.x];
			heavy[node]=i.x;
		}
		s[node]+=s[i.x];
	}
}
void add(int node,int par){
	store1[stop[node]*inv[depth[node]]%mod]++;
	store2[strt[node]]++;
	for(auto i:a[node]){
		if(i.x!=par){
			add(i.x,node);
		}
	}
}
void query(int node,int par,int val,int u){
	int w1=(val-strt[node]+mod)*inv[2*depth[u]]%mod;
	int w2=(stop[node]*powers[2*depth[u]])%mod*inv[depth[node]]%mod;
	w2=(val-w2+mod)%mod;
	if(store1.find(w1)!=store1.end()) res+=store1[w1];
	if(store2.find(w2)!=store2.end()) res+=store2[w2];
	for(auto i:a[node]){
		if(i.x!=par){
			query(i.x,node,val,u);
		}
	}
}
void dfs2(int node,int par,int keep){
	for(auto i:a[node]){
		if(i.x!=heavy[node] and i.x!=par){
			dfs2(i.x,node,0);
		}
	}
	if(heavy[node]) dfs2(heavy[node],node,1);
	int val=(stop[node]*powers[depth[node]]+strt[node])%mod;
	int w1=(val-strt[node]+mod)*inv[2*depth[node]]%mod;
	int w2=stop[node]*powers[depth[node]]%mod;
	w2=(val-w2+mod)%mod;
	if(store1.find(w1)!=store1.end()) res+=store1[w1];
	if(store2.find(w2)!=store2.end()) res+=store2[w2];
	store1[stop[node]*inv[depth[node]]%mod]++;
	store2[strt[node]]++;
	for(auto i:a[node]){
		if(i.x!=par and i.x!=heavy[node]){
			query(i.x,node,val,node);
			add(i.x,node);
		}
	}
	if(!keep) store1.clear(),store2.clear();
}

void solve(){
	cin>>n>>mod;
	rep(i,0,n-1){
		int u,v,w;
		cin>>u>>v>>w;
		u++;
		v++;
		a[u].pb({v,w});
		a[v].pb({u,w});
	}
	pre();
	dfs(1,0);
	dfs2(1,0,0);
	cout<<res<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}