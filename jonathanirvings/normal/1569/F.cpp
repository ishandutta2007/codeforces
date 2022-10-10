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
vector<vector<pii>> all_pairs;
vector<pii> cur_pairs;
int mask;
bool adj[15][15];

vector<vector<int>> all_partitions;
vector<int> cur_partition;
// vector<bool> bisa;

void dfs()
{
  if (mask == 0)
  {
    all_pairs.pb(cur_pairs);
    return;
  }
  REP(i,n) if( mask & (1 << i))
  {
    FOR(j,i+1,n) if (mask & (1 << j))
    {
      mask ^= (1 << i);
      mask ^= (1 << j);
      cur_pairs.pb(mp(i,j));
      dfs();
      cur_pairs.pop_back();
      mask ^= (1 << i);
      mask ^= (1 << j);
    }
    break;
  }
}

void dfs2(int turns,vi angka)
{
  if (SIZE(angka) == 0)
  {
    all_partitions.pb(cur_partition);
    return;
  }
  REP(mask,1<<SIZE(angka)) if ((mask & (1 << 0)) && __builtin_popcount(mask) % 2 == 0)
  {
    vi new_angka;
    REP(i,SIZE(angka)) if (mask & (1 << i))
    {
      cur_partition[angka[i]] = turns;
    } else new_angka.pb(angka[i]);
    dfs2(turns+1,new_angka);
  }
}

vector<pii> pairs;
int dp[1<<6][12][12];

int jahja(int mask,int a,int b)
{
  if (mask == 0) return adj[a][b];
  int &ret = dp[mask][a][b];
  if (ret >= 0) return ret;
  ret = 0;
  REP(i,SIZE(pairs)) if (mask & (1 << i))
  {
    if (adj[a][pairs[i].fi] && adj[pairs[i].se][b]
        && jahja(mask ^ (1 << i),pairs[i].fi,pairs[i].se))
    {
      ret = 1;
      break;
    }
    if (adj[a][pairs[i].se] && adj[pairs[i].fi][b]
        && jahja(mask ^ (1 << i),pairs[i].se,pairs[i].fi))
    {
      ret = 1;
      break;
    }
  }
  return ret;
}

int main()
{
  scanf("%d %d %d",&n,&m,&k);
  mask = (1 << n) - 1;
  dfs();
  VALUE(SIZE(all_pairs));
  
  cur_partition = vi(n,-1);
  vi angka(n); iota(ALL(angka),0);
  dfs2(1,angka);
  // bisa.resize(SIZE(all_partitions));
  VALUE(SIZE(all_partitions));
  VALUE(SIZE(all_pairs) * SIZE(all_partitions));
  vector<vector<int>> can_partitions;

  // REP(i,SIZE(all_partitions))
  // {
  //   REP(j,SIZE(all_partitions[i])) debug("%d ",all_partitions[i][j]); debug("\n");
  // }

  TC(m)
  {
    int x,y;
    scanf("%d %d",&x,&y);
    --x; --y;
    adj[x][y] = adj[y][x] = 1;
  }
  // vi coba(n); iota(ALL(coba),0);
  // do
  // {
  //   REP(i,SIZE(coba)-1) if (!adj[coba[i]][coba[i+1]]) goto cannotcoba;
  //   REP(i,SIZE(coba)) debug("%d ",coba[i]); debug("\n");
  //   cannotcoba:;
  // } while (PERMUTE(ALL(coba)));
  
  for (vector<pii> p : all_pairs)
  {
    pairs = p;
    RESET(dp,-1);
    int full = (1 << SIZE(pairs)) - 1;
    REP(i,SIZE(pairs))
    {
      if (jahja(full ^ (1 << i), pairs[i].fi, pairs[i].se)) goto ok;
    }

    continue;
    ok:;
    // REP(i,SIZE(pairs)) debug("(%d,%d) ",pairs[i].fi,pairs[i].se);
    // debug("\n");
    for (int i = 0; i < SIZE(all_partitions); ++i)
    // REP(i,SIZE(all_partitions)) if (!bisa[i])
    {
      REP(j,SIZE(pairs)) if (all_partitions[i][pairs[j].fi] != all_partitions[i][pairs[j].se])
        goto cannot;
      
      can_partitions.pb(all_partitions[i]);
      swap(all_partitions[i],all_partitions[SIZE(all_partitions)-1]);
      all_partitions.pop_back();
      --i;

      cannot:;
    }
  }
  LL risan = 0;
  // REP(i,SIZE(all_partitions)) if (bisa[i])
  REP(i,SIZE(can_partitions))
  {
    // REP(j,SIZE(all_partitions[i])) debug("%d ",all_partitions[i][j]); debug("\n");
    // int beda = *max_element(ALL(all_partitions[i]));
    int beda = *max_element(ALL(can_partitions[i]));
    if (beda <= k)
    {
      LL cur = 1;
      FORD(i,k,k-beda+1) cur *= i;
      risan += cur;
    }
  }
  printf("%lld\n",risan);
  return 0;
}