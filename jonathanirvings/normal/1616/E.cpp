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

struct BIT
{
  vi arr;
  int tambah = 0;
  void sz(int x) 
  {
    tambah = 0;
    arr.resize(x+1);
    REP(i,x+1) arr[i] = 0;
  }
  void update(int x,int y)
  {
    ++x;
    tambah += y;
    int m = SIZE(arr);
    while (x < m)
    {
      arr[x] += y;
      x += (x & -x);
    }
  }
  int query(int x)
  {
    int ret = 0;
    while (x > 0)
    {
      ret += arr[x];
      x -= (x & -x);
    }
    return ret;
  }
  int besar(int x)
  {
    ++x;
    return tambah - query(x);
  }
};

int n;
string s,t;
vi pos[26];
int now[26];
int now2[26];

int main()
{
  int Tcases;
  scanf("%d",&Tcases);
  TC(Tcases)
  {
    REP(i,26) pos[i].clear();
    RESET(now,0);
    
    scanf("%d",&n);
    s = GetString();
    t = GetString();
    REP(i,SIZE(s)) pos[s[i]-'a'].pb(i);

    LL risan = INFF;
    int x = 0;
    while (x < n && s[x] == t[x])
    {
      FOR(i,0,s[x]-'a')
      {
        while (now[i] < SIZE(pos[i]) && pos[i][now[i]] <= x) ++now[i];
        if (now[i] < SIZE(pos[i])) MIN(risan,(LL)pos[i][now[i]] - x);
      }
      ++x;
    }
    RESET(now,0);
    REP(i,26)
    {
      while (now[i] < SIZE(pos[i]) && pos[i][now[i]] < x) ++now[i];
    }

    BIT bit;
    bit.sz(n);
    LL tambah = 0;
    while (x < n)
    {
      // REP(i,26) now2[i] = now[i];
      FOR(i,0,t[x] - 'a')
      {
        if (now[i] < SIZE(pos[i]))
        {
          MIN(risan, tambah + pos[i][now[i]] - x + bit.besar(pos[i][now[i]]));
        }
      }
      int i = t[x] - 'a';
      if (now[i] < SIZE(pos[i]))
      {
        // debug("%d %d %d\n",pos[i][now[i]],x,bit.besar(pos[i][now[i]]));
        tambah += pos[i][now[i]] - x;
        tambah += bit.besar(pos[i][now[i]]);
        bit.update(pos[i][now[i]],1);
        ++now[i];
      } else break;
      // VALUE(tambah);
      ++x;
    }

    if (risan == INFF) puts("-1");
    else printf("%lld\n",risan);
  }
  return 0;
}