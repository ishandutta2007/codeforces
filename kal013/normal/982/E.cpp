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
const int INF=1e18;
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


struct ex_gcd{
    ll x,y,d;
    ex_gcd(ll x,ll y,ll d): x(x),y(y),d(d){}
};
ex_gcd gcd(ll a,ll b){
    if (b==0){
        return ex_gcd(1,0,a);
    }
    ex_gcd c=gcd(b,a%b);
    
    return ex_gcd(c.y,c.x-(a/b)*c.y,c.d);
}


pair<ll,ll> CRT(vector<ll>& rem,vector<ll>& mods){
    ll lcm=mods[0];
    
    ll ans=rem[0];
    
    for(int i=1;i<mods.size();++i){
        ex_gcd curr=gcd(lcm,mods[i]);
        // a1+n1*k1= a2+n2*k2
        // n1*x+n2*y= d
        // n1*x*(a2-a1)/d +n2*y*(a2-a1)/d= a2-a1
        // n1*x'+a1= n2*-y'+a2;
        //  n1 * ((a2-a1)/d) % (n2/d)
        if ((ans-rem[i])%curr.d!=0) return {-1,-1};
        ans=ans+(((curr.x*(rem[i]-ans)/curr.d))%(mods[i]/curr.d))*lcm;
        lcm=(lcm*(mods[i]/curr.d));
        ans%=lcm;
        if (ans<0) ans+=lcm;
    }
    return {ans,lcm};
}
int lcm(int a,int b){
    return (a/__gcd(a,b))*b;
}
// friend istream& operator >> (istream& is, const &int x){
//     ll &y=x;
//     return is>>y;
// }
int reach(int x,int y,int n,int m,int rx,int ry,int vx,int vy){
    // (x+t*vx)%(2*n)=rx
        // (y+t*vy)%(2*m)=ry 
        // rx-x=t*vx+2*n*k1 
        // ry-y=t*vy+2m*k2
        // (rx-x)*vy- (ry-y)*vx = (2*n*k1)*vy-2*m*k2*vx
        // d= (2*n)*(k1*vy)+(2*m)*(-k2*vx)
        // if (vy<0){
        //     y=2*m-y;
        // }
        // if (vx<0){
        //     x=2*n-x;
        // }
    int d= (rx-x)*vy-(ry-y)*vx;
    // O(1e9)
    ex_gcd curr=gcd(2*n,2*m);
    if ((d%curr.d)!=0){
        return -1;
    }
    int M=(2*m)/(curr.d);
    int k1=(curr.x%M)*vy*((d/curr.d)%M);
    int j=k1%(M);
    int t=(rx-x-2*n*j)*vx;
    int l=lcm(2*n,2*m);
    // trace(t);
    if (t<0){
        // trace(t,l);
        int z=(abs(t)+l-1)/l;
        // trace(z);
        t+=z*l;
    }
    if (t>=0){
        t%=l;
    }
    // trace(t);
    return t;
    // if (rx==n && ry==m){
        
        
        
        
    // }
    // else if (rx==0 && ry==m){
        
    // }
    // else if (ry==0 && rx==n){
        
    // }
    // else{
        
    // }
    
}



void solve(){
    ll N,M,Vx,Vy,X,Y;
    cin>>N>>M>>X>>Y>>Vx>>Vy;
    int n,m,vx,vy,x,y;
    // cin>>n>>m>>x>>y>>vx>>vy;
    n=N;m=M;x=X;y=Y;vx=Vx;vy=Vy;
    if (vy==0){
        if (y==0 || y==m){
            if (vx==1){
                d2((ll)n,(ll)y);
            }
            else{
                d2(0,(ll)y);
            }
        }
        else{
            d1(-1);
        }
        return;
    }
    if (vx==0){
        if (x==0 || x==n){
            if (vy==1){
                d2((ll)x,(ll)m);
            }
            else{
                d2((ll)x,0);
            }
        }
        else{
            d1(-1);
        }
        return;
    }
    
    pair<ll,ll> ans={-1,-1};
    int t=INF;
    ll t0=reach(x,y,n,m,n,m,vx,vy);
    // trace(t0);
    // trace(t0,n,m);
    if (t0!=-1){
        t=t0;
        ans={n,m};
    }
    
    t0=reach(x,y,n,m,n,0,vx,vy);
    // trace(t0,n,0);
    // trace(t0);
    if (t0!=-1 && t0<t){
        t=t0;
        ans={n,0};
    }
    
    t0=reach(x,y,n,m,0,m,vx,vy);
    // trace(t0,0,m);
    // trace(t0);
    if (t0!=-1 && t0<t){
        t=t0;
        ans={0,m};
    }
    t0=reach(x,y,n,m,0,0,vx,vy);
    // trace(t0,0,0);
    // trace(t0);
    if (t0!=-1 && t0<t){
        t=t0;
        ans={0,0};
    }
    if (ans.F==-1){
        d1(-1);
    }
    else{
        d2(ans.F,ans.S);
    }
    // if (vx==vy){
    
    //     int t0,t1,t2,t3;
        
    // }
    // else{
        
    // }
    // cin>>n>>k;
    // int l=1;
    // for(int i=0;i<n;++i){
    //     cin>>c;
    //     l=lcm(l,__gcd(k,c));
    // }
    // if (k==l){
    //     d1("Yes");
    // }
    // else{
    //     d1("No");
    // }
    

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