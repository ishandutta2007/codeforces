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

int n,m,a,b;
int data[300005];
int parent[300005];
vi nol,satu,bebas;
vvi adj;
map<int,int> indeks[300005];
LCA lca;
int simpan[300005];
vi risan;

int pt(int x)
{
  if (parent[x] == x) return x;
  return parent[x] = pt(parent[x]);
}

void dfs(int now,int pt)
{
  REP(i,SIZE(adj[now]))
  {
    // VALUE(adj[now][i]);
    if (adj[now][i] == pt) continue;
    dfs(adj[now][i],now);
    simpan[now] += simpan[adj[now][i]];
  }
  // VALUE(now);
  // VALUE(simpan[now]);
  if (simpan[now] % 2)
  {
    risan.pb(indeks[now][lca.parent[now][0]]);
  }
}

int main()
{
  scanf("%d %d",&n,&m);
  adj.resize(n);
  REP(i,n) 
  {
    scanf("%d",&data[i]);
    if (data[i] == -1) bebas.pb(i);
    else if (data[i] == 1) satu.pb(i);
  }
  if (SIZE(satu) % 2 == 1)
  {
    if (SIZE(bebas) == 0) 
    {
      puts("-1");
      return 0;
    }
    satu.pb(bebas[0]);
  }
  REP(i,n) parent[i] = i;
  REP(i,m)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    indeks[a][b] = indeks[b][a] = i;
    if (pt(a) == pt(b)) continue;
    parent[pt(a)] = pt(b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  lca.init(n,adj);
  for (int i = 0; i < SIZE(satu); i += 2)
  {
    int a = satu[i];
    int b = satu[i + 1];
    int c = lca.findLCA(a,b);
    ++simpan[a];
    ++simpan[b];
    --simpan[c];
    --simpan[c];
  }
  dfs(0,-1);
  printf("%d\n",SIZE(risan));
  REP(i,SIZE(risan)) printf("%d ",risan[i] + 1);
  puts("");
  return 0;
}