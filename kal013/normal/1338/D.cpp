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
const int mod=1e9+7;
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

int dp[MaxN][3];

vi adj[MaxN];
int ans=1;

int dep[MaxN];
void dfs(int n,int p){
	dep[n]=dep[p]+1;
	dp[n][0]=0;
	dp[n][1]=1;
	vi a,b,d;	
	vi c;
	int sz=0;
	int mx1=0,mx2=0;
	for(auto e:adj[n]){
		if (e!=p){
			dfs(e,n);
			++sz;
			mx1=max(mx1,dp[e][0]);
			mx2=max(mx2,dp[e][1]);
			a.pb(dp[e][0]);
			b.pb(dp[e][1]);
			d.pb(dp[e][2]);
			c.pb(max(dp[e][0],dp[e][1]));
		}
	}
	if (sz==0) return;
	sort(all(a));
	sort(all(b));
	sort(all(c));
	int len=a.size();

	dp[n][0]=max(mx1,mx2);
	// trace(n,mx1,mx2,a);
	dp[n][1]=mx1+1;



	
	// if (a.size()>1) ++dp[n][0];
	// dp[n][0]=max(dp[n][0],)
	dp[n][0]+=sz-1;
	dp[n][2]=dp[n][0];

	ans=max(ans,dp[n][0]);
	ans=max(ans,dp[n][1]);



	if (a.size()>=2){


		int t1=c[len-1]+c[len-2];
		// trace(a,n,ans,t1,c,b,a);
		t1+=sz-1;
		if (p==0) --t1;
		ans=max(ans,t1);
		ans=max(ans,a[len-1]+a[len-2]+1);
	}

}

void solve(){
	int n;
	cin>>n;
	For(i,n-1){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dep[0]=0;
	dfs(1,0);
	// int z=1;
	// Rep(i,n){
	// 	if (dep[i]>dep[z]) z=i;
	// }

	// dfs(z,0);
	// Rep(i,n){
	// 	if (dep[i]>dep[z]) z=i;
	// }
	// dfs(z,0);


// 	For(i,100){
// 		int z=rand()%n;
// 		++z;
// 		dfs(z,0);
// 	}
	// Rep(i,n){
	// 	trace(i,dp[i][0],dp[i][1]);
	// }
	cout<<ans<<endl;
	// cout<<max(dp[1][0],dp[1][1])<<endl;
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