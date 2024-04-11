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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static int a[maxn+5], b[maxn+5];
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) scanf("%d",&b[i]);
        static int cnt[maxn+5];
        rep(i,1,n) cnt[i] = 0;
        rep(i,1,n) cnt[a[i]]++;
        int rt = max_element(cnt+1,cnt+n+1) - cnt;
        static vi e[maxn+5];
        static int deg[maxn+5];
        rep(i,1,n) e[i].clear();
        rep(i,1,n) deg[i] = 0;
        rep(i,1,n) 
        {
            int x = a[i], y = b[i];
            if(x!=rt && y!=rt) e[x].pb(y), deg[y]++;
        }
        static int vis[maxn+5]; 
        rep(i,1,n) vis[i] = 0;
        queue<int> q;
        rep(i,1,n) if(deg[i]==0) q.push(i);
        while(sz(q))
        {
            int now = q.front(); q.pop();
            for(auto v: e[now]) if(--deg[v]==0) q.push(v);
            vis[now] = 1;
        }
        int ok = 1;
        rep(i,1,n) if(vis[i]==0) ok = 0;
        puts(ok ? "AC" : "WA");
    }
    return 0;
}