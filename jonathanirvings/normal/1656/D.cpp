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

bool dfs(int n,int now,int k)
{
  if (now == k) return n == 0;
  for (int i = (now == 0 ? k : now); i <= n; i += k)
  {
    if (dfs(n - i, now + 1, k)) return true;
  }
  return false;
}

bool bisa(int n, int k)
{
  return dfs(n,0,k);
}

bool coba(LL n, LL k)
{
  if (k == 1) return false;
  LL x = 2 * n / k;
  if (x - k < 0) return false;
  return (x - k) % 2 == 1;
}

LL cari(LL n)
{
  n = 2 * n;
  LL a = 1;
  while (n % 2 == 0)
  {
    a *= 2;
    n /= 2;
  }
  if (n == 1) return -1;
  return min(a,n);
  // for (LL i = 1; i * i <= 2 * n; ++i) if (2 * n % i == 0)
  // {
  //   if (coba(n,i)) return i;
  //   if (coba(n,2 * n / i)) return 2 * n / i;
  // }
  // return -1;
}

LL n;
int ans[1005];

int main()
{
  // FORN(n,2,50)
  // {
  //   printf("N=%d:",n);
  //   FORN(k,2,50)
  //   {
  //     if (bisa(n,k))
  //     {
  //       if (ans[n] == 0) ans[n] = k;
  //       printf(" %d",k);
  //       // break;
  //     }
  //   }
  //   puts("");
  // }
  // FORN(n,2,50)
  // {
  //   // printf("%d %d\n",n,cari(n));
  //   debug("%d %d\n",n,cari(n));
  //   if (cari(n) > 0) assert(bisa(n,cari(n)));
  // }
  // FORN(k,2,50)
  // {
  //   printf("K=%d:",k);
  //   FORN(n,2,50)
  //   {
  //     if (bisa(n,k)) printf(" %d",n);
  //   }
  //   puts("");
  // }
  // for (int i = 2; i <= 50; i += 2)
  // {
  //   printf("%d: %d %d\n",i,ans[i],ans[i/2]);
  // }
  scanf("%d",&Tcases);
  TC(Tcases)
  {
    scanf("%lld",&n);
    printf("%lld\n",cari(n));
  }
  return 0;
}