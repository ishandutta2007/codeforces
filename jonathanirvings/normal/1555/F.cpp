//start of jonathanirvings' template v3.0.3 (BETA)
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
 
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
 
#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif
 
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
 
inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}
 
inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}
 
inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}
 
inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
 
inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
 
inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}
 
//end of jonathanirvings' template v3.0.3 (BETA)
 
struct BIT
{
  vi arr;
  void sz(int x) 
  {
    arr.resize(x+1);
    REP(i,x+1) arr[i] = 0;
  }
  void update(int x,int y)
  {
    int m = SIZE(arr);
    while (x < m)
    {
      arr[x] += y;
      x += (x & -x);
    }
  }
  int query(int x)
  {
    int ret = 0;
    while (x > 0)
    {
      ret += arr[x];
      x -= (x & -x);
    }
    return ret;
  }
};
 
int n,q;
int root[300005];
int a,b,c;
vii adj[300005];
bool risan[500005];
vector<pair<pii,pii>> pending;
pii waktu[300005];
int h[300005];
int parent[20][300005];
int xo[300005];
static int t = 1;
BIT bit;
 
int find_root(int x)
{
  return root[x] = (x == root[x] ? x : find_root(root[x]));
}
 
void dfs(int u)
{
  waktu[u].fi = waktu[u].se = t++;
  for (pii edge : adj[u])
  {
    int v = edge.fi;
    int w = edge.se;
    if (v == parent[0][u]) continue;
    
    parent[0][v] = u;
    xo[v] = xo[u] ^ w;
    h[v] = h[u] + 1;
    dfs(v);
    waktu[u].se = waktu[v].se;
  }
}
 
int lca(int u,int v)
{
  if (h[u] < h[v]) swap(u,v);
  FORD(i,19,0) if (h[parent[i][u]] >= h[v])
  {
    u = parent[i][u];
  }
  if (u == v) return u;
  FORD(i,19,0) if (parent[i][u] != parent[i][v])
  {
    u = parent[i][u];
    v = parent[i][v];
  }
  return parent[0][u];
}
 
int main()
{
  scanf("%d %d",&n,&q);
  REP(i,n) root[i] = i;
  REP(i,q)
  {
    scanf("%d %d %d",&a,&b,&c);
    --a; --b;
    // debug("input %d %d %d\n",a,b,c);
    if (find_root(a) != find_root(b))
    {
      risan[i] = 1;
      adj[a].pb(mp(b,c));
      adj[b].pb(mp(a,c));
      root[find_root(a)] = find_root(b);
    } else
    {
      pending.pb(mp(mp(a,b),mp(c,i)));
    }
  }
  FOR(i,1,n) if (find_root(i) != find_root(0))
  {
    adj[i].pb(mp(0,0));
    adj[0].pb(mp(i,0));
    root[find_root(i)] = find_root(0);
  }
  parent[0][0] = xo[0] = h[0] = 0;
  dfs(0);
  FORN(i,1,19) REP(j,n) parent[i][j] = parent[i-1][parent[i-1][j]];
  bit.sz(n+5);
 
  for (auto p : pending)
  {
    int u = p.fi.fi;
    int v = p.fi.se;
    int w = p.se.fi;
    int ix = p.se.se;
 
    int z = lca(u,v);
 
    if (h[u] < h[v]) swap(u,v);
    int ada = bit.query(waktu[u].fi) - bit.query(waktu[z].fi);
    ada += bit.query(waktu[v].fi) - bit.query(waktu[z].fi);
 
    // debug("query=(%d %d %d %d) %d %d\n",u,v,w,ix,ada,(xo[u] ^ xo[v] ^ w));
    if (ada == 0 && (xo[u] ^ xo[v] ^ w) == 1)
    {
      risan[ix] = 1;
      while (u != z)
      {
        bit.update(waktu[u].fi,1);
        bit.update(waktu[u].se+1,-1);  
        u = parent[0][u];
      }
      while (v != z)
      {
        bit.update(waktu[v].fi,1);
        bit.update(waktu[v].se+1,-1);
        v = parent[0][v];
      }
      // bit.update(waktu[u].fi,1);
      // bit.update(waktu[u].se+1,-1);
      // bit.update(waktu[v].fi,1);
      // bit.update(waktu[v].se+1,-1);
    }
  }
 
  REP(i,q) puts(risan[i] ? "YES" : "NO");
  return 0;
}