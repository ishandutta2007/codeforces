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

set<string> risan;

void dfs(string s)
{
  risan.insert(s);
  REP(i,SIZE(s)-1)
  {
    string t = "";
    REP(j,SIZE(s))
    {
      if (j == i) t += max(s[i],s[i+1]); else
      if (j == i + 1); else
      t += s[j];
    }
    dfs(t);
  }
}

LL MOD = 1000000007;

int ada[10];
int ada2[10];
int tambah[1000005];
LL lst = 0;
LL add = 0;

int main()
{
  string s;
  s = GetString();
  // dfs(s);
  // VALUE(SIZE(risan));
  
  // for (string t : risan)
  // {
  //   int x = 0;
  //   REP(i,SIZE(t)) if (t[i] == '1') ++x; else break;
  //   ++ada[x];
  //   if (x == 1)
  //   {
  //     int y = 0;
  //     FOR(i,1,SIZE(t)) if (t[i] == '0') ++y; else break;
  //     ++ada2[y];
  //   }
  // }

  // REP(i,10) debug("%d %d %d\n",i,ada[i],ada2[i]);

  if (s == string(SIZE(s),'0'))
  {
    printf("%d\n",SIZE(s));
    return 0;
  }

  int a = 0;
  while (s.back() == '0')
  {
    s.pop_back();
    ++a;
  }
  REVERSE(s);
  int b = 0;
  while (s.back() == '0')
  {
    s.pop_back();
    ++b;
  }
  REVERSE(s);
  VALUE(s);

  int nol = 0;

  REP(i,SIZE(s))
  {
    if (s[i] == '1')
    {
      nol = 0;
      lst += add + 1;
    } else 
    {
      ++nol;
      add -= tambah[nol];
      tambah[nol] = lst;
      add += tambah[nol];
    }
    lst %= MOD;
    add %= MOD;
    lst = (lst % MOD + MOD) % MOD;
    add = (add % MOD + MOD) % MOD;
  }

  lst = (lst % MOD + MOD) % MOD;
  lst = (lst * (a + 1)) % MOD;
  lst = (lst * (b + 1)) % MOD;
  printf("%lld\n",lst);

  // LL risan = 0;
  // LL lst = 0;
  // LL tambah = 0;
  // int nol = 1;

  // FORD(i,SIZE(s)-1,0)
  // {
  //   debug("%lld %lld\n",tambah,lst);
  //   if (s[i] == '0')
  //   {
  //     tambah = -1;
  //     ++nol;
  //   }
  //   else
  //   {
  //     if (tambah == -1)
  //     {
  //       tambah = (lst + 1) * nol % MOD;
  //     }
  //     lst = (lst + tambah) % MOD;
  //     nol = 0;
  //   }
  // }
  // printf("%lld\n",lst);
  return 0;
}