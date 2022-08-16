/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
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
const int mod=1e9+7;
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
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


map<int,int> adj[maxn];


int sub[maxn],val[maxn];
int ai[maxn];
int P[maxn];
void dfs(int n,int p){
	sub[n]=val[n];
	P[n]=p;
	for(auto e:adj[n]){
		dfs(e.S,n);
		sub[n]+=sub[e.S];
	}
}

int timer[maxn];
int app[maxn];

vi G[maxn];

int sub2[maxn],bigC[maxn];

set<pii> cvals;

int offset=0;
void dfs2(int n){
	if (sub[n]==0) return;
	if (n==0){
		cvals.insert({0,0});
		for(auto e:G[n]){
			dfs2(e);
		}
		cvals.erase({0,0});
	}
	else{
		timer[n]=timer[P[n]]+1;
		if (val[n]==1){
			auto it=cvals.begin();
			// trace((*it),n,timer[n],P[n],offset);
			timer[n]=min(timer[n],(*it).F+offset+1);
		}

		cvals.insert({timer[n]-offset,n});
		app[n]=offset;
		offset+=val[n];

		for(auto e:G[n]){
			dfs2(e);
		}
		cvals.erase({timer[n]-app[n],n});




	}

}




void solve(){

	int n;
	cin>>n;

	Rep(i,n){
		int p;
		char c;
		cin>>p>>c;
		adj[p][(c-'a')]=i;
	}

	int k;
	cin>>k;
	For(i,k){
		cin>>ai[i];
		val[ai[i]]=1;
	}
	dfs(0,0);
	timer[0]=0;
	For(i,n+1){
		for(auto e:adj[i]){
			G[i].pb(e.S);
		}
		// trace(i,G[i]);
	}

	dfs2(0);
	// For(i,n+1){
	// 	trace(i,timer[i]);
	// }
	For(i,k){
		cout<<timer[ai[i]]<<" ";
	}
	cout<<endl;
	// trace(sub[0]);

}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   
    fio;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}