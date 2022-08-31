#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> ostream& operator<<(ostream& os, vector<T> V){
	os<<"[ "; for(auto v : V) os << v << " "; return os<<"]";
}
template<class L, class R> ostream& operator<<(ostream& os, pair<L, R> P){
	return os<< "(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
template< typename Arg1>
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
void __f(const char* name, Arg1&& arg1){
	cout << name << ": "<< arg1 << endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ','); cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else 
#define trace(...) 1
#endif
#define ll long long
#define ld long double
#define pll pair<ll, ll> 
#define pii pari<ll, ll>
#define F first
#define S second
#define I insert
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<ll>
#define vll vector<ll>
const ll maxn=2e6+5;
const ll INF=1e18;
#define Rep(i,n) for(ll i=1;i<=n;++i)

ll tot[maxn],cnt[maxn];
ll c[maxn];

bool vis[maxn];

ll calc(ll ci,ll p){
	return (ci+p)/(p+1);
}
void solve(){
	ll n,u;
	cin>>n;

	for(ll i=0;i<n+10;++i){
		tot[i]=0;
		cnt[i]=0;
		c[i]=0;
	}
	ll K=0;
	// trace(n);
	Rep(i,n) {
		cin>>u;

		++c[u];
	}
	Rep(i,n){
		if (c[i]==0) continue;
		// trace(i,c[i]);
		++K;
		vi tmp;
		ll k=1;
		for(ll j=1;j*j<=c[i];++j){
			++cnt[j];
			++k;
			vis[j]=1;
			tot[j]+=calc(c[i],j);
			// if ((c[i]%(j+1))==0){
			// 	tot[j]+=c[i]/(j+1);

			// }
			// else tot[j]+=c[i]/j;
			// trace(j,cnt[j],c[i],tot[j]);
			tmp.pb(j);
		}	
		k++;
		k+=5;

		k=min(k,c[i]);

		for(ll x=k;x>0;--x){
			ll tp=(c[i])%x;
			ll p=(c[i]-tp)/x;
			if (!vis[p]){
				vis[p]=1;
				++cnt[p];
				tmp.pb(p);
				tot[p]+=calc(c[i],p);
				// if (c[i]%(p+1)==0){
				// 	tot[p]+=(c[i])/(p+1);
				// }
				// else tot[p]+=c[i]/p;
				// tot[p]+=x;
			}
			if (tp==0){
				p-=1;
			}
			if (!vis[p]){
				vis[p]=1;
				++cnt[p];
				tmp.pb(p);
				tot[p]+=calc(c[i],p);
				// if (c[i]%(p+1)==0){
				// 	tot[p]+=(c[i])/(p+1);
				// }
				// else tot[p]+=c[i]/p;
				// tot[p]+=x;
			}
		}





		for(auto x:tmp){
			vis[x]=0;
		}
	}
	// trace(K);
	ll m=INF;
	for(ll p=1;p<=n;++p){
		if (cnt[p]==K) {m=min(m,tot[p]);
			// trace(p,K);
		}
	}
	cout<<m<<endl;
	

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}