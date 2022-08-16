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


const ll INF = 1e18;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll n,k;cin>>n>>k;
	vll v(n);ll i,j;
	for(i=0;i<n;i++){
		cin>>v[i];
	}
	ll l,r;
	multiset<ll> in,out;
	ll ans = -INF;
	for(l=0;l<n;l++){
		for(r=l;r<n;r++){
			ll cur=0;
			in.clear();out.clear();
			for(i=0;i<n;i++){
				if(i<l || i>r)out.I(v[i]);
				else {in.I(v[i]);cur+=v[i];}
			}
			auto it = in.begin();
			ans = max(ans,cur);
			if(out.size()==0)continue;
			auto it1 = --(out.end());
			for(j=0;j<k;j++){
				if(it==in.end())break;
				if((*it1) > (*it)){
					cur += (*it1) - (*it);
					ans = max(ans,cur);
					it++;
					if(it1==out.begin())break;
					it1--;
				}	
				else break;
			}
			ans = max(ans,cur);
		}	
	}
	cout<<ans;
}