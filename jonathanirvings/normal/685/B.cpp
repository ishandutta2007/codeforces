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
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.3 (BETA)

int n,q;
int parent[20][300005];
vi child[300005];
int risan[300005];
int isi[300005];
int h[300005];
int point[300005];

int pt(int x)
{
  if (x == -1) return -1;
  if (x == point[x]) return x;
  return point[x] = pt(point[x]);
}

int naik(int now, int lv)
{
  FORD(i,19,0)
  {
    if (lv >= (1 << i))
    {
      now = parent[i][now];
      lv -= (1 << i);
    }
  }
  return now;
}

void dfs(int now)
{
  isi[now] = 1;
  REP(i,SIZE(child[now]))
  {
    h[child[now][i]] = h[now] + 1;
    dfs(child[now][i]);
    isi[now] += isi[child[now][i]];
  }
}

void dfs2(int now)
{
  REP(i,SIZE(child[now]))
  {
    dfs2(child[now][i]);
  }
  int con = 0;
  REP(i,SIZE(child[now]))
  {
    MAX(con,isi[child[now][i]]);
  }
  int lo = -1, hi = -1, L, R;
  L = 0; R = h[now];
  while (L <= R)
  {
    int M = (L + R) >> 1;
    int m = naik(now,M);
    if (con <= isi[m] / 2)
    {
      lo = m;
      R = M - 1;
    } else L = M + 1;
  }
  L = 0; R = h[now];
  while (L <= R)
  {
    int M = (L + R) >> 1;
    int m = naik(now,M);
    if (isi[m] - isi[now] <= isi[m] / 2)
    {
      hi = m;
      L = M + 1;
    } else R = M - 1;
  }
  //debug("%d %d %d\n",now,lo,hi);
  if (lo == -1 || hi == -1 || h[lo] < h[hi]) return;
  //debug("%d %d %d\n",now,lo,hi);
  while (1)
  {
    //debug("%d %d\n",lo,pt(lo));
    lo = pt(lo);
    //VALUE(lo);
    if (lo == -1 || h[lo] < h[hi]) break;
    //VALUE(lo);
    //debug("%d %d\n",lo,now);
    risan[lo] = now;
    //VALUE(lo);
    point[lo] = parent[0][lo];
    //VALUE(lo);
  }
  //debug("%d %d %d\n",now,lo,hi);
}

int main()
{
  RESET(risan,-1);
  scanf("%d %d",&n,&q);
  REP(i,n) point[i] = i;
  parent[0][0] = -1;
  FOR(i,1,n)
  {
    scanf("%d",&parent[0][i]);
    --parent[0][i];
    child[parent[0][i]].pb(i);
  }
  FOR(i,1,20) REP(j,n)
  {
    if (parent[i-1][j] == -1) parent[i][j] = -1;
    else parent[i][j] = parent[i-1][parent[i-1][j]];
  }
  h[0] = 0;
  dfs(0);
  dfs2(0);
  //REP(i,n) debug("%d %d\n",i,risan[i]);
  TC(q)
  {
    int x;
    scanf("%d",&x);
    printf("%d\n",risan[x-1] + 1);
  }
  //REP(i,n) debug("%d %d %d\n",i,isi[i],h[i]);
  return 0;
}