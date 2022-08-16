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
const int MaxN=1e5+100;
const int mod=998244353;
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


inline int mul(int a,int b){
    return (a*1ll*b)%mod;
}
inline int add(int a,int b){
    a+=b;
    return (a>=mod)?a-mod:a;
}
inline int sub(int a,int b){
    a-=b;
    return (a<0)?a+mod:a;
}
int P[maxn];
int prmul[maxn];
int inmul[maxn];
int f[maxn];

inline int range_prod(int l,int r){
    return mul(prmul[r],inmul[l-1]);
}
inline int inv_range_prod(int l,int r){
    return mul(inmul[r],prmul[l-1]);
}

bool on[maxn];
ll val[maxn];

ll calc(ll l,ll r){
    --r;
    // trace(l,r);
    ll prd=range_prod(l,r);
    prd=mul(prd,f[r+1]);
    
    ll val=sub(f[l],prd);
    // trace(f[l],f[r],val);
    // trace(val);
    val=mul(val,inv_range_prod(l,r));
    // trace(l,r,val);
    return val;
}

void solve(){
    int n,q;
    cin>>n>>q;
    ll inv_10=inv(100);
    prmul[0]=1;
    inmul[0]=1;
    
    Rep(i,n){
        on[i]=0;val[i]=0;
        cin>>P[i];
        P[i]=mul(P[i],inv_10);
        prmul[i]=mul(prmul[i-1],P[i]);
        inmul[i]=inv(prmul[i]);
    }
    P[n+1]=1;
    prmul[n+1]=prmul[n];
    inmul[n+1]=inmul[n];
    f[n+1]=1;
    f[n+2]=0;
    // f[n]=1;
    on[1]=1;
    for(int i=n;i>=1;--i){
        f[i]=add(1,mul(P[i],f[i+1]));
    }
    
    set<int> check;
    check.insert(1);
    check.insert(n+1);
    ll E=mul(f[1],inv_range_prod(1,n));
    E=calc(1,n+1);
    val[1]=E;
    // trace(E);
    Rep(x,q){
        ll y;
        cin>>y;
        if (on[y]){
            on[y]^=1;
            auto it=check.find(y);
            E=sub(E,val[y]);
            val[y]=0;
            --it;
            ll x=*(it);
            ++it;++it;
            ll z=*(it);
            E=sub(E,val[x]);
            
            val[x]=calc(x,z);
            E=add(E,val[x]);
            check.erase(y);
        }
        else{
            on[y]^=1;
            check.insert(y);
            auto it=check.find(y);
            --it;
            ll x=*(it);
            ++it;++it;
            ll z=*(it);
            E=sub(E,val[x]);
            val[x]=calc(x,y);
            val[y]=calc(y,z);
            E=add(E,val[x]);
            E=add(E,val[y]);
            
            
        }
        d1(E);
        
    }
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