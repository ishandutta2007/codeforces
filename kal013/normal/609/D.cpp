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
#define sgn(a,b) ((a>b || a>=0 && b<0 || (b<0 && a<0 && abs(a)<abs(b))) && (!(a<=0 && b>0)))
#define loop(i,a,b) for(int i=a;i!=b;i+=tern(sgn(b,a),1,-1))
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

int a[maxn],b[maxn],cost[2][maxn],day[2][maxn];
vpi val[2];

int reachable(int x,int n,int s){
    vi tmp;
    For(i,2){
        for(auto y:val[i]){
            tmp.pb(y.F*cost[i][x]);
        }
    }
    sort(all(tmp));
    int cnt=0;
    int co=0;
    for(auto y:tmp){
        if (co+y>s) break;
        ++cnt;
        co+=y;
    }
    return cnt;
}

void prnt(int x,int n,int s,int k){
    vppi tmp;
    For(i,2){
        for(auto y:val[i]){
            tmp.pb(mp(mp(y.F*cost[i][x],y.S),i));
        }
    }
    sort(all(tmp));
    int cnt=0;
    int co=0;
    for(auto y:tmp){
        if (cnt==k) break;
        ++cnt;
        co+=y.F.F;
        d2(y.F.S+1,day[y.S][x]+1);
    }
}

signed main(){
    int n,m,k,s,c,t,ans=-1;
    fio;
    cin>>n>>m>>k>>s;
    For(i,n) cin>>a[i];
    For(i,n) cin>>b[i];
    For(i,m) cin>>t>>c, val[t-1].pb(mp(c,i));
    
    For(i,n){
        if (i==0 || cost[0][i-1]>a[i]) cost[0][i]=a[i],day[0][i]=i;
        else cost[0][i]=cost[0][i-1],day[0][i]=day[0][i-1];
        if (i==0 || cost[1][i-1]>b[i]) cost[1][i]=b[i],day[1][i]=i;
        else cost[1][i]=cost[1][i-1],day[1][i]=day[1][i-1];
    }
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        
        if (reachable(mid,n,s)>=k){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    if (ans==-1) d1(ans);
    else{
        d1(ans+1);
        prnt(ans,n,s,k);
    }
}