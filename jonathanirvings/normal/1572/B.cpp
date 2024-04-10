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
int dat[200005];
int tot;
int now;
vi risan;

void hajar(int mid)
{
  FOR(i,mid+1,n) if (dat[i] == 1)
  {
    // VALUE(i);
    // VALUE(SIZE(risan));
    if (dat[i + 1] == 1)
    {
      dat[i] = dat[i + 1] = 0;
      risan.pb(i - 1);
    } else 
    {
      dat[i] = dat[i + 1] = dat[i + 2] = (dat[i] ^ dat[i + 1] ^ dat[i + 2]);
      risan.pb(i);
      if (dat[i] == 1)
      {
        dat[i] = dat[i + 1] = 0;
        risan.pb(i - 1);
      }
    }
  }
  FORD(i,mid-1,0) if (dat[i] == 1)
  {
    if (dat[i - 1] == 1)
    {
      dat[i] = dat[i - 1] = 0;
      risan.pb(i - 1);
    } else 
    {
      dat[i - 2] = dat[i - 1] = dat[i] = (dat[i - 2] ^ dat[i - 1] ^ dat[i]);
      risan.pb(i - 2);
      if (dat[i] == 1)
      {
        dat[i] = dat[i - 1] = 0;
        risan.pb(i - 1);
      }
    }
  }
  puts("YES");
  printf("%d\n",SIZE(risan));
  REP(i,SIZE(risan)) printf("%d ",risan[i]+1); puts("");
}

int main()
{
  scanf("%d",&Tcases);
  TC(Tcases)
  {
    scanf("%d",&n);
    risan.clear();
    tot = 0;
    now = 0;
    REP(i,n)
    {
      scanf("%d",&dat[i]);
      tot ^= dat[i];
    }
    if (tot != 0)
    {
      puts("NO");
      continue;
    }
    REP(mid,n)
    {
      // VALUE(mid);
      now ^= dat[mid];
      if (dat[mid] == 0 && now == 0)
      {
        hajar(mid);
        goto dah;
      }
    }
    FOR(i,1,n) if (dat[i] == 0 && dat[i - 1] == 1)
    {
      int x = i;
      while (dat[x] == 0) ++x;
      if ((x - i) % 2 == 1)
      {
        for (int j = i - 1; j + 2 < x; j += 2)
        {
          dat[j + 1] = dat[j + 2] = 1;
          risan.pb(j);
        }
        risan.pb(x - 2);
        dat[x - 2] = dat[x] = 0;
        hajar(x - 1);
        goto dah;
      }
    }
    puts("NO");
    dah:;
  }
  return 0;
}