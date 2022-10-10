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

constexpr int kMod = 998244353;

template <typename T>
T pow(T a, int b) {
  if (b == 1) {
    return a;
  }
  T res = pow(a, b >> 1);
  res = res * res;
  if (b & 1) {
    res = res * a;
  }
  return res;
}

template <int MOD>
struct ModularInt {
  ModularInt() { num = 0; }
  ModularInt(int num): num(num) {}

  void operator+=(const ModularInt& other) {
    num += other.num;
    if (num >= MOD) {
      num -= MOD;
    }
  }

  ModularInt operator+(const ModularInt& other) const {
    int res = num + other.num;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  void operator-=(const ModularInt& other) {
    num += MOD - other.num;
    if (num >= MOD) {
      num -= MOD;
    }
  }

  ModularInt operator-(const ModularInt& other) const {
    int res = num - other.num + MOD;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  void operator*=(const ModularInt& other) {
    num = (long long)num * other.num % MOD;
  }

  ModularInt operator*(const ModularInt& other) const {
    return (long long)num * other.num % MOD;
  }

  ModularInt operator/(const ModularInt& other) const {
    return (*this) * pow(other, MOD - 2);
  }

  int num;
};

typedef ModularInt<kMod> Int;

int n,m;
int l[55],r[55];
bool pr[100005];
vi primes;
Int risan = 0;

int ceil(int x,int y)
{
  return (x + y - 1) / y;
}

Int f(int bagi)
{
  REP(i,n) if (ceil(l[i],bagi) > r[i] / bagi) return 0;
  vector<Int> dp(m / bagi + 1, 0);
  dp[0] = 1;
  REP(i,n)
  {
    vector<Int> pre = dp;
    FORN(j,1,m/bagi) pre[j] = pre[j-1] + dp[j];
    FORN(j,0,m/bagi)
    {
      if (j < ceil(l[i],bagi)) dp[j] = 0; else
      {
        int x = max(0,j - r[i]/bagi);
        dp[j] = pre[j - ceil(l[i],bagi)] - (x == 0 ? 0 : pre[x - 1]);
      }
    }
    // FORN(j,0,m/bagi) printf("%d ",dp[j].num); puts("");
  }
  Int res = 0;
  FORN(i,0,m/bagi) res += dp[i];
  return res;
}

void dfs(int u,int ada,int cur)
{
  if (u == SIZE(primes) || cur > m / primes[u])
  {
    // printf("%d %d %d %d\n",u,ada,cur,f(cur).num);
    if (ada%2==0) risan += f(cur);
    else risan -= f(cur);
    return;
  }
  dfs(u+1,ada,cur);
  dfs(u+1,ada+1,cur*primes[u]);
}

int main() {
  scanf("%d %d",&n,&m);
  REP(i,n) scanf("%d %d",&l[i],&r[i]);
  // f(1); return 0;
  RESET(pr,1);
  FORN(i,2,m) if (pr[i])
  {
    primes.pb(i);
    for (int j = 2; i * j <= m; ++j) pr[i * j] = false;
  }
  dfs(0,0,1);
  printf("%d\n",risan.num);
}