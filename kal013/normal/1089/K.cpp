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

inline int fib(int n,int a=1,int b=1,int c=1,int d=0,int acca=0,int accb=1,int m=mod){
    if (n==0) return acca;

    if (n&1) return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,((a*acca)%m+(b*accb)%m)%m,((c*acca)%m+(d*accb)%m)%m,m);
    else return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,acca,accb,m);
}

/*/-----------------------------Code begins----------------------------------/*/
#define M ((s+e)/2)
struct dat{
    int dif,ext,rng;
    bool end;
};

dat seg[maxn*10];
void combine(int a,int b,int c){
    seg[c].rng=seg[a].rng+seg[b].rng;
    int u=min(seg[a].ext,seg[b].dif);
    seg[c].dif=seg[a].dif+seg[b].dif-u;
    seg[c].ext=seg[b].ext+seg[a].ext-u;
    if (seg[b].end || seg[c].ext>0 || seg[b].dif<=seg[a].ext) seg[c].end=true;
    else seg[c].end=false;
}
dat comb(dat a,dat b){
    dat c;
    c.rng=a.rng+b.rng;
    int u=min(a.ext,b.dif);
    c.dif=a.dif+b.dif-u;
    c.ext=a.ext+b.ext-u;
    if (b.end || c.ext>0 || b.dif<=a.ext) c.end=true;
    else c.end=false;
    return c;
}


void build(int node, int s,int e){

    if (s==e){
        seg[node].dif=1;
        seg[node].ext=0;
        seg[node].rng=1;
        seg[node].end=false;
        return;
    }
    build(2*node,s,M);
    build(2*node+1,M+1,e);
    combine(2*node,2*node+1,node);
    
}

void update(int node,int s,int e,int l,int d){
    if (l>e || l<s) return;
    if (s==e){
        seg[node].dif=(d>0)?0:1;
        seg[node].ext=(d>0)?d-1:0;
        seg[node].end=(d>0)?true:false;
        return;
    }
    update(2*node,s,M,l,d);
    update(2*node+1,M+1,e,l,d);
    combine(2*node,2*node+1,node);
}
dat query(int node,int s,int e,int l,int r){
    if (l<=s && e<=r) return seg[node];
    if (l<=M) {
        dat tmp=query(2*node,s,M,l,r);
        if (r<=M) return tmp;
        return comb(tmp,query(2*node+1,M+1,e,l,r));
    }
    return query(2*node+1,M+1,e,l,r);
}


pii quer[maxn];
void solve(){
    int q;
    read(q);
    build(1,1,maxn);
    For(i,q){
        char t;
        read(t);
        if (t=='?'){
            int d;
            read(d);
            dat a=query(1,1,maxn,1,d);
            int ans=0;
            if (a.end) ++ans;
            ans+=a.ext;
            d1(ans);
            // trace(a.ext,a.dif,a.rng);
        }
        else if (t=='+'){
            int a,b;
            read(a);read(b);
            quer[i+1]={a,b};
            update(1,1,maxn,a,b);
        }
        else{
            int i,a,b;
            read(i);
            a=quer[i].F;b=quer[i].S;
            update(1,1,maxn,a,0);
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