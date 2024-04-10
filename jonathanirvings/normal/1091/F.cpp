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

typedef long double Double;

string s;
int n;
Double l[100005];
Double akhir[100005];
Double punya[100005];
Double kurang[100005];
int G = -1, W = -1, L = -1;

int main()
{
  scanf("%d",&n);
  REP(i,n) scanf("%Lf",&l[i]);
  s = GetString();
  Double stamina = 0;
  Double risan = 0;
  REP(i,n)
  {
    if (s[i] == 'G')
    {
      if (G == -1) G = i;
      stamina += l[i];
      risan += l[i] * 5;
    } else if (s[i] == 'W')
    {
      if (W == -1) W = i;
      stamina += l[i];
      risan += l[i] * 3;
    } else if (s[i] == 'L')
    {
      stamina -= l[i];
      if (stamina < 0)
      {
        if (W != -1)
        {
          l[W] += -stamina;
          risan += 3 * -stamina;
        }
        else
        {
          assert(G != -1);
          l[G] += -stamina;
          risan += 5 * -stamina;
        }
        stamina = 0;
      }
      risan += l[i];
    }
    punya[i] = stamina;
  }
  debug("%.2Lf\n",risan);

  Double can = 0;
  FORD(i,n-1,0)
  {
    debug("%.2Lf %.2Lf\n",punya[i],can);
    if (punya[i] > can && s[i] == 'G')
    {
      Double buang = min((Double)(punya[i] - can) / 2, (Double)l[i]);
      debug("BUANG: %.2Lf\n",buang);
      risan -= (5 - 1) * buang;
      kurang[i] = buang;
      can += 2 * buang;
    }
    if (s[i] == 'L')
    {
      // MAX(can,l[i]);
      can += l[i];
    } else if (s[i] == 'G')
    {
      can = max((Double)0, can - l[i]);
    } else if (s[i] == 'W')
    {
      can = max((Double)0, can - l[i]);
    }
  }
  debug("%.2Lf\n",risan);

  stamina = 0;
  REP(i,n)
  {
    if (s[i] == 'G')
    {
      stamina += l[i];
    } else if (s[i] == 'W')
    {
      stamina += l[i];
    } else if (s[i] == 'L')
    {
      stamina -= l[i];
    }
    stamina -= 2 * kurang[i];
    punya[i] = stamina;
  }

  can = 0;
  FORD(i,n-1,0)
  {
    can += 2 * kurang[i];
    if (punya[i] > can && s[i] == 'W')
    {
      Double buang = min((Double)(punya[i] - can) / 2, (Double)l[i]);
      risan -= (3 - 1) * buang;
      can += 2 * buang;
    }
    if (s[i] == 'L')
    {
      // MAX(can,l[i]);
      can += l[i];
    } else if (s[i] == 'G')
    {
      can = max((Double)0, can - l[i]);
    } else if (s[i] == 'W')
    {
      can = max((Double)0, can - l[i]);
    }
  }

  printf("%.0Lf\n",risan);
  return 0;
}