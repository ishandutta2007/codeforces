/*/ Author: kal013 /*/
#include <bits/stdc++.h>
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
// #define codechef
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ ";
	for(auto v : V) os << v << " ";
	return os << "]";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";
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
template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};
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
inline void read(auto &x) {cin>>x;}
#endif


/*/-----------------------------Code begins----------------------------------/*/



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
    int minCut(int src=-1){
        vis.resize(n,false);
        cut((src==-1)?s:src);
    }
};
vpi edges;
vector<int> c;
vi adj[100];
bool v[100];
bool pos(int s,int n){
    // trace(s,n);
    v[s]=true;
    if (s==n) return true;
    for(auto x:adj[s]){
        if (v[x]) continue;
        if (pos(x,n)) return true;
    }
    return false;
}
void solve(){
    int n,m,x,u,w,cur;
    read(n);read(m);read(x);
    long double low=0.0,high=1e6,ans=0.0;
    long double eps=1e-12;
    For(i,n) v[i]=false;
    For(i,m) {
        read(u);read(w);
        read(cur);
        edges.pb({--u,--w});
        adj[u].pb(w);
        c.pb(cur);
    }

    if (!pos(0,n-1)) {
        d1(0);
        return;
    }
    while (high-low>eps){
        long double mid=(low+high)/2.0;
        
        Dinic sol(n);
        For(i,edges.size()){
            // trace(c[i]/mid,c[i],i);
            cur=(int)(c[i]/mid);
            sol.addEdge(edges[i].F,edges[i].S,cur);
        }
        
        int y=sol.maxFlow(0,n-1);
        // trace(low,high,mid,eps,sol.flow,y,x);
        if (sol.flow>=x){
            ans=max(ans,mid);
            low=mid;
        }
        else{
            high=mid;
        }
    }
    
    // d1(eps/2);
    cout<<fixed<<setprecision(11)<<(ans*x);
    
    
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    fio;
    int t=1;
    // read(t);
    while(t--) {
        solve();
    }
}