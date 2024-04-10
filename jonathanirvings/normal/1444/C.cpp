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

int n,m,k,u,v;
int c[1000005];
map<pii,vii> edges;
vi adj[1000005];
int ada[1000005];
pii conn[1000005];
bool dah[1000005];
bool cannot[1000005];

vvi adj2;
vi dah2;
bool ok2 = 1;

void dfs(int u)
{
  for (int v : adj[u]) if (c[u] == c[v])
  {
    if (dah[v] && conn[v].se == conn[u].se)
    {
      cannot[c[u]] = 1;
    }
    if (!dah[v])
    {
      dah[v] = 1;
      conn[v] = mp(conn[u].fi,1-conn[u].se);
      dfs(v);
    }
  }
}

void dfs2(int u)
{
  // debug("COLOUR %d %d\n", u, dah2[u]);
  for (int v : adj2[u])
  {
    if (dah2[v] == dah2[u])
    {
      ok2 = 0;
    }
    if (dah2[v] == 0)
    {
      dah2[v] = 3 - dah2[u];
      dfs2(v);
    }
  }
}

int main()
{
  scanf("%d %d %d",&n,&m,&k);
  REP(i,n)
  {
    scanf("%d",&c[i]);
    --c[i];
  }
  REP(i,m)
  {
    scanf("%d %d",&u,&v);
    --u; --v;
    if (c[u] > c[v]) swap(u,v);
    adj[u].pb(v);
    adj[v].pb(u);
    if (c[u] != c[v]) edges[mp(c[u],c[v])].pb(mp(u,v));
  }
  REP(i,n) if (!dah[i])
  {
    dah[i] = 1;
    conn[i] = mp(ada[c[i]]++, 0);
    dfs(i);
  }
  LL risan = 0;
  REP(i,k) if (!cannot[i]) ++risan;
  risan = (risan * (risan - 1)) / 2;
  for (auto cek : edges)
  {
    int u = cek.fi.fi;
    int v = cek.fi.se;
    if (cannot[u] || cannot[v]) continue;

    map<pair<int,pii>,int> ix;
    for (auto x : cek.se)
    {
      u = x.fi;
      v = x.se;
      if (ix.count(mp(c[u],conn[u])) == 0) ix[mp(c[u],conn[u])] = SIZE(ix);
      if (ix.count(mp(c[v],conn[v])) == 0) ix[mp(c[v],conn[v])] = SIZE(ix);
    }
    int node = SIZE(ix);
    adj2 = vvi(node, vi());
    dah2 = vi(node, 0);
    ok2 = 1;
    for (auto x : cek.se)
    {
      u = x.fi;
      v = x.se;
      int uu = ix[mp(c[u],conn[u])];
      int vv = ix[mp(c[v],conn[v])];
      if (uu != vv)
      {
        adj2[uu].pb(vv);
        adj2[vv].pb(uu);
      }
      // debug("%d %d\n",uu,vv);
    }
    for (auto x : ix)
    {
      auto key = x.fi;
      if (ix.count(mp(key.fi,mp(key.se.fi,1-key.se.se))))
      {
        adj2[x.se].pb(ix[mp(key.fi,mp(key.se.fi,1-key.se.se))]);
        // debug("ADD %d %d\n",x.se,ix[mp(key.fi,mp(key.se.fi,1-key.se.se))]);
      }
    }
    REP(i,node) if (dah2[i] == 0) 
    {
      dah2[i] = 1;
      dfs2(i);
    }
    if (!ok2) --risan;
    // debug("%d %d %d\n",cek.fi.fi,cek.fi.se,ok2);
  }
  printf("%lld\n",risan);
  return 0;
}