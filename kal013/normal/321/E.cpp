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
#define For(i,n) for(int i=0;i<n;i++)
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
// #define codechef
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
template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }
 
    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};
#endif
#ifdef codechef
// inline void read(int &x) {
//     register int c = getchar_unlocked();
//     x = 0;
//     int neg = 0;
 
//     for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
 
//     if(c=='-') {
//     	neg = 1;
//     	c = getchar_unlocked();
//     }
 
//     for(; c>47 && c<58 ; c = getchar_unlocked()) {
//     	x = (x<<1) + (x<<3) + c - 48;
//     }
 
//     if(neg)
//     	x = -x;
// }
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
// inline void read(auto &x) {x=getchar()-'0';}
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
 
 
 
struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double a){
        x = a;
        y = 0;
    }
    base(double a , double b){
        x = a;
        y = b;
    }
    base conj(){
        return base(x , -y);
    }
    base operator = (const base &o){
        x = o.x;
        y = o.y;
        return *this;
    }
    base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    base operator * (const base &o) const {
        return base(x * o.x - y * o.y , y * o.x + x * o.y);
    }
    base operator * (const double num) const {
        return base(x * num , y * num);
    }
    base operator / (const double num) const {
        return base(x / num , y / num);
    }
 
};
 
 
 
 
/*/-----------------------------Code begins----------------------------------/*/
const int N=4050;
 
int u[N][N],c[N][N],p[N][N],dp[N][N];
int ml[N],mr[N],P[N],opt[N];
vi process; 

int n,k;
inline int C(int i,int j){
    
    if (i>j) return 0;
    int r=u[j][j];
    if (i!=0) r-=u[i-1][j]+u[j][i-1]-u[i-1][i-1];
    return r/2;
}

inline void pre(int l,int r,int par){
    if (l>r) return;
    int M=(l+r)/2;
    P[M]=par;
    process.pb(M);
    pre(l,M-1,M);
    pre(M+1,r,M);
}
inline void d(int i,int n){
    For(j,n) {ml[j]=0,mr[j]=n-1;}
    for(auto x:process){
        pii ans={INF,-1};
        if (P[x]!=-1){
            if (P[x]>x){
                ml[x]=max(ml[P[x]],ml[x]);
                mr[x]=min(mr[x],opt[P[x]]);
            }
            else{
                ml[x]=max(ml[x],opt[P[x]]);
                mr[x]=min(mr[x],mr[P[x]]);
            }
        }
        for(int j=ml[x];j<=min(mr[x],x-1);++j){
            ans=min(ans,{dp[i-1][j]+C(j+1,x),j});
        }
        dp[i][x]=ans.F;
        opt[x]=ans.S;
    }
    
}
 
inline void d(int i,int l,int r,int ml,int mr){
    int M=(l+r)/2;
    if (l>r) return;
    pii ans={INF,-1};
    for(int j=ml;j<=min(mr,M);j++){
        ans=min(ans,{dp[i-1][j]+C(j+1,M),j});
    }
    dp[i][M]=ans.F;
    d(i,l,M-1,ml,ans.S);
    d(i,M+1,r,ans.S,mr);
}
 
 
 
void solve(){
    // int n,k;
    scanf("%d%d" , &n , &k);
    
    getchar();
    // For(i,n) For(j,n) {u[i][j]=getchar()-'0';getchar();}
    
    For(i,n){
        For(j,n){
            u[i][j]=getchar()-'0';
            if (i!=0) u[i][j]+=u[i-1][j];
            if (j!=0) u[i][j]+=u[i][j-1];
            if (i!=0 && j!=0) u[i][j]-=u[i-1][j-1];
            getchar();
        }
    }
    pre(0,n-1,-1);
    For(i,n){
        dp[1][i]=C(0,i);
    }
    for(int i=2;i<=k;i++){
        // d(i,0,n-1,0,n-1);
        d(i,n);
    }
    
    printf("%d\n",dp[k][n-1]);
    
    
    
    
    
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    // fio;
    
    int t=1;
    // read(t);
    while(t--) {
        solve();
    }
}