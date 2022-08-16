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

ll rz[MAX],cz[MAX];
gp_hash_table<ll,ll> mr[MAX],mc[MAX];

const ll CH = 320;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll n;
	cin>>n;
	ll i,j,k;
	ll x,y;
	for(i=0;i<n;i++){
		cin>>x>>y;
		mr[x][y] = 1; rz[x]++;
		mc[y][x] = 1; cz[y]++;
	}
	set<pll> ro,co;
	for(i=0;i<MAX;i++){
		if(rz[i]>0)ro.I({rz[i],i});
		if(cz[i]>0)co.I({cz[i],i});
	}
	ll done = 0;
	ll ans = 0;
	while(done<n){
		vpll pts;
		auto z = *ro.begin();
		ll wh = 0;
		// trace(z);
		if(z.F<CH){
			for(auto v:mr[z.S]){
				// trace(v);
				if(v.S==1)
					pts.pb({z.S,v.F});
			}
		}	
		else{
			wh=1;
			z = *co.begin();
			// trace(z);
			for(auto v:mc[z.S]){
				if(v.S==1)
					pts.pb({v.F,z.S});
			}
		}
		ll p = pts.size();
		for(i=0;i<p;i++){
			for(j=i+1;j<p;j++){
				if(wh==0){
					ll len = abs(pts[i].S - pts[j].S);
					ll nn[2];
					nn[0] = pts[i].F - len;
					nn[1] = pts[i].F + len;
					for(k=0;k<2;k++){
						if(nn[k]<0 || nn[k] >MAX)continue;
						bool pos = true;
						if(mr[nn[k]][pts[i].S]!=1)pos = false;
						if(mr[nn[k]][pts[j].S]!=1)pos = false;
						if(pos)ans++;
					}
 				}
 				else{
 					ll len = abs(pts[i].F - pts[j].F);
					ll nn[2];
					nn[0] = pts[i].S - len;
					nn[1] = pts[i].S + len;
					for(k=0;k<2;k++){
						if(nn[k]<0 || nn[k] >MAX)continue;
						bool pos = true;
						if(mc[nn[k]][pts[i].F]!=1)pos = false;
						if(mc[nn[k]][pts[j].F]!=1)pos = false;
						if(pos)ans++;
					}
 				}
			}
		}
		vll row,col;
		if(wh==0){for(auto z:pts)col.pb(z.S);row.pb(pts[0].F);}
		else{for(auto z:pts)row.pb(z.F);col.pb(pts[0].S);}
		for(auto z:col){
			co.erase({cz[z],z});
		}
		for(auto z:row){
			ro.erase({rz[z],z});
		}
		for(auto z:pts){
			done++;
			mr[z.F][z.S]=0;
			mc[z.S][z.F]=0;
			rz[z.F]--;
			cz[z.S]--;
		}
		for(auto z:col){
			if(cz[z])co.I({cz[z],z});
		}
		for(auto z:row){
			if(rz[z])ro.I({rz[z],z});
		}
		// trace(pts);
		// done++;
	}
	cout<<ans;
}