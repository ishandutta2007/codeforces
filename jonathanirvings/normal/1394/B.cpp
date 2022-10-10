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

int n,m,k;
int u,v,w;
vii adj[200005];
vii inv[200005];
bool cannot[15][15];
bool no[15][15][15][15];
int pt[105];
vi num;
int risan = 0;

int root(int x)
{
  if (pt[x] == x) return x;
  return pt[x] = root(pt[x]);
}

void gabung(int x,int y)
{
  pt[root(x)] = root(y);
}

int cv(int x,int y)
{
  return x * 10 + y;
}

int cv(pii p)
{
  return cv(p.fi,p.se);
}

pii cvv(int x)
{
  return mp(x / 10, x % 10);
}

void dfs(int now)
{
  if (now == k)
  {
    // REP(i,k) debug("%d ",num[i]); debug("\n");
    REP(i,k) FOR(j,i+1,k)
    {
      if (no[i][num[i]][j][num[j]]) return;
      // if (root(cv(i,num[i])) == root(cv(j,num[j]))) return;
    }
    // REP(i,k) debug("%d ",num[i]); debug("\n");
    ++risan;
  } else 
  {
    REP(i,now+1) if (!cannot[now][i])
    {
      num[now] = i;
      dfs(now+1);
    } 
  }
}

int main()
{
  scanf("%d %d %d",&n,&m,&k);
  TC(m)
  {
    scanf("%d %d %d",&u,&v,&w);
    --u; --v;
    adj[u].pb(mp(w,v));
    inv[v].pb(mp(w,u));
  }
  REP(i,n)
  {
    SORT(adj[i]);
    SORT(inv[i]);
  }
  REP(i,101) pt[i] = i;
  REP(i,n)
  {
    vii ada;
    for (pii tmp : inv[i])
    {
      int x = tmp.se;
      int y;
      REP(j,SIZE(adj[x])) if (adj[x][j].se == i) 
      {
        y = j;
        break;
      }
      ada.pb(mp(SIZE(adj[x]) - 1,y));
    }
    SORT(ada);
    FOR(i,1,SIZE(ada)) if (ada[i] == ada[i-1]) cannot[ada[i].fi][ada[i].se] = 1;
    ada.erase(unique(ALL(ada)),ada.end());
    // VALUE(i);
    REP(i,SIZE(ada)) REP(j,SIZE(ada))
    {
      no[ada[i].fi][ada[i].se][ada[j].fi][ada[j].se] = 1;
    }
    // FOR(i,1,SIZE(ada))
    // {
    //   // debug("%d %d, %d %d\n", ada[i-1].fi,ada[i-1].se,ada[i].fi,ada[i].se);
    //   gabung(cv(ada[i-1]),cv(ada[i]));
    // }
  }
  // REP(i,k) REP(j,i+1) debug("%d %d %d\n",i,j,cannot[i][j]);
  num = vi(k,0);
  dfs(0);
  printf("%d\n",risan);
  // FORN(i,1,k) REP(j,i) debug("%d %d %d\n",i,j,cannot[i][j]);
  return 0;
}