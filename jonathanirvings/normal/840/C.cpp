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

int n;
int data[305];
LL convert[305];
vi prima;
int AKAR = 32000;
LL dua[1000005];
LL HASH = 999999999999999989LL;
LL MOD = 1e9 + 7;
map<int,int> ix;
map<LL,int> ada;
int grup[305];
int m;
LL f[305];
LL C[305][305];
LL dp[305][305];

void init()
{
  f[0] = 1;
  FORN(i,1,300) f[i] = ((LL)f[i-1] * i) % MOD;
  FORN(i,0,300)
  {
    C[i][0] = C[i][i] = 1;
    FOR(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
  }
}

int main()
{
  init();
  scanf("%d",&n);
  REP(i,n) scanf("%d",&data[i]);
  REP(i,n)
  {
    int x = data[i];
    FORN(j,2,AKAR) if(x % j == 0)
    {
      prima.pb(j);
      while (x % j == 0) x /= j;
    }
    if (x > 1) prima.pb(x);
  }
  SORT(prima);
  prima.erase(unique(ALL(prima)),prima.end());
  REP(i,SIZE(prima)) ix[prima[i]] = i;

  dua[0] = 1;
  FOR(i,1,SIZE(prima)) dua[i] = dua[i-1] * 2 % HASH;

  REP(i,n)
  {
    convert[i] = 0;
    int x = data[i];
    FORN(j,2,AKAR)
    {
      int ok = 0;
      while (x % j == 0)
      {
        x /= j;
        ok ^= 1;
      }
      if (ok) convert[i] = (convert[i] + dua[ix[j]]) % HASH;
    }
    if (x > 1) convert[i] = (convert[i] + dua[ix[x]]) % HASH;
    ++ada[convert[i]];
  }
  m = 0;
  for (map<LL,int>::iterator it = ada.begin(); it != ada.end(); ++it)
  {
    grup[m] = it->se;
    ++m;
  }
  grup[m++] = 1;
  SORTA(grup,m);
  // REP(i,m) VALUE(grup[i]);
  // VALUE(m);

  LL risan = f[grup[0]-1];
  int tpos = grup[0];
  int tsplit = 0;
  if (grup[0] > 1) tsplit = grup[0];
  dp[0][tsplit] = 1;
  FOR(i,1,m)
  {
    int cnt = grup[i];
    FORN(j,0,tpos)
    {
      int possplit = j;
      int posjoin = tpos-j;
      REPN(k,cnt)
      {
        int kiri = cnt - k;
        LL tmp1 = (LL)C[kiri+k-1][k-1] * dp[i-1][j] % MOD;
        FORN(l,0,k)
        {
          int inssplit = l;
          int insjoin = k-l;
          int tmp = j+kiri-inssplit;
          if (tmp >= 0 && possplit >= inssplit && posjoin >= insjoin)
          {
            LL tmp2 = (LL)C[possplit][inssplit]*C[posjoin][insjoin]%MOD*tmp1%MOD;
            dp[i][tmp] = (dp[i][tmp] + tmp2) % MOD;
          }
        }
      }
    }
    tpos += cnt;
    tsplit += cnt-1;
    risan = risan * f[cnt] % MOD;
  }
  risan = risan * dp[m-1][0] % MOD;
  if (risan < 0) risan += MOD;
  printf("%lld\n",risan);
  return 0;
}