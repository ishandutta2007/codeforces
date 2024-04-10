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

#define data asdf
 
int n;
string mat[15];
int data[15][15];

LL risan[1<<15];
int ct[1<<6][15];

vector<pair<pii,int>> cnt(vi &v,bool front)
{
  RESET(ct,0);
  SORT(v);
  do {
    int mask = 0;
    REP(i,SIZE(v)-1) if (data[v[i]][v[i+1]]) mask |= (1 << i);
    if (front) ++ct[mask][v[0]];
    else ++ct[mask][v[SIZE(v)-1]];
  } while (PERMUTE(ALL(v)));
  
  vector<pair<pii,int>> res;
  REP(i,1<<(SIZE(v)-1)) REP(j,n) if (ct[i][j] > 0) res.pb(mp(mp(i,j),ct[i][j]));
  return res;
}
 
int main()
{
  scanf("%d",&n);
  REP(i,n) mat[i] = GetString();
  REP(i,n) REP(j,n) data[i][j] = mat[i][j] - '0';
  REP(bagi,1<<n) if (__builtin_popcount(bagi) == n/2)
  {
    vi a, b;
    REP(i,n) if (bagi & (1 << i)) a.pb(i);
    else b.pb(i);
    if (n % 2 == 0 && a[0] != 0) continue;

    vector<pair<pii,int>> aa = cnt(a,0);
    vector<pair<pii,int>> bb = cnt(b,1);
    for (pair<pii,int> x : aa)
    {
      for (pair<pii,int> y : bb)
      {
        int mask = x.fi.fi;
        mask |= (data[x.fi.se][y.fi.se] << (SIZE(a) - 1));
        mask |= (y.fi.fi << SIZE(a));
        risan[mask] += (LL)x.se * y.se;
      }
    }
  }

  if (n % 2 == 0)
  {
    REP(i,1<<(n-1))
    {
      int x = 0;
      REP(j,n-1) if (i & (1 << j)) x |= (1 << (n - 1 - j - 1));
      printf("%lld ",risan[i] + risan[x]);
    }
    // puts("");
    // REP(i,1<<(n-1)) printf("%lld ",risan[i]);
  } else REP(i,1<<(n-1)) printf("%lld ",risan[i]);
  puts("");
  return 0;
}