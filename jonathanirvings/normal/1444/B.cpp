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

LL f[1000005];
LL invf[1000005];
LL a[1000005];
LL MOD = 998244353;
LL dapat[1000005];
LL dua[1000005];
int n;

LL bigmod(LL a,LL b)
{
  if (b == 0) return 1;
  LL tmp = bigmod(a,b/2);
  LL tmp2 = tmp * tmp % MOD;
  if (b % 2 == 0) return tmp2;
  return tmp2 * a % MOD;
}

LL C(int n,int k)
{
  return f[n] * invf[k] % MOD * invf[n-k] % MOD;
}

void bf()
{
  vi tot(n);
  REP(i,1<<n) if (__builtin_popcount(i) == n / 2)
  {
    vi a,b;
    REP(j,n) if (i & (1 << j)) a.pb(j);
    else b.pb(j);
    REVERSE(b);
    REP(j,SIZE(a))
    {
      if (a[j] > b[j]) ++tot[a[j]];
      else ++tot[b[j]];
    }
  }
  REP(i,n) printf("%d ",tot[i]);
  puts("");
  exit(0);
}

int main()
{
  scanf("%d",&n);
  n *= 2;
  // bf();
  f[0] = 1;
  dua[0] = 1;
  FORN(i,1,n)
  {
    f[i] = f[i-1] * i % MOD;
    dua[i] = dua[i-1] * 2 % MOD;
  }
  FORN(i,0,n) invf[i] = bigmod(f[i],MOD-2);

  LL risan = 0;
  LL tot = C(n, n / 2);
  REP(i,n) scanf("%lld",&a[i]);
  SORTA(a,n);
  REP(i,n)
  {
    if (i < n / 2) risan -= tot * a[i];
    else risan += tot * a[i];
    risan %= MOD;
  }
  // REP(i,n) scanf("%lld",&a[i]);
  // SORTA(a,n);
  // LL tot = C(n, n / 2);
  // REP(i,n)
  // {
  //   LL cur = 0;
  //   if (i < n / 2)
  //   {
  //     // if (i % 2 == 0)
  //     // {

  //     // } else
  //     // {
  //     //   cur = 2
  //     // }
  //   } else 
  //   {
  //     cur = tot - dapat[n - 1 - i];
  //   }
  //   dapat[i] = cur;
  //   risan = (risan + cur * a[i]) % MOD;
  //   risan = (risan - (tot - cur) * a[i]) % MOD;
  //   // cur = C(n-1,i) * a[i] % MOD;
  //   // if (i % 2 == 0) risan -= cur;
  //   // else risan += cur;
  //   // risan %= MOD;
  //   // VALUE(risan);
  // }
  // risan = (risan * 2) % MOD;
  if (risan < 0) risan += MOD;
  printf("%lld\n",risan);
  return 0;
}