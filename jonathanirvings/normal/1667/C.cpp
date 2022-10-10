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

int Tcases;
int n;

int kecil(int n)
{
  vii sq;
  // REP(i,n) REP(j,n) sq.pb(mp(i,j));
  REP(i,n) REP(j,n)
  {
    // if (max(i,j) <= (n + 1) / 2)
    sq.pb(mp(i,j));
  }
  sort(ALL(sq), [] (pii a, pii b) {
    return max(a.fi,a.se) < max(b.fi,b.se);
  });
  // REVERSE(sq);
  FORN(coba,1,n*n)
  {
    vi lepas;
    REP(i,coba) lepas.pb(0);
    REP(i,SIZE(sq)-coba) lepas.pb(1);

    do
    {
      vii taruh;
      REP(i,SIZE(lepas)) if (!lepas[i]) taruh.pb(sq[i]);
      REP(i,n) REP(j,n)
      {
        REP(k,SIZE(taruh))
        {
          if (i == taruh[k].fi || j == taruh[k].se) goto ok;
          if (i - taruh[k].fi == j - taruh[k].se) goto ok;
        }
        goto gabisa;
        ok:;
      }
      // REP(i,SIZE(taruh)) debug(">> %d %d\n", taruh[i].fi,taruh[i].se);
      return coba;

      gabisa:;

    } while (PERMUTE(ALL(lepas)));
  }
  return -1;
}

int coba(int n)
{
  FORN(k,1,n)
  {
    if (2 * (n - k) - 1 <= k) return k;
  }
  return INF;
}

bool adar[100005],adac[100005];

int main()
{
  scanf("%d",&n);
  int risan = coba(n);
  printf("%d\n",risan);
  FORD(i,n,risan+2)
  {
    pii now = mp(i,risan+1);
    now.fi -= (n - risan) + 1 * (n - i);
    now.se -= (n - risan) + 1 * (n - i);

    printf("%d %d\n",now.fi,now.se);
    adar[now.fi] = 1;
    adac[now.se] = 1;
  }
  FORN(i,risan+2,n)
  {
    pii now = mp(risan+1,i);
    now.fi -= 2 * (i - risan - 1);
    now.se -= 2 * (i - risan - 1);

    printf("%d %d\n",now.fi,now.se);
    adar[now.fi] = 1;
    adac[now.se] = 1;
  }
  FORN(i,1,risan) if (!adar[i] && !adac[i])
  {
    printf("%d %d\n",i,i);
  }
  // VALUE(coba(20));
  // VALUE(coba(100000));
  // FORN(i,1,20)
  {
    // int ans = kecil(i);
    // debug("%d %d %d %d\n",i,ans,i-ans,coba(i));
    // debug("n = %d\n",i);
    // debug("ans = %d\n",kecil(i));
  }
  return 0;
}