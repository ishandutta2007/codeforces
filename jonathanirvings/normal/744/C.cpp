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

pii ada[1<<17];
int n;
string tipe[20];
pii data[20];
int dp[1<<16][125];
pii butuh = mp(0,0);
vi loop[1<<16];

int jahja(int bit, int r)
{
  if (bit == 0)
  {
    if (r == 0) return 0;
    return -INF;
  }
  int &ret = dp[bit][r];
  if (ret != -1) return ret;
  ret = -INF;
  REP(l,SIZE(loop[bit]))
  {
    int i = loop[bit][l];
    pii x = ada[bit ^ (1 << i)];
    MAX(ret, jahja(bit ^ (1 << i), max(0, r - min(data[i].fi,x.fi))) + min(data[i].se,x.se));
  }
  return ret;
}

bool bisa(int token)
{
  pii untung = mp(butuh.fi - token, butuh.se - token);
  MAX(untung.fi, 0);
  MAX(untung.se, 0);
  if (untung.fi > 121) return false;
  return jahja((1 << n) - 1, untung.fi) >= untung.se;
  //return jahja((1 << n) - 1, untung.fi, untung.se);
}

int main()
{
  RESET(dp,-1);
  scanf("%d",&n);
  REP(i,n)
  {
    tipe[i] = GetString();
    scanf("%d %d",&data[i].fi,&data[i].se);
    butuh.fi += data[i].fi;
    butuh.se += data[i].se;
  }
  REP(i,1<<n)
  {
    ada[i] = mp(0,0);
    REP(j,n) if (i & (1 << j))
    {
      loop[i].pb(j);
      if (tipe[j] == "R") ++ada[i].fi;
      else ++ada[i].se;
    }
  }
  int risan = 0;
  int L = 0;
  int R = INF;
  while (L <= R)
  {
    int M = (L + R) >> 1;
    if (bisa(M))
    {
      risan = M;
      R = M - 1;
    } else L = M + 1;
  }
  printf("%d\n",risan + n);
  return 0;
}