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

int T;
int n;

LL MOD = 998244353;
LL fact[200005];
LL invfact[200005];

LL pow(LL a,LL b)
{
  if (b == 0) return 1;
  LL tmp = pow(a,b/2);
  LL tmp2 = tmp * tmp % MOD;
  if (b % 2 == 0) return tmp2;
  return tmp2 * a % MOD;
}

LL C(int a,int b)
{
  return fact[a] * invfact[b] % MOD * invfact[a-b] % MOD;
}

int main()
{
  fact[0] = 1;
  FORN(i,1,200000) fact[i] = fact[i-1] * i % MOD;
  FORN(i,0,200000) invfact[i] = pow(fact[i],MOD-2);
  scanf("%d",&T);
  TC(T)
  {
    scanf("%d",&n);
    map<int,int> ada;
    REP(i,n) 
    {
      int x;
      scanf("%d",&x);
      ++ada[-x];
    }
    LL risan = fact[n];
    if (SIZE(ada) > 1)
    {
      pii a, b;
      int ctr = 0;
      for (pii c : ada)
      {
        if (ctr == 0) a = c;
        else if (ctr == 1) b = c;
        else break;
        ++ctr;
      }
      a.fi = -a.fi; b.fi = -b.fi;
      // debug("%d %d %d %d\n",a.fi,a.se,b.fi,b.se);
      if (a.se == 1)
      {
        if (a.fi - b.fi == 1)
        {
          LL kurang = fact[n - a.se - b.se];
          // VALUE(kurang);
          kurang = kurang * fact[b.se] % MOD;
          // VALUE(kurang);
          kurang = kurang * C(n,a.se + b.se) % MOD;
          // VALUE(kurang);
          risan = risan - kurang;
          if (risan < 0) risan += MOD;
        } else risan = 0;
      }
    }
    printf("%lld\n",risan);
  }
  return 0;
}