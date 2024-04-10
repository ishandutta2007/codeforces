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

class Centroid {
public:
  int n;
  const vector<vector<int>> *adj;
  vector<int> parent;
  vector<bool> done;
  vector<int> sz;

  void init(int _n, vector<vector<int> > &_adj) {
    n = _n;
    adj = &_adj;
    parent.resize(n);
    done.resize(n);
    sz.resize(n);
    REP(i,n) done[i] = 0;
  }

  vector<int> centroid()
  {
    centroid(0, -1);
    return parent;
  }

private:
  void precompute(int u, int pt) {
    sz[u] = 1;
    REP(i,SIZE((*adj)[u])) if (!done[(*adj)[u][i]] && (*adj)[u][i] != pt)
    {
      precompute((*adj)[u][i], u);
      sz[u] += sz[(*adj)[u][i]];
    }
  }

  int findCenter(int u, int pt, int n)
  {
    REP(i,SIZE((*adj)[u])) if(!done[(*adj)[u][i]] && (*adj)[u][i] != pt)
    {
      if (sz[(*adj)[u][i]] > n/2)
        return findCenter((*adj)[u][i], u, n);
    }
    return u;
  }

  void centroid(int u, int pt)
  {
    precompute(u, -1);
    int center = findCenter(u, pt, sz[u]);
    done[center] = 1;
    parent[center] = pt;
    REP(i,SIZE((*adj)[center])) if (!done[(*adj)[center][i]] && (*adj)[center][i] != pt)
      centroid((*adj)[center][i], center);
  }
};

class LCA {
public:
  int N, K;
  const vector<vector<int> > *adj;
  vector<int> height;
  vector<vector<int> > parent;
  vector<int> count;

  void init(int _N, vector<vector<int> > &_adj)
  {
    N = _N;
    K = 0;
    while ((1 << K) < N) ++K;
    height.resize(N);
    count.resize(N);
    parent.resize(N);
    REP(i,N) parent[i].resize(K);
    adj = &_adj;
    parent[0][0] = 0;
    height[0] = 0;
    dfs(0);
    fillParent();
  }

  int findLCA(int x,int y)
  {
    if (height[x] < height[y]) swap(x,y);
    FORD(i,K-1,0)
    {
      if (height[parent[x][i]] >= height[y]) x = parent[x][i];
    }
    if (x == y) return x;
    FORD(i,K-1,0)
    {
      if (parent[x][i] != parent[y][i])
      {
        x = parent[x][i];
        y = parent[y][i];
      }
    }
    return parent[x][0];
  }

  int dist(int x,int y)
  {
    int lca = findLCA(x,y);
    return height[x] + height[y] - 2 * height[lca];
  }

private:
  void dfs(int now)
  {
    count[now] = 1;
    REP(i,SIZE((*adj)[now])) if((*adj)[now][i] != parent[now][0])
    {
      height[(*adj)[now][i]] = height[now] + 1;
      parent[(*adj)[now][i]][0] = now;
      dfs((*adj)[now][i]);
      count[now] += count[(*adj)[now][i]];
    }
  }

  void fillParent() 
  {
    FOR(i,1,K) REP(j,N)
    {
      parent[j][i] = parent[parent[j][i-1]][i-1];
    }
  }
};

int n,q;
Centroid c;
int a,b;
vi parent;
vector<vi> adj;
LCA lca;
int bawah[100005];
int t,v;

void update(int x)
{
  int now = x;
  while (now != -1)
  {
    MIN(bawah[now],lca.dist(now,x));
    now = parent[now];
  }
}

int query(int x)
{
  int risan = bawah[x];
  int now = x;
  while (now != -1)
  {
    MIN(risan, bawah[now] + lca.dist(now, x));
    now = parent[now];
  }
  return risan;
}

int main()
{
  scanf("%d %d",&n,&q);
  adj.resize(n);
  REP(i,n-1)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  c.init(n,adj);
  lca.init(n,adj);
  parent = c.centroid();
  REP(i,n) bawah[i] = INF;
  update(0);
  TC(q)
  {
    scanf("%d %d",&t,&v);
    --v;
    if (t == 1) update(v);
    else printf("%d\n",query(v));
  }
  return 0;
}