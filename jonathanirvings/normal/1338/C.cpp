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

set<int> s;

string binary(int x, int k)
{
  string s = "";
  while (x > 0)
  {
    s = (char)(x % 2 + '0') + s;
    x /= 2;
  }
  while (SIZE(s) < k) s = '0' + s;
  return s;
}

int bf(int x)
{
  vi v;
  int K = 10;
  while (SIZE(s) < 500)
  {
    FORN(i,1,10000) FORN(j,i+1,10000)
    {
      if (s.count(i) == 0 && s.count(j) == 0 && s.count(i^j) == 0)
      {
        printf("%s %s %s (%5d %5d %5d)\n", binary(i,K).c_str(), binary(j,K).c_str(), binary(i^j,K).c_str(),i,j,i^j);
        // debug("%d %d %d\n",i,j,i^j);
        s.insert(i);
        s.insert(j);
        s.insert(i^j);
        v.pb(i);
        v.pb(j);
        v.pb(i^j);
        goto hell;
      }
    }
    hell:;
  }
  // vi v(ALL(s));
  return v[x-1];
}

string bin(LL x,LL y)
{
  string s = "";
  for (LL i = 1; i < y; i *= 4)
  {
    s = (char)(x % 4 + '0') + s;
    x /= 4;
  }
  return s;
}

LL solve(LL n)
{
  --n;
  LL row = n / 3;
  LL cur = 1;
  LL currow = 0;
  while (1)
  {
    if (currow + cur > row)
    {
      LL rem = row - currow;
      string s = bin(rem,cur);
      LL a = cur + rem;
      LL b = 0;
      
      LL l = cur * 2;
      LL r = cur * 3;
      REP(i,SIZE(s))
      {
        LL d = (r - l) >> 2;
        if (s[i] == '0');
        else if (s[i] == '1') l = l + 2 * d;
        else if (s[i] == '2') l = l + 3 * d;
        else l = l + d;
        r = l + d;
      }
      assert(l + 1 == r);
      b = l;

      // VALUE(s);
      // debug("%lld %lld %lld\n",a,b,a^b);

      if (n % 3 == 0) return a;
      if (n % 3 == 1) return b;
      return a ^ b;
    } else 
    {
      currow += cur;
      cur = cur * 4;
    }
  }
}

int t;
LL n;

int main()
{
  // VALUE(bf(1));
  // VALUE(solve(11));
  scanf("%d",&t);
  // t = 100000;
  TC(t)
  {
    scanf("%lld",&n);
    // n = 10000000000000000LL;
    printf("%lld\n",solve(n));
  }
  return 0;
}