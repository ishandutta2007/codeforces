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
const int maxn=2e6+100;
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


int x[maxn],y[maxn];
const int N=1040;
int d[N][N];
inline int dis(int i,int j){
	if (d[i][j]==0) d[i][j]=d[j][i]=((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]));

	return d[i][j];
}

int dsu[maxn];
int sz[maxn];


set<int> G[maxn];

inline int Fi(int x){
	return (x==dsu[x])?x:dsu[x]=Fi(dsu[x]);
}
inline void Me(int x,int y){
	x=Fi(x);
	y=Fi(y);
	if (x==y) return;
	if (sz[x]<sz[y]) swap(x,y);
	dsu[y]=x;
	sz[x]+=sz[y];
}

map<int,int> cnt;

// vi adj[maxn],radj[maxn];




set<pii> Pos[maxn];
bool sam[maxn];
vi adj[maxn];

// void dfs(int n){
// 	vis[n]=1;
// 	for(auto e:adj[n]){
// 		if (!vis[e]) dfs(e);
// 	}
// 	stk.pb(n);
// }

// void dfs2(int n,int cm){
// 	vis[n]=1;
// 	comp[n]=cm;
// 	for(auto e:radj[n]){
// 		if (!vis[e]) dfs2(e,cm);
// 	}
// }

map<int,int> idx;


void solve(){
	int n;
	cin>>n;
	For(i,n){
		cin>>x[i]>>y[i];
	}
	For(i,n){
		for(int j=i+1;j<n;++j) ++cnt[dis(i,j)];
	}
	int us=0;

	for(auto e:cnt){
		idx[e.F]=++us;
	}

	For(i,n){
		unordered_map<int,int> res;

		For(j,n){
			if (i!=j){
				++res[dis(i,j)];
				
			}
		}
		bool pos=1;
		for(auto e:res){
			if (e.S!=cnt[e.F]){
				pos=0;
				break;
			}
		}
		if (pos){
			cout<<1<<endl;
			cout<<i+1<<endl;
			return;
		}
	}
	For(i,n){
		dsu[i]=i;
		sz[i]=1;
	}


	For(i,n){

		unordered_map<int,int> prv;

		For(j,n){
			if (i!=j){
				int z=dis(i,j);
				if (prv.find(z)!=prv.end()){
					Me(j,prv[z]);
					// Me(2*j+1,2*prv[z]+1);
				}
				prv[z]=j;
			}	
		}

	}
	For(i,n){
		adj[Fi(i)].pb(i);
	}





	For(i,n){
		for(int j=i+1;j<n;++j){
			Pos[idx[dis(i,j)]].insert({min(Fi(i),Fi(j)),max(Fi(i),Fi(j))});
			if (Fi(i)==Fi(j)){
				sam[idx[dis(i,j)]]=1;
			}
		}
	}
	
	For(i,2*n){
		sz[i]=1;
		dsu[i]=i;
	}
	For(i,n){
		for(auto e:adj[i]){
			Me(2*i,2*e);
			Me(2*i+1,2*e+1);
		}
	}
	Rep(i,us){
		if (sam[i]){
			for(auto e:Pos[i]){
				Me(2*e.F,2*e.S);
				Me(2*e.F+1,2*e.S+1);
			}
		}
	}

	Rep(i,us){

		if (!sam[i]){

			bool op=1;
			for(auto e:Pos[i]){
				int s1=Fi(2*e.F),s2=Fi(2*e.S);
				if (s1==s2) op=0;
			}
			if (op){
				for(auto e:Pos[i]){
					Me(2*e.F,2*e.S+1);
					Me(2*e.F+1,2*e.S);
				}
			}
		}
	}

	// For(i,2*n){
	// 	Ans[Fi(i)].pb(i);
	// }	


	vector<int> A;
	A.pb(0);
	// set<int> use;
	// use.insert(0);
	// use.insert(1);


	int unuse=-1;
	int prv=0;
	vector<int> B;
	vector<int> rem;

	for(int i=1;i<n;++i) rem.pb(i);
	while(!rem.empty() && prv>=0){
		vector<int> tp;
		for(auto j:rem){
			// if (A.find(j)==A.end() && B.find(j)==B.end()){
				if (Fi(2*j)==Fi(2*prv)){
					A.pb(j);
					// use.insert(2*j);
					// use.insert(2*j+1);
				}
				else if (Fi(2*j+1)==Fi(2*prv)){
					B.pb(j);
					// use.insert(2*j);
					// use.insert(2*j+1);
				}
				else {
					if (unuse!=-1) tp.pb(unuse);
					unuse=j;
				}
			// }
		}
		rem.swap(tp);
		A.swap(B);
		prv=unuse;
		unuse=-1;
		if (prv>=0)A.pb(prv);

	}


	cout<<A.size()<<endl;
	for(auto e:A) cout<<e+1<<" ";
		cout<<endl;
	



	

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