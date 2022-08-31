/*/ Author: kal013 /*/
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
// #define int long long
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
inline void read(auto &x) {cin>>x;}
#endif
inline int fast_expo(int base,int power,int modulo=mod){
    base%=mod;
    if (base<0) base+=mod;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        cnt>>=1;
    }
    // int tmp=ans;
    return ans;
}

inline int fib(int n,int a=1,int b=1,int c=1,int d=0,int acca=0,int accb=1,int m=mod){
    if (n==0) return acca;

    if (n&1) return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,((a*acca)%m+(b*accb)%m)%m,((c*acca)%m+(d*accb)%m)%m,m);
    else return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,acca,accb,m);
}

/*/-----------------------------Code begins----------------------------------/*/

// string morse[char_size]={".-","-...","-.-.","-..",".","..-.","--.","....","..", ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};


struct Tree{
    int n;
    vector<vi> adj;
    vector<int> st,en,euler,val,seg;
    Tree(){};
    Tree(int N){
        n=N;
        adj.resize(n);
        st.resize(n);
        en.resize(n);
        val.resize(n);
        seg.resize(4*n);
    }
    void clear(){
        n=0;
        adj.clear();
        st.clear();
        en.clear();
        val.clear();
        seg.clear();
    }
    void resize(int N){
        n=N;
        adj.resize(n);
        st.resize(n);
        en.resize(n);
        val.resize(n);
        seg.resize(4*n);
    }
    void add_edge(int u,int v){
        adj[u].pb(v);
        adj[v].pb(u);
    }
    void dfs(int n,int p){
        st[n]=euler.size();
        euler.pb(n);
        for(auto x:adj[n]){
            if (x!=p) dfs(x,n);
        }
        en[n]=euler.size()-1;
    }
    void update(int l,int r,int v,int node,int s,int e){
        if (r<s || l>e) return;
        if (l<=s && e<=r) {seg[node]+=v;return;}
        int M=((s+e)>>1);
        update(l,r,v,2*node,s,M);update(l,r,v,2*node+1,M+1,e);
    }
    void update(int u,int v){
        update(st[u],en[u],v,1,0,n-1);
    }
    inline int query(int l,int node,int s,int e){
        if (s==e) return seg[node];
        int M=((s+e)>>1);
        if (l<=M) return seg[node]+query(l,2*node,s,M);
        else return seg[node]+query(l,2*node+1,M+1,e);
    }
    inline int total(int u){
        return query(st[u],1,0,n-1);
    }
};



// Not tested
const int char_size=26;
struct node{
    int to[char_size],cnt,link,depth;
    node(){
        For(i,char_size) to[i]=-1;
        cnt=0,link=-1,depth=0;
    }
    node(int d){
        For(i,char_size) to[i]=-1;
        cnt=0,link=-1,depth=d;
    }
};


struct aho_corasick{
    vector<node> trie;
    Tree updates;
    aho_corasick(){
        node root;
        root.link=0;
        trie.pb(root);
    }
    int add_string(string s){
        int v=0;
        for(auto X:s){
            int x=(X-'a');
            if (trie[v].to[x]==-1){
                trie[v].to[x]=trie.size();
                node curr(trie[v].depth+1);
                trie.pb(curr);
            }
            v=trie[v].to[x];
        }
        ++trie[v].cnt;
        return v;
    }
    void build_link(){
        updates.resize(trie.size());
        queue<int> bfs;
        bfs.push(0);
        while(!bfs.empty()){
            int v=bfs.front();
            int suff=trie[v].link;
            bfs.pop();
            For(i,char_size){
                if (trie[v].to[i]!=-1){
                    int u=trie[v].to[i];
                    trie[u].link=(trie[u].depth==1)?0:trie[suff].to[i];
                    updates.add_edge(trie[u].link,u);
                    // trie[u].cnt+=trie[trie[u].link].cnt;
                    bfs.push(u);
                }
                else{
                    trie[v].to[i]=(v!=suff)?trie[suff].to[i]:0;
                }
            }
        }
        updates.dfs(0,0);
        For(i,trie.size()) updates.update(i,trie[i].cnt);
        
    }
    int match(string s){
        int v=0,ans=0;
        for(auto X:s){
            int x=X-'a';
            v=trie[v].to[x];
            ans+=updates.total(v);
        }
        return ans;
    }
};

string a[MaxN];
int id[MaxN];
bool inc[MaxN];
void solve(){
    int n,k;
    read(n);read(k);
    aho_corasick U;
    For(i,k) {
        read(a[i]);
        id[i]=U.add_string(a[i]);
        inc[i]=true;
    }
    U.build_link();
    string s;
    For(i,n){
        char t;
        cin>>t;
        if (t=='?'){
            cin>>s;
            d1(U.match(s));
        }
        else if (t=='+'){
            int x;read(x);
            --x;
            if (inc[x]) continue;
            inc[x]=true;
            U.updates.update(id[x],1);
        }
        else{
            int x;
            read(x);
            --x;
            if (!inc[x]) continue;
            inc[x]=false;
            U.updates.update(id[x],-1);
        }
        
    }
    
    
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