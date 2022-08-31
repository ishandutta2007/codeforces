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

#define int long long
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
vll v;
ll n,A,cf,cm,m;
const int N=1e5+100;
int pref[N];
vpll g;
inline ll res(int x,int mf){
	return mf*x-pref[x];
}


ll calc(ll i,ll x){
	if (v[i]<=x) return res(i+1,x);
	auto it=upper_bound(v.begin(),v.end(),x)-v.begin();
	--it;
	return res(it+1,x);
}
ll cntmin(ll i,ll tot){
	if (tot<0) return -1;
	if (i<0) return A*cm;
	
	ll lo=0,hi=A,ans=0;
	while (lo<=hi){
		ll mid=(lo+hi)>>1;
		ll xx=calc(i,mid);
		if (xx<=tot){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	return ans*cm;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	cin>>n>>A>>cf>>cm>>m;
	v.resize(n);
	ll i,j;
	for(i=0;i<n;i++){
		cin>>v[i];
		g.pb({v[i],i});
	}
	sort(v.begin(),v.end());
	sort(g.begin(),g.end());
	pref[0]=0;
	for(int i=0;i<n;++i){
		pref[i+1]=pref[i]+v[i];
	}

	ll cnt=0;
	ll tot=m;
	pll ans={cntmin(n-1,m),0ll};
	++cnt;
	while (cnt<=n){
		tot-=A-v[n-cnt];
		i=n-cnt-1;
		if (tot>=0){
			pll zzz={(cntmin(i,tot)+cf*cnt),cnt};
			ans=max(zzz,ans);
		}
		else{
			break;
		}
		++cnt;
	}
	cout<<ans.F<<endl;
	ll mf=cm?(ans.F-ans.S*cf)/cm:0;
	for(ll i=n-1;i>=0;--i){
		if (n-i<=ans.S){
			v[g[i].S]=A;
		}
		else{
			v[g[i].S]=max(g[i].F,mf);
		}

	}
	for(auto x:v){
		cout<<x<<" ";
	}

}