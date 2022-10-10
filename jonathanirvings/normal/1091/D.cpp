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

LL MOD = 998244353;
LL fact[1000005];
LL invfact[1000005];
int n;

LL f(int n)
{
  vi res;
  vi temp;
  REP(i,n) temp.pb(i+1);
  do
  {
    REP(i,SIZE(temp)) res.pb(temp[i]);
  } while (PERMUTE(ALL(temp)));
  LL risan = 0;
  REP(i,SIZE(res)-n+1)
  {
    LL now = 0;
    FOR(j,i,i+n) now += res[j];
    if (now == n * (n + 1) / 2) ++risan;
  }
  return risan;
}

// LL fact(int n)
// {
//   if (n == 0) return 1;
//   return fact(n-1) * n;
// }

LL bigpow(LL a,LL b)
{
  if (b == 0) return 1;
  LL tmp = bigpow(a,b/2);
  LL tmp2 = tmp*tmp%MOD;
  if (b % 2 == 0) return tmp2;
  return tmp2 * a % MOD;
}

LL x(int n)
{
  --n;
  LL res = 0;
  FORN(i,1,n) res = (res + invfact[i]) % MOD;
  return res * fact[n] % MOD;
}

LL g(int n)
{
  return ((fact[n] - x(n)) % MOD + MOD) * n % MOD;
}

int main()
{
  scanf("%d",&n);
  fact[0] = 1;
  FORN(i,1,n) fact[i] = fact[i-1] * i % MOD;
  invfact[n] = bigpow(fact[n],MOD-2);
  FORD(i,n-1,0) invfact[i] = invfact[i+1] * (i + 1) % MOD;

  printf("%lld\n",g(n));
  // FORN(i,1,n) printf("%d %lld %lld %lld\n",i,f(i),g(i),x(i));
  // FORN(i,1,n) assert(f(i) == g(i));
  // FORN(i,1,10) printf("%d %lld %lld %lld %lld\n",i,f(i) % MOD,f(i)/i,f(i)-fact(i),(f(i)-fact(i))/i);
  // FORN(i,1,10) printf("%d %lld %lld\n",i,f(i),f(i)/i-fact(i));
  return 0;
}