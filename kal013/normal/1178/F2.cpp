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
const int mod=998244353;
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
// inline void read(auto &x) {cin>>x;}
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
int a[maxn],b[maxn],c[maxn],L[maxn],R[maxn];
int vis[maxn];
int seg[2*maxn];
vi poss[maxn];
vi xpos;
int idx[maxn],reva[maxn],revb[maxn];
int dp[2050][2050];
map<int,bool> st[maxn];
void build(int n){
    for(int i=n;i<2*n;++i) seg[i]=c[i-n];
    for(int i=n-1;i>0;--i) seg[i]=min(seg[i<<1],seg[(i<<1)|1]);
}
int query(int l,int r,int n){
    assert(l<=r);
    int ans=c[l];
    ++r;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if (l&1) ans=min(ans,seg[l++]);
        if (r&1) ans=min(ans,seg[--r]);
    }
    return ans;
}

bool correct(int i,int j){
    if (j<i) return true;
    if (st[i].find(j)!=st[i].end()) return st[i][j];
    set<int> us;
    set<int> rem;
    for(int k=i;k<=j;++k){
        int x=xpos[k];
        if (x==a[idx[x]]) us.insert(idx[x]);
        if (x==b[idx[x]]) rem.insert(idx[x]);
    }
    bool pp=true;
    for(auto x:rem){
        auto it=us.find(x);
        if (it==us.end()){
            pp=false;
            break;
        }
        us.erase(it);
    }
    if (!us.empty()) pp=false;
    st[i][j]=pp;
    return st[i][j];
}

int state(int i,int j,int m,int done,int p1,int p2){
    
    if (i>j) return 1;
    // if (!correct(i,j)) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    // trace(done);
    int num=max(query(xpos[i],xpos[j],m+1),done+1);
    // trace(i,j,num,xpos[i],xpos[j],p1,p2);
    int l=reva[num],r=revb[num];
    // trace(l,r,num);
    
    while (l<i || r>j){
        if (r==j && i>l) return 0;
        if (l==i && r>j) return 0;
        ++num;
        l=reva[num];
        r=revb[num];
    }
    // trace(l,r,num);
    
    int curr=state(l+1,r-1,m,num,i,j);
    int left=0,right=0,cnt=0;
    for(int k=l;k>=i;--k){
        
        if (xpos[k]<L[num]) break;
        
        // trace(k,l-1);
        // trace(i,k-1);
        // trace(i,l);
        // if (query(xpos[k],xpos[l],m+1)<num) break;
        if (k!=l){
            int X=xpos[k];
            if (X==a[idx[X]]) ++cnt;
            if (X==b[idx[X]]) --cnt;
        }
        if (cnt==0) left+=(state(k,l-1,m,num,i,j)*state(i,k-1,m,num,i,j))%mod;
        if (left>=mod) left-=mod;
    }
    cnt=0;
    for(int k=r;k<=j;++k){
        
        if (xpos[k]>R[num]) break;
        // trace(r+1,k);
        // trace(k+1,j);
        // trace(r,j);
        // if (query(xpos[r],xpos[k],m+1)<num) break;
        if (k!=r){
            int X=xpos[k];
            if (X==a[idx[X]]) ++cnt;
            if (X==b[idx[X]]) --cnt;
        }
        if (cnt==0) right+=(state(r+1,k,m,num,i,j)*state(k+1,j,m,num,i,j))%mod;
        if (right>=mod) right-=mod;
    }
    int an=(left*right)%mod;
    an=(an*curr)%mod;
    dp[i][j]=an;
    return an;
    
}

bool pos(int n,int m){
    for(int i=1;i<=n;++i){
        if (query(a[i],b[i],m+1)<i) return false;
    }
    return true;
}


void solve(){
    int n,m;
    cin>>n>>m;
    // bool pos=true;
    for(int i=1;i<=n;++i){
        a[i]=m+1;
        b[i]=0;
    }
    for(int i=1;i<=m;++i){
        cin>>c[i];
        a[c[i]]=min(a[c[i]],i);
        b[c[i]]=max(b[c[i]],i);
    }
    
    build(m+1);
    
    if (!pos(n,m)){
        d1(0);
        return;
    }
    for(int i=1;i<=n;++i){
        
        xpos.pb(a[i]);
        idx[a[i]]=i;
        if (a[i]!=b[i]) xpos.pb(b[i]);
        idx[b[i]]=i;
        
    }
    
    
    sort(all(xpos));
    // trace(xpos);
    for(int j=0;j<xpos.size();++j){
        int x=xpos[j];
        if (x==a[idx[x]]) reva[idx[x]]=j;
        if (x==b[idx[x]]) revb[idx[x]]=j;
    }
    For(i,xpos.size()) For(j,xpos.size()) dp[i][j]=-1;
    for(int i=1;i<=n;++i){
        for(int xl=a[i];xl>0;--xl){
            if (c[xl]<i) break;
            L[i]=xl;
        }
        for(int xr=b[i];xr<=m;++xr){
            if (c[xr]<i) break;
            R[i]=xr;
        }
    }
    // for(auto x:xpos) trace(x,idx[x]);
    // trace(xpos);
    // for(int i=1;i<=n;++i){
    //     trace(reva[i],revb[i],a[i],b[i]);
    // }
    d1(state(0,xpos.size()-1,m,0,INF,INF));
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