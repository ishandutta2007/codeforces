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
// const int INF=1e16;

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
// inline void read_str(char *str){
//     register char c = 0;
//     register int i = 0;

//     while (c < 33)
//         c = getchar_unlocked();

//     while (c != '\n') {
//         str[i] = c;
//         c = getchar_unlocked();
//         i = i + 1;
//     }

//     str[i] = '\0';
// }

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
int head[MaxN],sub[MaxN],col[MaxN],par[MaxN],child[MaxN],mx[MaxN],ans[MaxN];
vi adj[MaxN];
unordered_map<int,int> cnt[MaxN],color[MaxN];

void dfs(int node,int parent){
    sub[node]=1;
    par[node]=parent;
    child[node]=-1;
    int tmp=0;
    for (auto x:adj[node]){
        if (x==parent) continue;
        dfs(x,node);
        sub[node]+=sub[x];
        if (sub[x]>tmp) tmp=sub[x],child[node]=x;
    }
}

void assign(int node,bool keep){
    if (keep) head[node]=head[par[node]];
    else head[node]=node;
    for (auto x:adj[node]){
        if (x!=par[node]) assign(x,x==child[node]);
    }
}

void solve(int node){
    int top=head[node];
    if (child[node]!=-1) solve(child[node]);
    for (auto x:adj[node]){
        if (x==par[node] || x==child[node]) continue;
        solve(x);
        
        for (auto u: color[head[x]]){
            if (color[top].find(u.F)!=color[top].end()){
                cnt[top][color[top][u.F]]-=u.F;
            }
            else color[top][u.F]=0;
            color[top][u.F]+=u.S;
            if (cnt[top].find(color[top][u.F])==cnt[top].end()){
                cnt[top][color[top][u.F]]=0;
            }
            cnt[top][color[top][u.F]]+=u.F;
            mx[top]=max(mx[top],color[top][u.F]);
        }
    }
    if (cnt[top].find(color[top][col[node]])!=cnt[top].end()){
    cnt[top][color[top][col[node]]]-=col[node];}
    color[top][col[node]]++;
    if (cnt[top].find(color[top][col[node]])==cnt[top].end()){
        cnt[top][color[top][col[node]]]=0;
    }
    cnt[top][color[top][col[node]]]+=col[node];
    
    while (mx[top]<color[top][col[node]]) mx[top]++;
    
    ans[node]=cnt[top][mx[top]];
    
}

signed main(){
    int n,u,v;
    fio;
    cin>>n;
    loop(i,1,n+1){
        cin>>col[i];
        mx[i]=0;
    }
    For(i,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    assign(1,false);
    solve(1);
    
    loop(i,1,n+1) d0(ans[i]);
}