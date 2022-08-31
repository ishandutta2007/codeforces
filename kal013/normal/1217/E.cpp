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


struct Node{
	int a=INF,b=INF;
	Node(){};
	Node(int a): a(a),b(INF){};
	Node(int a,int b):a(a),b(b) {};
	Node operator +(const Node& p) const{
		return Node(min(a,p.a),min(min(b,p.b),max(a,p.a)));
	}
	Node operator +=(const Node& p){
		b=min(min(b,p.b),max(a,p.a));
		a=min(a,p.a);
		return *this;
	}
	Node operator = (const Node& p){
		this->a=p.a;this->b=p.b;
		return *this;
	}
};
int a[maxn];
int A[maxn][10];
Node seg[maxn][10];
#define M ((s+e)/2)
void build(int node,int s,int e,int tp){
	if (s==e){
		seg[node][tp]=Node(A[s][tp]);
	}
	else{
		build(2*node,s,M,tp);
		build(2*node+1,M+1,e,tp);
		seg[node][tp]=seg[2*node][tp]+seg[2*node+1][tp];
	}
}
void update(int node,int s,int e,int tp,int l){
	if (s==e){
		seg[node][tp]=Node(A[s][tp]);
		return;
	}
	if (l<=M) update(2*node,s,M,tp,l);
	else update(2*node+1,M+1,e,tp,l);
	seg[node][tp]=seg[2*node][tp]+seg[2*node+1][tp];
}
void assgn(int l){
	int z=a[l];
	For(i,10){
		int x=z%10;
		if (x>0){
			A[l][i]=a[l];
		}
		else{
			A[l][i]=INF;
		}
		z/=10;
	}
}
void update(int s,int e,int l){
	assgn(l);
	For(i,10) update(1,s,e,i,l);
}

Node query(int node,int s,int e,int l,int r,int tp){
	if (l<=s && e<=r) return seg[node][tp];
	if (M<l) return query(2*node+1,M+1,e,l,r,tp);
	else if (M+1>r) return query(2*node,s,M,l,r,tp);
	return query(2*node,s,M,l,r,tp)+query(2*node+1,M+1,e,l,r,tp);
}
int query(int s,int e,int l,int r){
	int res=INF;
	For(i,10) {
		Node j=query(1,s,e,l,r,i);
		// trace(i,j.a,j.b,l,r);
		res=min(res,j.a+j.b);
	}
	return res;
}
void solve(){
	int n,m,t;
	cin>>n>>m;
	For(i,n) cin>>a[i];
	For(i,n) assgn(i);
	For(i,10) build(1,0,n-1,i);
	For(i,m){
		cin>>t;
		if (t==1){
			int id,x;
			cin>>id>>x;
			--id;
			a[id]=x;
			update(0,n-1,id);
		}
		else{
			int l,r;
			cin>>l>>r;
			--l;--r;
			int q=query(0,n-1,l,r);
			if (q>=INF) q=-1;
			d1(q);
		}
	}
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