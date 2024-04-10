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

int n,m,r;
pii pos[2005];
LL b[2005];
bitset<2000> adj[2005];
LL C[2005][2005];
int MOD = 1000000007;

int main()
{
  scanf("%d %d %d",&n,&m,&r);
  REP(i,n) scanf("%d %d %lld",&pos[i].fi,&pos[i].se,&b[i]);
  REP(i,n) REP(j,n)
  {
    if (max(abs(pos[i].fi-pos[j].fi),abs(pos[i].se-pos[j].se)) <= r)
    {
      adj[i].set(j);
    }
  }
  LL risan = 0;
  FORN(i,0,n)
  {
    C[i][0] = C[i][i] = 1;
    FOR(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
  }
  REP(i,n)
  {
    LL ada = C[n][m] - C[n - adj[i].count()][m];
    LL mul = b[i] * b[i] % MOD;
    risan = (risan + ada * mul) % MOD;
    // debug("%d %lld %lld\n",i,ada,mul);
  }
  REP(i,n) FOR(j,i+1,n)
  {
    LL ada = C[n][m] - C[n - adj[i].count()][m] - C[n - adj[j].count()][m];
    ada += C[n - (adj[i] | adj[j]).count()][m];
    LL mul = 2 * b[i] * b[j] % MOD;
    risan = (risan + ada * mul) % MOD;
    // debug("%d %d %lld %lld\n",i,j,ada,mul);
  }
  risan = (risan + MOD) % MOD;
  printf("%lld\n",risan);
  return 0;
}