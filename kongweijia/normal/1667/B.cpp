#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(char c) {return "'" + string(1,c) + "'";}
string to_string(bool x) {return x ? "true" : "false";}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 500'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

// Range Add & Range Minimum (with the leftist index).
template<class T, T INF, int maxn> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a;
    array<int,maxn*4+5> id;
    void pu(int i) 
    {
        a[i] = max(a[ls],a[rs]); // change here if you want maximum value.
        if(a[i]==a[ls]) id[i] = id[ls]; // change here if you want the rightist index.
        else id[i] = id[rs];
    }
    void build(int i,int l,int r)
    {
        if(l==r) 
        {
            a[i] = INF;
            id[i] = l;
        }
        else
        {
            int mid = (l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql<=l && r<=qr)
        {
            chmax(a[i], x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid = (l+r)>>1;
        upd(ls,l,mid,ql,qr,x);
        upd(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    pair<T,int> ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return pair<T,int>{a[i],id[i]};
        if(qr<l || r<ql) return pair<T,int>{INF,-1};
        int mid = (l+r)>>1;
        auto resl = ask(ls,l,mid,ql,qr);
        auto resr = ask(rs,mid+1,r,ql,qr);
        if(resl.FI>=resr.FI) return resl; // change here if you want the rightist index or if you want maximum value.
        else return resr;
    }
    #undef ls
    #undef rs
};
// Example: type int, range [1,maxn].
Segtree<int,-inf,maxn> seg;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static int a[maxn+5];
        rep(i,1,n) scanf("%d",&a[i]);
        static ll ps[maxn+5];
        rep(i,1,n) ps[i] = ps[i-1] + a[i];
        static vector<ll> vec; vec.clear();
        rep(i,0,n) vec.pb(ps[i]);
        sort(all(vec)); vec.erase(unique(all(vec)),vec.end());
        int N = sz(vec);
        rep(i,0,n) a[i] = lower_bound(all(vec),ps[i]) - vec.begin() + 1;
        static int dp[maxn+5];
        static int best[maxn+5];
        rep(i,1,N) best[i] = -inf;
        seg.build(1,1,N);
        seg.upd(1,1,N,a[0],a[0],0);
        best[a[0]] = 0;
        rep(i,1,n)
        {
            dp[i] = -inf;
            int x = a[i];
            chmax(dp[i], seg.ask(1,1,N,1,x-1).FI + i);
            chmax(dp[i], best[x]);
            if(a[i-1]>a[i]) chmax(dp[i], dp[i-1] - 1);
            seg.upd(1,1,N,x,x,dp[i]-i);
            best[x] = dp[i];
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}