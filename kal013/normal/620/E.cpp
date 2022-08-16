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

const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
// const int INF=1e16;
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

int col[maxn];
vi adj[maxn];
int st[maxn],ed[maxn],lzy[5*maxn];

vi euler;

int seg[5*maxn],ans;
int pow2[60];
#define M (s+e)/2

void merge(int a,int b,int c){
    seg[c]=seg[a]|seg[b];
}
void build(int node,int s,int e){
    lzy[node]=-1;
    if (s==e){
        seg[node]=(pow2[col[euler[s]]-1]);
        return;
    }
    build(2*node,s,M);
    build(2*node+1,M+1,e);
    merge(2*node,2*node+1,node);
}

void rmv(int node,int s,int e){
    if (lzy[node]==-1) return;
    seg[node]=(pow2[(lzy[node]-1)]);
    if (s!=e) {
        lzy[2*node]=lzy[node];
        lzy[2*node+1]=lzy[node];
    }
    lzy[node]=-1;
}


void upd(int node,int s,int e,int l,int r,int val){
    rmv(node,s,e);
    // d6(node,s,e,l,r,val);
    if (l>e || r<s) return;
    // d6(node,s,e,l,r,val);
    if (s>=l && e<=r) {
        
        lzy[node]=val;
        rmv(node,s,e);
        // d6(node,s,e,l,r,seg[node].soz);
        return;
    }
    upd(2*node,s,M,l,r,val);
    upd(2*node+1,M+1,e,l,r,val);
    merge(2*node,2*node+1,node);
}

void quer(int node,int s,int e,int l,int r){
    rmv(node,s,e);
    if (l>e || r<s) return;
    if (s>=l && e<=r){
        ans|=seg[node];
        return;
    }
    quer(2*node,s,M,l,r);
    quer(2*node+1,M+1,e,l,r);
    
}


void df(int no,int p){
    euler.pb(no);
    st[no]=euler.size()-1;
    // d3(no,p,st[no]);
    for (auto x:adj[no]){
        if (x!=p){
            df(x,no);
        }
    }
    
    ed[no]=euler.size()-1;
    // d3(no,p,ed[no]);
}

signed main(){
    int n,m,u,v,t,tt;
    fio;
    pow2[0]=1;
    For(i,59){
        pow2[i+1]=pow2[i]*2;
    }
    cin>>n>>m;
    For(i,n){
        cin>>col[i];
    }

    For(i,n-1){
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);adj[v].pb(u);
    }
    // For(i,n){
    //     d0(i);d0(":");
    //     for(auto x:adj[i]){
    //         d0(x);
    //     }
    //     d1("");
    // }
    df(0,0);
    
    build(1,0,euler.size()-1);
    
    For(i,m){
        cin>>t;
        if (t==1){
            cin>>u>>v;
            u--;
            upd(1,0,euler.size()-1,st[u],ed[u],v);
        }
        else{
            cin>>u;
            u--;
            ans=0;
            quer(1,0,euler.size()-1,st[u],ed[u]);
            tt=0;
            
            For(i,60){ 
                if (ans&(pow2[i])) tt++;
            }
            d1(tt);
        }
    }
}