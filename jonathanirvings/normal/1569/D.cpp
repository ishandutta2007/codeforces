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
int n,m,k;
set<int> adax,aday;
vi x,y;
vi dihorin, divert;
map<int,vi> horin,vert;

int main()
{
  scanf("%d",&T);
  TC(T)
  {
    scanf("%d %d %d",&n,&m,&k);
    adax.clear(); aday.clear(); x.clear(); y.clear();
    dihorin.clear(); divert.clear(); horin.clear(); vert.clear();
    x.resize(n);
    REP(i,n)
    {
      scanf("%d",&x[i]);
      adax.insert(x[i]);
    }
    y.resize(m);
    REP(i,m)
    {
      scanf("%d",&y[i]);
      aday.insert(y[i]);
    }
    REP(i,k)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      if (adax.count(a) && aday.count(b)) continue;
      if (adax.count(a))
      {
        divert.pb(b);
        vert[a].pb(b);
      }
      else if (aday.count(b))
      {
        dihorin.pb(a);
        horin[b].pb(a);
      }
    }
    SORT(dihorin);
    SORT(divert);
    LL risan = 0;
    {
      int now = 0;
      int j = 0;
      REP(i,SIZE(dihorin))
      {
        now = lower_bound(ALL(x),dihorin[i]) - x.begin();
        if (now < SIZE(x) && x[now] == dihorin[i]) continue;
        while (j < SIZE(dihorin) && dihorin[j] < (now < SIZE(x) ? x[now] : INF)) ++j;
        risan += j - i - 1;
      }
      for (pair<int, vi> hor : horin)
      {
        vi wow = hor.se;
        SORT(wow);
        now = 0;
        j = 0;
        REP(i,SIZE(wow))
        {
          now = lower_bound(ALL(x),wow[i]) - x.begin();
          if (now < SIZE(x) && x[now] == wow[i]) continue;
          while (j < SIZE(wow) && wow[j] < (now < SIZE(x) ? x[now] : INF)) ++j;
          risan -= j - i - 1;
        }
      }

    }
    // debug("\n");
    {
      int now = 0;
      int j = 0;
      REP(i,SIZE(divert))
      {
        now = lower_bound(ALL(y),divert[i]) - y.begin();
        if (now < SIZE(y) && y[now] == divert[i]) continue;
        while (j < SIZE(divert) && divert[j] < (now < SIZE(y) ? y[now] : INF)) ++j;
        risan += j - i - 1;
      }
      for (pair<int, vi> vert : vert)
      {
        vi wow = vert.se;
        SORT(wow);
        now = 0;
        j = 0;
        REP(i,SIZE(wow))
        {
          now = lower_bound(ALL(y),wow[i]) - y.begin();
          if (now < SIZE(y) && y[now] == wow[i]) continue;
          while (j < SIZE(wow) && wow[j] < (now < SIZE(y) ? y[now] : INF)) ++j;
          risan -= j - i - 1;
        }
      }
    }
    printf("%lld\n",risan);
  }
  return 0;
}