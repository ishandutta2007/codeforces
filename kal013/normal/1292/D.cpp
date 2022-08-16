/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...)
#endif
const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+9;
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set
#endif

inline int fast_expo(int base,int power,int modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    // int tmp=ans;
    return ans;
}
inline int inv(int base,int modulo=mod){
    return fast_expo(base,modulo-2,modulo);
}


/*/-----------------------------Code begins----------------------------------/*/

const int N=5001;
int cnt[N][N];
bool seive[N];
ll dis[N];
vi primes;



int invi[N];
vpi adj[3*N];
vpi fact[3*N];

vpi prv[N];


int fa[N],so[N];

map<vpi,int> idx;

set<int> hsh;

int po[N][N];

int chsh[N];
int comp=0;

void pre(){


	for(int i=2;i<N;++i) seive[i]=1;
	for(int i=1;i<N;++i) invi[i]=inv(i);
	for(int i=2;i<N;++i){
		if (seive[i]){
			cnt[i][i]=1;
			for(int j=i+i;j<N;j+=i){
				seive[j]=0;
				cnt[j][i]=cnt[j/i][i]+1;
			}
			primes.pb(i);
		}
	}
	fa[1]=1;
	so[1]=1;
	for(int i=2;i<N;++i){
		for(auto j:primes){
			cnt[i][j]+=cnt[i-1][j];
			dis[i]+=cnt[i][j];
		}
	}
	reverse(all(primes));

	idx[fact[1]]=++comp;
	++comp;
	for(int i=2;i<N;++i){
		for(auto j:primes){
			if (cnt[i][j]==0) continue;
			fact[i].pb({j,cnt[i][j]});
		}
		idx[fact[i]]=comp++;
	}

	for(int i=2;i<N;++i){
		vpi T;
		int z1=0;
		for(int z=0;z<min(fact[i].size(),fact[i-1].size());++z){
			if (fact[i][z].F!=fact[i-1][z].F) {
				break;
			}
			z1+=fact[i-1][z].S;
			if (fact[i][z].S!=fact[i-1][z].S){
				T.pb(fact[i-1][z]);

				break;
			}
			T.pb(fact[i][z]);
		}


		if (idx.find(T)==idx.end()){
			fact[comp]=T;
			dis[comp]=z1;
			idx[T]=comp++;
		}
	}	

	// for(int i=0;i<comp;++i){
	// 	ll t1=1;
	// 	for(auto e:fact[i]){
	// 		t1=(t1*fast_expo(e.F,e.S))%mod;
	// 	}
	// 	chsh[i]=t1;


	// 	hsh.insert(t1);
	// 	// ll res=0;
	// 	// int n=T.size();

	// 	// while(T.size()>0){
	// 	// 	--T[n-1].S;
	// 	// 	if (T[n-1].S==0) T.pop_back();
	// 	// 	++res;
	// 	// 	if (idx.find(T)!=idx.end()){
	// 	// 		int z=idx[T];
	// 	// 		adj[i].pb({res,z});
	// 	// 		adj[res].pb({i,z});
	// 	// 		break;
	// 	// 	}

	// 	// }

	// }

	// for(int i=0;i<comp;++i){
	// 	int z=chsh[i];
	// 	int n=fact[i].size();
	// 	ll res=0;
	// 	while(fact[i].size()>0){
	// 		--fact[i][n-1].S;
	// 		z=(z*invi[fact[i][n-1].F])%mod;
	// 		++res;

	// 		if (fact[i][n-1].S==0){
	// 			fact[i].pop_back();--n;
	// 		}
	// 		if (hsh.find(z)==hsh.end()) continue;
	// 		auto it=idx.find(fact[i]);
	// 		if (it!=idx.end()){
	// 			z=(*it).S;
	// 			adj[i].pb({z,res});
	// 			adj[z].pb({i,res});
	// 			break;
	// 		}
	// 	}

	// }
	// trace(hsh.size(),comp);

}

ll getdis(int i,int j){

	int z=0;

	ll use=0;

	for(;z<min(fact[i].size(),fact[j].size());++z){
		if (fact[i][z].F!=fact[j][z].F) break;
		use+=min(fact[i][z].S,fact[j][z].S);
		if (fact[i][z].S!=fact[j][z].S) break;
	}
	return dis[i]+dis[j]-2*use;


}

int tot[3*N];


int dfs(int x,int p,int v){
	if (tot[x]>0)trace(x,p,v);
	ll t=tot[x]*v;
	for(auto e:adj[x]){
		if (e.F!=p){
			t+=dfs(e.F,x,v+e.S);
		}
	}
	return t;
}	


bool vis[N];


int prf[30],suf[30];
int prf2[30];

// ll getdis(map<int,int>& M){
// 	prf[0]=M[0];
// 	auto it=M.rbegin();
// 	int mx=(*it).F;
// 	for(int i=1;i<=mx;++i){
// 		prf[i]=prf[i-1]+M[i];
// 	}
// 	prf2[0]=0;

// 	for(int i=1;i<=mx;++i){
// 		prf2[i]=prf2[i-1]+i*M[i];
// 	}

// 	if (mx>0) trace(M);
// 	ll ans=INF;
// 	ll x1=0,mul=0;
// 	for(int i=mx;i>=0;--i){
// 		ans=min(ans,prf[i]*i-prf2[i]+x1-mul*i);
// 		if (mx>0) trace(mx,ans,x1,mul,i);
// 		x1+=i*M[i];
// 		mul+=M[i];
// 	}
// 	if (mx>0) trace(ans);
// 	return ans;



// }
void solve(){
	vi iter;

	int n;
	cin>>n;
	int x;
	Rep(i,n){
		cin>>x;
		if (x==0) x=1;
		if (!vis[x]){
			vis[x]=1;
			iter.pb(x);
		}
		++tot[x];
	}
	ll ans=INF;
	for(int i=0;i<comp;++i){
		ll t1=0;
		for(auto z:iter){
			t1+=tot[z]*getdis(i,z);
			if (t1>=ans) break;
		}
		// if (t1==7){
		// 	trace(i,fact[i]);
		// 	for(auto k:iter){
		// 		trace(fact[k],getdis(i,k));
		// 	}
		// }
		ans=min(ans,t1);
	}
	cout<<ans<<endl;

}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   
    fio;
    int t=1;
    pre();

    // cin>>t;
    while(t--) {
        solve();
    }
}