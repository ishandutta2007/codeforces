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

int n,m,p;
LL mask[200005];
int ada[1<<15];
vi subset[1<<15];

LL risan = 0;

int main()
{
  REP(bit,1<<15)
  {
    vi nyala;
    REP(i,15) if (bit & (1 << i)) nyala.pb(i);
    REP(bit2,1<<SIZE(nyala))
    {
      int ret = 0;
      REP(i,SIZE(nyala)) if (bit2 & (1 << i)) ret |= (1 << nyala[i]);
      if (ret != bit) subset[bit].pb(ret);
    }
  }

  scanf("%d %d %d",&n,&m,&p);
  REP(i,n)
  {
    string s = GetString();
    REP(j,m)
    {
      mask[i] = mask[i] * 2 + (s[j] - '0');
    }
  }
  FORN(tries,1,20)
  {
    int x = (LL)(rand() % n) * rand() % n;
    // VALUE(x);
    RESET(ada,0);
    vi nyala;
    REP(j,m) if (mask[x] & (1LL << j)) nyala.pb(j);
    REP(i,n)
    {
      int now = 0;
      REP(j,SIZE(nyala)) if (mask[i] & (1LL << nyala[j])) now |= (1 << j);
      // debug("%d %d\n",i,now);
      ++ada[now];
    }
    REP(i,1<<SIZE(nyala)) if (ada[i] > 0)
    {
      for (int j : subset[i]) ada[j] += ada[i];
    }
    // REP(i,1<<SIZE(nyala)) debug("%d=%d\n",i,ada[i]);
    REP(i,1<<SIZE(nyala)) if (ada[i] >= (n + 1) / 2)
    {
      if (__builtin_popcountll(risan) < __builtin_popcount(i))
      {
        risan = 0;
        REP(j,SIZE(nyala)) if (i & (1 << j)) risan |= (1LL << nyala[j]);
      }
    }
    // VALUE(__builtin_popcountll(risan));
  }
  string s = "";
  while (risan > 0)
  {
    if (risan % 2 == 0) s += '0';
    else s += '1';
    risan /= 2;
  }
  REVERSE(s);
  while (SIZE(s) < m) s = '0' + s;
  printf("%s\n",s.c_str());
  return 0;
}