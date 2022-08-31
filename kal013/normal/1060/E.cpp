#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"

// int mod=1e9+7;
// inline int mul(int a,int b){return (a*1ll*b)%mod;}
// inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
// inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
// inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
// inline int inv(int a){return power(a,mod-2);}
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 

const ll MAX = 	2e5+15;

vll g[MAX];
ll part[MAX];
ll no[2];
ll par[MAX];
ll subz[MAX];
ll ans = 0;
ll n;
void dfs(ll x){
	no[part[x]]++;
	subz[x]=1;
	for(auto z:g[x]){
		if(z==par[x])continue;
		par[z]= x;
		part[z] = 1-part[x];
		dfs(z);	
		subz[x] += subz[z];
		ans += subz[z]*(n-subz[z]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	cin>>n;
	ll i,j,k;
	ll a,b;
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		g[a].pb(b);g[b].pb(a);
	}
	part[1] =0;
	dfs(1);
	// trace(ans);
	ans/=2;
	// trace(no[0],no[1]);
	ans += (no[0]*no[1]+1)/2;
	cout<<ans;
}