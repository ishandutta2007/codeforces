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
// #define cross(i,a,b) ((tern(b>a,1,-1))*(i))>=((tern(b>a,1,-1))*(b))
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
#endif
inline int fast_expo(int base,int power,int modulo=mod){
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        cnt>>=1;
    }
    int tmp=ans;
    return tmp;
}

// inline int fib(int n,int a=1,int b=1,int c=1,int d=0,int acca=0,int accb=1,int m=mod){
//     if (n==0) return acca;

//     if (n&1) return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,((a*acca)%m+(b*accb)%m)%m,((c*acca)%m+(d*accb)%m)%m,m);
//     else return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,acca,accb,m);
// }

// struct base{
//     double x , y;
//     base(){
//         x = 0;
//         y = 0;
//     }
//     base(double a){
//         x = a;
//         y = 0;
//     }
//     base(double a , double b){
//         x = a;
//         y = b;
//     }
//     base conj(){
//         return base(x , -y);
//     }
//     base operator = (const base &o){
//         x = o.x;
//         y = o.y;
//         return *this;
//     }
//     base operator + (const base &o) const {
//         return base(x + o.x , y + o.y);
//     }
//     base operator - (const base &o) const {
//         return base(x - o.x , y - o.y);
//     }
//     base operator * (const base &o) const {
//         return base(x * o.x - y * o.y , y * o.x + x * o.y);
//     }
//     base operator * (const double num) const {
//         return base(x * num , y * num);
//     }
//     base operator / (const double num) const {
//         return base(x / num , y / num);
//     }

// };



const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

/*/-----------------------------Code begins----------------------------------/*/

int arr[maxn];
int p[maxn],s[maxn];
int pref[maxn];

HullDynamic a;
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    
    
    int n,ans=0,tot=0;
    cin>>n;
    For(i,n){cin>>arr[i];tot+=(i+1)*arr[i];}
    
    // d1(tot);
    pref[0]=0;
    For(i,n) pref[i+1]=arr[i]+pref[i];
    p[0]=0;
    For(i,n){
        p[i+1]=pref[n]-pref[i]+p[i];
        // d0(p[i+1]);
    }
    // d1("");
    s[n+1]=0;
    for(int i=n;i>0;i--){
        s[i]=s[i+1]+i*arr[i-1];
        // d0(s[i]);
    }
    // d1("");
    int bst=0;
    For(i,n){
        bst=max(bst,max(-s[i+1],-p[i+1]));
    }
    // trace(bst);
    for(int i=n-1;i>0;i--){
        a.insert_line(pref[n]-pref[i],-s[i+1]);
        int res=a.eval(i);
        // trace(i,res,pref[n]-pref[i],-s[i+1],p[i],res-p[i]);
        bst=max(bst,res-p[i]);
        
    }
    // d2(bst,tot+bst);
    d1(tot+bst);
    
    
    // int n,s=0,ans=0,best=0;
    // cin>>n;
    // For(i,n) {
    //     line={-i-1,s};
    //     cht[0].add(line);
    //     cin>>arr[i+1];
    //     ans+=(arr[i+1]*(i+1));
    //     int xx=-cht[0].min(arr[i+1])-(i+1)*(arr[i+1])+s;
    //     best=max(best,xx);
    //     // d4(i,cht[0].min(arr[i+1]),s,xx);
    //     s+=arr[i+1];
    // }
    // s=0;
    // for(int i=n;i>0;i--){
    //     line={i,-s};
    //     // d3("line",i,-s);
    //     cht[1].add(line);
    //     int xx=-cht[1].min(-arr[i])-s-i*arr[i];
    //     // d4(i,xx,cht[1].min(-arr[i]),arr[i]);
    //     s+=arr[i];
    //     best=max(best,xx);
        
    // }
    
    // d1(ans+best);
    
    
    
}