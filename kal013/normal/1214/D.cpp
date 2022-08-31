/*/ Author: kal013 /*/
#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
typedef priority_queue<ppi,vppi,greater<ppi>> min_heap_ppi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define tern(a,b,c) (!!(a))*b+(!(a))*c
#define cross(i,a,b) ((tern(b>a,1,-1))*(i))>=((tern(b>a,1,-1))*(b))
#define loop(i,a,b) for(int i=a;i!=b;i+=tern(b>a,1,-1))
#define sloop(i,a,b,s) for(int i=a;(!(cross(i,a,b)));i+=s)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
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
//#define file cin
//#define codechef
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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
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
#ifdef codechef
inline void read(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
}
inline void read_str(char *str){
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}
#else
inline void read(int &x) {cin>>x;}
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

inline int fib(int n,int a=1,int b=1,int c=1,int d=0,int acca=0,int accb=1,int m=mod){
    if (n==0) return acca;

    if (n&1) return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,((a*acca)%m+(b*accb)%m)%m,((c*acca)%m+(d*accb)%m)%m,m);
    else return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,acca,accb,m);
}

/*/-----------------------------Code begins----------------------------------/*/

int n,m;
vi mat[maxn];
string s[maxn];
vi adj[maxn];
vi tmp[maxn];
int tin[maxn],low[maxn],timer,P[maxn],nx[maxn],dp[maxn],vp[maxn];
bool cut[maxn];
bool vis[maxn];
bool onpath[maxn];
inline int conv(int i,int j){
	return (i*m+j);
}


void dfs1(int n,int p){
	queue<pii> q;
	q.push({n,p});
	while (!q.empty()){
		auto X=q.front();
		q.pop();
		if (vis[X.F]) continue;
		vis[X.F]=true;
		P[X.F]=X.S;
		for(auto e:adj[X.F]){
			if (!vis[e])q.push({e,X.F});
		}
	}

	// P[n]=p;
	// vis[n]=true;
	// for(auto e:adj[n]){
	// 	if (vis[e] || e==p) continue;
	// 	dfs1(e,n);
	// 	tmp[n].pb(e);
	// }
}
// void dfs2(int n,int p){
// 	if (!onpath[n]){
// 		dp[n]=dp[p];
// 	}
// 	for(auto e:tmp[n]){
// 		dfs2(e,n);
// 	}
// }
// void dfs(int n,int p){
// 	vis[n]=true;
// 	trace(n,p);
// 	tin[n]=low[n]=timer++;
// 	P[n]=p;
// 	int chil=0;
// 	for(auto to:adj[n]){
// 		if (to==p) continue;
// 		if (vis[to]){
// 			low[n]=min(low[n],tin[to]);
// 		}
// 		else{
// 			dfs(to,n);
// 			low[n]=min(low[n],low[to]);
// 			if (low[to]>=tin[n] && p!=-1){
// 				cut[n]=true;
// 			}
// 			++chil;
// 		}
// 	}
// 	if (p==-1 && chil>1) cut[n]=true;
// }
int mattac=0;
map<int,int> pos;
void dfs(int n,int p,int v){
	vis[n]=true;
	dp[n]=min(dp[n],v);
	for(auto e:adj[n]){
		if (onpath[e]){
			mattac=max(mattac,dp[e]);
		}
		if (vis[e] || onpath[e] || e==p) continue;
		dfs(e,n,v);
	}
}

void solve(){
	
	cin>>n>>m;
	timer=0;
	mattac=0;
	For(i,n){
		cin>>s[i];
		mat[i].resize(m);
		For(j,m){
			if (s[i][j]=='.') mat[i][j]=1;
			else {
				assert(s[i][j]=='#');
				mat[i][j]=0;
			}
		}
	}
	For(i,n){
		For(j,m){
			int id=conv(i,j);

			dp[id]=INF;
			vp[id]=INF;
			// cut[id]=false;
			// tin[id]=-1;
			// low[id]=-1;
			onpath[id]=false;
			if (mat[i][j]==0) continue;
			
			// if (i!=0 && mat[i-1][j]==1){
			// 	adj[id].pb(conv(i-1,j));
			// }
			// if (j!=0 && mat[i][j-1]==1){
			// 	adj[id].pb(conv(i,j-1));
			// }
			if (i!=n-1 && mat[i+1][j]==1) {
				adj[id].pb(conv(i+1,j));
			}
			if (j!=m-1 && mat[i][j+1]==1){
				adj[id].pb(conv(i,j+1));
			}
		}
	}
	dfs1(0,-1);
	int id=conv(n-1,m-1);
	if (!vis[id]) {d1(0);return;}
	while (id>=0){
		onpath[id]=true;
		if (P[id]!=-1) nx[P[id]]=id;
		id=P[id];

	}
	id=conv(n-1,m-1);
	int cu=0;
	dp[cu]=0;
	vp[cu]=0;
	vi vert;
	vert.pb(0);
	while(cu!=id){
		dp[nx[cu]]=dp[cu]+1;
		vp[nx[cu]]=dp[nx[cu]];
		cu=nx[cu];
		vert.pb(cu);

	}
	For(i,n*m) vis[i]=false;
	for(auto e:vert){
		for(auto j:adj[e]){
			if (j!=P[e] && j!=nx[e]){
				// trace(e,j,nx[e]);
				assert(dp[j]>dp[e]);
			}
		}
	}
	// for(auto e:vert) vis[e]=true;
	for(auto e:vert){
		if (e!=0 && e!=n*m-1 && mattac<=dp[e]){
			// trace(e,dp[e],mattac);
			d1(1);
			return;
		}
		dfs(e,P[e],dp[e]);
	}

	// For(i,n){
	// 	For(j,m){
	// 		if (mat[i][j]==0) continue;
	// 		int id=conv(i,j);
	// 		// trace(id,i,j,dp[id]);
	// 		if (onpath[id]) continue;
	// 		for(auto e:adj[id]){
	// 			if (onpath[e]){
	// 				vp[e]=min(vp[e],dp[id]);
	// 			}
	// 		}
	// 	}
	// }
	// int mn=vert.size();
	// // trace(vert);
	// for(int i=vert.size()-1;i>=0;--i){
	// 	dp[vert[i]]=min(dp[vert[i]],mn);
	// 	mn=min(dp[vert[i]],vp[vert[i]]);

	// 	if (dp[vert[i]]==i && i!=vert.size()-1 && i!=0){
	// 		d1(1);
	// 		return;
	// 	}
	// }
	d1(2);

	


	// dfs(0,-1);
	
	// For(i,n){
	// 	For(j,m){
	// 		int id=conv(i,j);
	// 	}
	// }
	// if (!vis[id]){
	// 	d1(0);
	// 	return;
	// }
	// while (id>0){
	// 	id=P[id];
	// 	if (id!=0 && cut[id]){
	// 		d1(1);
	// 		return;
	// 	}
	// }
	// d1(2);

}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    fio;
    int t=1;
    // read(t);
    while(t--) {
        solve();
    }
}