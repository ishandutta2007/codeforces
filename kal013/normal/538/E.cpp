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


const ll MAX = 2e5+15;

vll g[MAX];
ll par[MAX];
ll subz[MAX];
ll maxA[MAX],minA[MAX],maxB[MAX],minB[MAX];

void dfs0(ll x){
	for(auto z:g[x]){
		if(z==par[x])continue;
		par[z] = x;dfs0(z);
		subz[x]+=subz[z];
	}
	if(subz[x]==0)subz[x]=1;
}
ll INF = 1e9;

void dfs1(ll x){
	ll m = subz[x];
	if(m==1){ minA[x] = minB[x] = maxA[x] =maxB[x] =1;return;}
	ll waste = 0;
	ll minwaste = INF;
	for(auto z:g[x]){
		if(z==par[x])continue;
		dfs1(z);
		waste += subz[z] - maxA[z] +1;
		minwaste = min(minwaste,subz[z] - maxB[z] +1);
	}	
	maxB[x] = m - waste +1; maxA[x] = m - minwaste +1;

	waste = 0;minwaste = INF;
	for(auto z:g[x]){
		if(z==par[x])continue;
		waste += minB[z]; 
		minwaste = min(minwaste,minA[z]);
	} 
	minA[x] = waste;
	minB[x] = minwaste;
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll n;cin>>n;
	ll i,j,k;ll a,b;
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		g[a].pb(b);g[b].pb(a);
	}
	dfs0(1);
	dfs1(1);
	cout<<maxA[1]<<" "<<minA[1];
}