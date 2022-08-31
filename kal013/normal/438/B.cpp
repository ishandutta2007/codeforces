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

const ll MAX = 1e5+15;

vll g[MAX];
ll dsu[MAX],sz[MAX];
bool done[MAX];

ll hd(ll x){
	if(x==dsu[x])return x;
	else return dsu[x]  = hd(dsu[x]);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll n,m;
	cin>>n>>m;
	ll i,j,k;
	ll a,b;
	vpll v;
	for(i=1;i<=n;i++){
		cin>>a;v.pb({a,i});
		dsu[i]=i;
		sz[i] = 1;
	}
	sort(v.begin(),v.end(),greater<pll>());
	for(i=0;i<m;i++){
		cin>>a>>b;
		g[a].pb(b);g[b].pb(a);
	}
	ll ans =0 ;
	for(auto Z:v){
		ll z = Z.S; 
		ll curz = 1;
		ll cur = z;
		done[z] = 1;
		for(auto y:g[z]){
			if(hd(cur)==hd(y))continue;
			if(!done[y])continue;
			ll nz = sz[hd(y)];
			ans+=nz*curz*Z.F;
			dsu[hd(cur)] = hd(y);
			cur = hd(y);
			curz = sz[cur] = nz+curz;
		}
	}
	ld fin = (2.0*ans)/(n*(n-1));
	cout<<fin<<"\n";
}