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
const int maxn=1e6+10000;
const int MaxN=1e5+10000;
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
const int N=205;
int dp[N][N][5][4][4];
pii mve[N][N][5][4][4];
int sol(int i,int j,int k,int l,int m){
    if (i<0 || j<0) return -10000;
    if (max(i,j)==0){
        if (l==3 || m==3) return 0;
        return -10000;
    }
    if (k>4 || l>3 || m>3) return -10000;
    
    if(l==3 || m==3) return -10000;
    if (dp[i][j][k][l][m]>-INF) return dp[i][j][k][l][m];
    bool f=false,F=false;
    int tol=(k<4)?25:15;
    int cn=-10000;
    if (i>=tol){
        for(int t=0;t<=tol-2;++t){
            if (t>j) break;
            int u=sol(i-tol,j-t,k+1,l+1,m)+1;
            
            if (u>cn) {
                cn=u;
                mve[i][j][k][l][m]={tol,t};
            }
        }
        int t=tol-1,t2=tol+1;
        
        while (t2<=i && t<=j){
            int u=sol(i-t2,j-t,k+1,l+1,m)+1;
            if (u>cn){
                cn=u;
                mve[i][j][k][l][m]={t2,t};
            }
            t2+=1;
            t+=1;
        }
    }
    if (j>=tol){
        
        for(int t=0;t<=tol-2;++t){
            if (t>i) break;
            int u=sol(i-t,j-tol,k+1,l,m+1)-1;
            if (u>cn) {
                cn=u;
                mve[i][j][k][l][m]={t,tol};
            }
        }
        int t=tol-1,t2=tol+1;
        
        while (t2<=j && t<=i){
            int u=sol(i-t,j-t2,k+1,l,m+1)-1;
            if (u>cn){
                cn=u;
                mve[i][j][k][l][m]={t,t2};
            }
            t2+=1;
            t+=1;
        }
    }
    dp[i][j][k][l][m]=cn;
    // trace(i,j,k,l,m,cn);
    return cn;
}

vector<pii> mves;

bool Find(int i,int j,int k,int l,int m){
    if (sol(i,j,k,l,m)<-50) return false;
    if (k>4 || l>=3 || m>=3 || max(i,j)==0) return true;
    pii X=mve[i][j][k][l][m];
    // trace(i,j,k,l,m,X);
    mves.pb({X});
    // trace(mves);
    if (X.F>X.S) ++l;
    else ++m;
    return Find(i-X.F,j-X.S,k+1,l,m);
    
    // int tol=(k<4)?25:15;
    // bool f=false;
    // if (i>=tol){
    //     for(int t=0;t<=tol-2;++t){
    //         if (t>j) break;
    //         f=Find(i-tol,j-t,k+1,l+1,m);
    //         if (f) {
    //             mves.pb({{tol,t},k});
    //             break;
    //         }
    //     }
    //     int t=tol-1,t2=tol+1;
        
    //     while (t2<=i && t<=j && (!f)){
    //         f=Find(i-t2,j-t,k+1,l+1,m);
    //         if (f){
    //             mves.pb({{t2,t},k});
    //         }
    //         t2+=1;
    //         t+=1;
    //     }
    // }
    // if (j>=tol && (!f)){
        
    //     for(int t=0;t<=tol-2;++t){
    //         if (t>i) break;
    //         f=Find(i-t,j-tol,k+1,l,m+1);
            
    //         if (f) {
    //             mves.pb({{t,tol},k});
    //             break;
    //         }
    //     }
    //     int t=tol-1,t2=tol+1;
        
    //     while (t2<=j && t<=i && (!f)){
    //         f=Find(i-t,j-t2,k+1,l,m+1);
    //         if (f){
    //             mves.pb({{t,t2},k});
    //             break;
    //         }
    //         t2+=1;
    //         t+=1;
    //     }
    // }
    // return f;
}

void solve(){
    int a,b;
    read(a);read(b);
    bool f=sol(a,b,0,0,0)>-50;
    // trace(sol(a,b,0,0,0));
    if (!f){
        d1("Impossible");
        return;
    }
    
    mves.clear();
    Find(a,b,0,0,0);
    int a1=0,b1=0;
    for(auto x:mves){
        if (x.F>x.S) ++a1;
        else ++b1;
    }
    cout<<a1<<":"<<b1<<endl;
    for(auto x:mves){
        cout<<x.F<<":"<<x.S<<" ";
    }
    cout<<endl;

}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    fio;
    For(i,N) For(j,N) For(k,5) For(l,4) For(m,4) dp[i][j][k][l][m]=-INF;
    int t=1;
    read(t);
    while(t--) {
        solve();
    }
}