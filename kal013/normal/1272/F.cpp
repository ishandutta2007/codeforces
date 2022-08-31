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
const int N=203;
string s,t;
bool vis[N][N][N*2];
int dp[N][N][N*2];
char opt[N][N][N*2];

int state(int i,int j,int ex){
    // trace(i,j,ex);
    assert(ex>=0);
    if (ex<0) return INF;
    if (i==0 && j==0 && ex==0) return 0;
    if (vis[i][j][ex]) return dp[i][j][ex];
    
    vis[i][j][ex]=1;
    dp[i][j][ex]=INF;
    int &cu=dp[i][j][ex];
    if (i==0 && j==0){
        opt[i][j][ex]='(';
        cu=state(i,j,ex-1)+1;
        return cu;
    }
    if (i==0){
        if (t[j-1]=='(' && ex==0){
            opt[i][j][ex]=')';
            cu=state(i,j,ex+1)+1;
            return dp[i][j][ex];
        }
        int ze=ex+((t[j-1]=='(')?-1:1);
        
        cu=state(i,j-1,ze)+1;
        opt[i][j][ex]=t[j-1];
        return dp[i][j][ex];
    }
    if (j==0){
        if (s[i-1]=='(' && ex==0){
            opt[i][j][ex]=')';
            cu=state(i,j,ex+1)+1;
            return dp[i][j][ex];
        }
        int ze=ex+((s[i-1]=='(')?-1:1);
        
        dp[i][j][ex]=state(i-1,j,ze)+1;
        opt[i][j][ex]=s[i-1];
        return dp[i][j][ex];
    }
    int t1=INF,t2=INF;
    if (ex>0){
        t1=min(t1,1+state(i-(s[i-1]=='(' ? 1:0), j- (t[j-1]=='('?1:0),ex-1));
    }
    if (ex<s.size()+t.size()){
        t2=min(t2,1+state(i-((s[i-1]==')') ? 1:0), j- (t[j-1]==')'?1:0),ex+1));
    }
    if (t1<=t2){
        opt[i][j][ex]='(';
    }
    else opt[i][j][ex]=')';
    dp[i][j][ex]=min(t1,t2);
    return dp[i][j][ex];
}

void solve(){
    cin>>s>>t;
    
    state(s.size(),t.size(),0);
    
    int n=s.size(),m=t.size();
    int ex=0;
    string ans="";
    while(n>0 || m>0 || ex>0){
        
        ans+=opt[n][m][ex];
        char z=opt[n][m][ex];
        if (n>0 && s[n-1]==z) --n;
        if (m>0 && t[m-1]==z) --m;
        if (z=='(') --ex;
        else ++ex;
        assert(ex>=0);
    }
    reverse(all(ans));
    cout<<ans<<endl;
    
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