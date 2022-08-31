/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
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
const int MaxN=2e5+100;
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

int dp[MaxN][2];
int wt[MaxN];


int seg[maxn];
int seg2[maxn];
#define M ((s+e)/2)
void build(int node,int s,int e){
    seg[node]=INF;
    seg2[node]=INF;
    if (s!=e){
        build(2*node,s,M);
        build(2*node+1,M+1,e);
    }
}

void update(int node,int s,int e,int l,int v){
    if (e<l || s>l) return;
    if (s==e){
        seg[node]=v;
        return;
    }
    update(2*node,s,M,l,v);
    update(2*node+1,M+1,e,l,v);
    seg[node]=min(seg[2*node],seg[2*node+1]);
}

void update2(int node,int s,int e,int l,int v){
    if (e<l || s>l) return;
    if (s==e){
        seg2[node]=v;
        return;
    }
    update2(2*node,s,M,l,v);
    update2(2*node+1,M+1,e,l,v);
    seg2[node]=min(seg2[2*node],seg2[2*node+1]);
}
int query(int node,int s,int e,int l,int r){
    if (e<l || s>r) return INF;
    if (l<=s && e<=r) return seg[node];
    return min(query(2*node,s,M,l,r),query(2*node+1,M+1,e,l,r));
}

int query2(int node,int s,int e,int l,int r){
    if (e<l || s>r) return INF;
    if (l<=s && e<=r) return seg2[node];
    return min(query2(2*node,s,M,l,r),query2(2*node+1,M+1,e,l,r));
}

void solve(){
    dp[0][0]=0;
    dp[0][1]=INF;
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    Rep(i,n){
        wt[i]=((int)(s[i-1]-'0'))*k;
    }
    build(1,0,n);
    update2(1,0,n,0,0);
    Rep(i,n){
        dp[i][0]=INF;
        dp[i][1]=INF;
        dp[i][0]=query(1,0,n,max(0ll,i-k),i);
        if (wt[i]==0) dp[i][1]=i+min(dp[i-1][0],dp[i-1][1]);
        else{
            dp[i][1]=i+query2(1,0,n,max(0ll,i-k-1),i-1);
            
            
            update(1,0,n,i,dp[i][1]);
        }
        
        update2(1,0,n,i,min(dp[i][0],dp[i][1]));
    }
    cout<<min(dp[n][1],dp[n][0])<<endl;
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