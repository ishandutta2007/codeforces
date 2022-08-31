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


ll merge(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    if (x1==x3 && x2==x4){
        if (y1>y3){
            swap(y1,y3);
            swap(y2,y4);
        }
        if (y2<y3) return -1;
        return (max(y2,y4)-y1)*(x4-x3);
    }
    else if (y1==y3 && y2==y4){
        if (x1>x3){
            swap(x1,x3);
            swap(x2,x4);
        }
        if (x2<x3) return -1;
        return (max(x2,x4)-x1)*(y2-y1);
    }
    return -1;
}
void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    int x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;
    bool val1=1,val2=1;
    int x5,y5,x6,y6;
    cin>>x5>>y5>>x6>>y6;
    ll area=(x2-x1)*(y2-y1);
    x3=max(x3,x1);
    x4=min(x4,x2);
    y3=max(y3,y1);
    y4=min(y4,y2);
    if (x4<=x3 || y4<=y3) val1=0;
    x5=max(x5,x1);
    x6=min(x6,x2);
    y5=max(y5,y1);
    y6=min(y6,y2);
    ll area1=((x4-x3)*(y4-y3));
    ll area2=((x6-x5)*(y6-y5));
    if (x6<=x5 || y6<=y5) val2=0;
    if (!val1 && !val2){
        cout<<"YES"<<endl;
        return;
    }
    if (!val1){
        if (area2<area) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return;
    }
    if (!val2){
        if (area1<area) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return;
    }
    if (area1+area2<area){
        cout<<"YES"<<endl;
        return;
    }
    if (area1>=area || area2>=area){
        cout<<"NO"<<endl;
        return;
    }
    if (merge(x3,y3,x4,y4,x5,y5,x6,y6)==area){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
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