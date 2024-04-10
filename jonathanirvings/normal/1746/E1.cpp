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
int n;
int petax[16];

int query(vi v)
{
  printf("? ");
  printf("%d",SIZE(v));
  for (int x : v) printf(" %d",x);
  puts("");
  
  fflush(stdout);
  string s = GetString();
  if (s == "YES") return 1;
  return 0;
}

int query(vi v, vi w)
{
  vi gabung;
  for (int x : v) gabung.pb(x);
  for (int x : w) gabung.pb(x);
  return query(gabung);
}

int answer(int x)
{
  printf("! %d\n",x);
  
  fflush(stdout);
  string s = GetString();
  if (s == ":(") return 0;
  return 1;
}

int main()
{
  petax[0] = 10;
  petax[1] = 10;
  petax[2] = 12;
  petax[3] = 6;
  petax[4] = 12;
  petax[5] = 9;
  petax[6] = 5;
  petax[7] = 5;
  petax[8] = 10;
  petax[9] = 10;
  petax[10] = 9;
  petax[11] = 3;
  petax[12] = 6;
  petax[13] = 3;
  petax[14] = 5;
  petax[15] = 5;

  scanf("%d",&n);
  vi mungkin(n);
  iota(ALL(mungkin),1);
  while (SIZE(mungkin) > 2)
  {
    vvi grup(4);
    REP(i,SIZE(mungkin)) grup[i%4].pb(mungkin[i]);
    if (SIZE(mungkin) == 3) grup[3].pb(mungkin[0]);
    int res = 0;
    res = res * 2 + query(grup[0], grup[1]);
    res = res * 2 + query(grup[0], grup[2]);
    res = res * 2 + query(grup[0], grup[2]);
    res = res * 2 + query(grup[0], grup[1]);

    int hasil = petax[res];
    mungkin.clear();
    REP(i,4) if (hasil & (1 << i))
    {
      for (int x : grup[i]) mungkin.pb(x);
    }
    SORT(mungkin);
    mungkin.erase(unique(ALL(mungkin)),mungkin.end());
  }
  if (answer(mungkin[0])) return 0;
  answer(mungkin[1]);
  return 0;
}