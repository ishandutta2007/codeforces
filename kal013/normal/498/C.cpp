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




// Tested on https://codeforces.com/problemset/problem/852/D

const int inf=1e6;

struct Dinic{
    int n,s,t;
    int inf_flow=1e6;
    struct edge{
        int x,y,flow,cap;
        edge(int x,int y,int flow,int cap): x(x),y(y),flow(flow),cap(cap){};
    };
    int lim,flow;
    vector<bool> vis;
    vector<int> d,cur;
    vector<vector<int>> adj;
    vector<edge> edges;
    
    Dinic(int n,int l=1): n(n),lim(l){
        adj.resize(n);
        d.resize(n);
        cur.resize(n);
    }
    void addEdge(int from,int to,int cap,bool dir=true){
        adj[from].pb(edges.size());
        edges.pb(edge(from,to,0,cap));
        adj[to].pb(edges.size());
        edges.pb(edge(to,from,0,((dir) ? 0 : cap)));
    }
    bool bfs(){
        queue<int> q;
        q.push(s);
        For(i,n) d[i]=-1;
        d[s]=0;
        while(!q.empty() && d[t]==-1){
            int from=q.front();q.pop();
            for(auto id:adj[from]){
                int to=edges[id].y;
                if (d[to]!=-1 || edges[id].cap-edges[id].flow<lim) continue;
                d[to]=d[from]+1;
                q.push(to);
            }
        }
        
        return d[t]!=-1;
    }
    
    int dfs(int from,int push){
        if (push==0 || from==t) return push;
        for(;cur[from]<adj[from].size();cur[from]++){
            int id=adj[from][cur[from]];
            int to=edges[id].y;
            if (d[to]!=d[from]+1 || edges[id].cap-edges[id].flow<lim) continue;
            if (int pushed=dfs(to,min(push,edges[id].cap-edges[id].flow))){
                edges[id].flow+=pushed;
                edges[id^1].flow-=pushed;
                return pushed;
            }
        }
        return 0;
    }
    
    int maxFlow(int src,int snk){
        s=src;t=snk;
        flow=0;
        for(;lim>0;lim>>=1){
            while (bfs()){
                fill(all(cur),0);
                int pushed;
                while (pushed=dfs(s,inf_flow)){
                    flow+=pushed;
                }
            }
        }
        return flow;
    }
    void cut(int v){
        vis[v]=true;
        for(auto x:adj[v]){
            if (edges[x].flow<edges[x].cap && !vis[edges[x].y]){
                cut(edges[x].y);
            }
        }
    }
    // int minCut(int src=-1){
    //     vis.resize(n,false);
    //     cut((src==-1)?s:src);
    // }
};
const int N=300;
int a[N];
vpi fact[N];
map<int,int> cnt[N];
map<int,vi> divi;
vi adj[N];
void solve(){
	int n,m,u,v;
	cin>>n>>m;
	For(i,n){
		cin>>a[i];
		int x=a[i];
		for(int j=2;j*j<=x;++j){
			if (x%j!=0) continue;
			// trace(j,x);
			int cn=0;
			divi[j].pb(i);
			while(x%j==0){
				x/=j;
				++cn;
			}
			cnt[i][j]=cn;
		}
		if (x!=1){
			divi[x].pb(i);
			cnt[i][x]=1;
		}
	}
	For(i,m){
		cin>>u>>v;
		--u;--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int moves=0;
	// for(auto &e:divi){
	// 	sort(all(e));
	// }

	for(auto e:divi){
		int s=(e.S).size();
		if (s<=1) continue;
		map<int,int> idx;
		int ctr=1;
		Dinic U(s+4);
		int src=0,snk=s+3;
		for(auto k:e.S){
			idx[k]=ctr++;

		}
		for(auto k:e.S){
			if (k%2==0){
				U.addEdge(src,idx[k],cnt[k][e.F]);
				for(auto zz:adj[k]){
					if (idx.find(zz)!=idx.end()){
						U.addEdge(idx[k],idx[zz],inf);
					}
				}
			}
			else{
				U.addEdge(idx[k],snk,cnt[k][e.F]);
			}
		}
		moves+=U.maxFlow(src,snk);


		
		// int id=0;
		// trace(e,moves);
	}
	d1(moves);

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