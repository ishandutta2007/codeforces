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

int n,q;
LL tree[4000005];
LL prop[4000005];
int pt[500005];
int w[500005];
vi child[500005];
LL tot[500005];
int sz[500005];
int v,l,r;
int lst[500005];

LL risan[500005];
vector<pair<int,pii>> queries[500005];

void pushdown(int now)
{
  tree[now*2] += prop[now];
  tree[now*2+1] += prop[now];
  prop[now*2] += prop[now];
  prop[now*2+1] += prop[now];
  prop[now] = 0;
}

void dfs(int x)
{
  lst[x] = x;
  for (int y : child[x])
  {
    dfs(y);
    MAX(lst[x],lst[y]);
  }
}


void build(int now,int L,int R)
{
  if (L == R)
  {
    tree[now] = (SIZE(child[L]) == 0 ? tot[L] : INFF);
    return;
  }
  int M = (L + R) >> 1;
  build(now*2,L,M);
  build(now*2+1,M+1,R);
  tree[now] = min(tree[now*2],tree[now*2+1]);
  // debug("%d %d: %lld\n",L,R,tree[now]);
}

void update(int now,int L,int R,int x,int y,LL v)
{
  if (x <= L && R <= y)
  {
    prop[now] += v;
    tree[now] += v;
    return;
  }
  if (R < x || y < L) return;
  pushdown(now);
  int M = (L + R) >> 1;
  update(now*2,L,M,x,y,v);
  update(now*2+1,M+1,R,x,y,v);
  tree[now] = min(tree[now*2],tree[now*2+1]);
}

LL query(int now,int L,int R,int x,int y)
{
  if (x <= L && R <= y) return tree[now];
  if (R < x || y < L) return INFF;
  pushdown(now);
  int M = (L + R) >> 1;
  return min(query(now*2,L,M,x,y),query(now*2+1,M+1,R,x,y));
}

void dbg(int now,int L,int R)
{
  debug("(%d, %d): (%lld, %lld)\n", L, R, tree[now], prop[now]);
  if (L == R) return;
  int M = (L + R) >> 1;
  dbg(now*2,L,M);
  dbg(now*2+1,M+1,R);
}

void go(int x)
{
  // VALUE(x);
  // dbg(1,1,n);
  for (pair<int,pii> q : queries[x])
  {
    int l = q.se.fi;
    int r = q.se.se;
    LL res = query(1,1,n,l,r);
    risan[q.fi] = res;
  }
  for (int y : child[x])
  {
    update(1,1,n,1,n,w[y]);
    // dbg(1,1,n);
    update(1,1,n,y,lst[y],-2*w[y]);
    // dbg(1,1,n);
    go(y);
    update(1,1,n,y,lst[y],2*w[y]);
    update(1,1,n,1,n,-w[y]);
  }
}

int main()
{
  scanf("%d %d",&n,&q);
  FORN(i,2,n)
  {
    scanf("%d %d",&pt[i],&w[i]);
    tot[i] = w[i] + tot[pt[i]];
    child[pt[i]].pb(i);
  }
  REP(i,q)
  {
    scanf("%d %d %d",&v,&l,&r);
    queries[v].pb(mp(i,mp(l,r)));
  }
  dfs(1);
  // FORN(i,1,n) debug("%d %d\n",i,lst[i]);
  build(1,1,n);
  go(1);
  REP(i,q) printf("%lld\n",risan[i]);
  return 0;
}