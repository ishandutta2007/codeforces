/*/ Author: kal013 /*/
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
#define int long long
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
#define ll long long

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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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

const int N=7050;
int a[N],b[N];

bool mt[N][N];
// pii seg[MaxN];
int cnt[N];



// void build(int node,int s,int e){
// 	if (s==e){
// 		seg[node]={cnt[s],s};
// 	}
// 	else{
// 		int M = ((s+e)/2);
// 		build(2*node,s,M);
// 		build(2*node+1,M+1,e);
// 		seg[node]=max(seg[2*node],seg[2*node+1]);
// 	}
// }
// void update(int node,int s,int e,int l,int v){
// 	if (s==e){
// 		seg[node]={v,l};
// 		return;
// 	}
// 	int M = ((s+e)/2);
// 	if (l<=M) update(2*node,s,M,l,v);
// 	else update(2*node+1,M+1,e,l,v);
// 	seg[node]=max(seg[2*node],seg[2*node+1]);
// }
pii query(int n){
	pii res={-INF,-INF};
	For(i,n){
		res=max(res,{cnt[i],i});
	}
	return res;
}

// pii query(int node,int s,int e,int l,int r){
// 	if (l>e || r<s) return {-INF,-INF};
// 	if (l<=s && e<=r) return seg[node];
// 	int M= ((s+e)/2);
// 	return max(query(2*node,s,M,l,r),query(2*node+1,M+1,e,l,r));
// }
// vi adj[N],rev[N];
void solve(){
	int n;
	cin>>n;
	int msk=(1ll<<60)-1;
	For(i,n){
		cin>>a[i];
	}
	int res=0;

	For(i,n) {cin>>b[i];res+=b[i];}
	For(i,n){
		For(j,n){
			if (j==i) continue;
			int z=(a[j]^msk)&a[i];
			if (z!=0){
				mt[i][j]=1;
				// adj[i].pb(j);
				++cnt[i];
			}
			else{
				mt[i][j]=0;
			}
		}
	}
	// build(1,0,n-1);
	int x=n;
	while (x){
		pii X=query(n);
		// trace(X);
		if (X.F<x-1) break;
		// trace(X);
		int id=X.S;
		For(e,n){
			if (!mt[e][id] || !cnt[e]) continue;
			// trace(e,cnt[e]);
			if (cnt[e]<=0) continue;
			--cnt[e];
			// update(1,0,n-1,e,cnt[e]);
		}
		cnt[id]=-INF;
		// update(1,0,n-1,id,-INF);
		res-=b[id];
		--x;
	}
	d1(res);
	



}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    #ifndef ONLINE_JUDGE
        freopen("error.txt","w",stderr);
    #endif
    fio;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}