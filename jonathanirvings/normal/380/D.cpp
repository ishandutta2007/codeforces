//start of jonathanirvings' template v3.0.1 (BETA)

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
#include <assert.h>
#include <time.h>
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
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
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
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.1 (BETA)

int T,n,x;
int pos[100005];
int posr[100005];
LL MOD = 1000000007;
LL f[100005];
vii angka;

LL bigmod(int a, int b, int MOD)
{
  LL x=1,y=a; 
  while(b > 0)
  {
    if(b % 2 == 1)
      x = (x * y) % MOD;
    y = (y * y) % MOD;
    b /= 2;
  }
  return x;
}

LL inverse(int n,int M) {return bigmod(n,M-2,M);}

LL C(int n, int r)
{
  if (n < r) return 0;
  return (f[n]*((inverse(f[r], MOD) * inverse(f[n-r], MOD)) % MOD)) % MOD;
}

int main()
{
  f[0] = 1;
  FORN(i,1,100000) 
  {
    f[i] = (f[i-1] * i) % MOD;
  }
  //scanf("%d",&T);
  T = 1;
  TC(T)
  {
    pii kecil2 = mp(INF,INF);
    angka.clear();
    scanf("%d",&n);
    RESET(pos,-1);
    RESET(posr,-1);
    REP(i,n)
    {
      scanf("%d",&x);
      if (x > 0) 
      {
        pos[x-1] = i;
        posr[i] = x - 1;
        MIN(kecil2,mp(x-1,i));
        if (x-1 > 0) angka.pb(mp(x-1,i));
      }
    }
    int kecil = kecil2.se;
    if (kecil == INF)
    {
      LL risan = 1;
      REP(i,n-1) risan = (risan * 2LL) % MOD;
      printf("%lld\n",risan);
      continue;
    }
    angka.pb(mp(n,n));
    SORT(angka);
    LL risan = 0;
    LL petrus1 = 1;
    LL petrus2 = 1;
    if (kecil2.fi != 0) {
      int R = angka[0].se + 1;
      int L = angka[0].se - angka[0].fi - 1;
      if (-1 <= L && R <= n)
      {
        int last = angka[0].fi;
        FOR(j,1,SIZE(angka))
        {
          if (L < angka[j].se && angka[j].se < R)
          {
            petrus1 = 0;
            break;
          }
          int ada = angka[j].fi - last;
          if (R <= angka[j].se)
          {
            int sisa = angka[j].se - R;
            if (ada < sisa)
            {
              petrus1 = 0;
              break;
            }
            petrus1 = (petrus1 * C(ada - 1, sisa)) % MOD;
            L -= (ada - sisa - 1);
            R = angka[j].se + 1;
          } else if (angka[j].se <= L)
          {
            int sisa = L - angka[j].se;
            if (ada < sisa)
            {
              petrus1 = 0;
              break;
            }
            petrus1 = (petrus1 * C(ada - 1, sisa)) % MOD;
            R += (ada - sisa - 1);
            L = angka[j].se - 1;
          }
          last = angka[j].fi;
        }
      } else petrus1 = 0;
    }
    if (kecil2.fi != 0) {
      int L = angka[0].se - 1;
      int R = angka[0].se + angka[0].fi + 1;
      if (-1 <= L && R <= n)
      {
        int last = angka[0].fi;
        FOR(j,1,SIZE(angka))
        {
          //debug("%d %d %d %d %lld\n",angka[j].fi,angka[j].se,L,R,petrus2);
          if (L < angka[j].se && angka[j].se < R)
          {
            petrus2 = 0;
            break;
          }
          int ada = angka[j].fi - last;
          if (R <= angka[j].se)
          {
            int sisa = angka[j].se - R;
            if (ada < sisa)
            {
              petrus2 = 0;
              break;
            }
            petrus2 = (petrus2 * C(ada - 1, sisa)) % MOD;
            L -= (ada - sisa - 1);
            R = angka[j].se + 1;
          } else if (angka[j].se <= L)
          {
            int sisa = L - angka[j].se;
            if (ada < sisa)
            {
              petrus2 = 0;
              break;
            }
            petrus2 = (petrus2 * C(ada - 1, sisa)) % MOD;
            R += (ada - sisa - 1);
            L = angka[j].se - 1;
          }
          last = angka[j].fi;
          //debug("%d %d %d %d %lld\n",angka[j].fi,angka[j].se,L,R,petrus2);
        }
      } else petrus2 = 0;
    }
    //REP(i,n) printf("%d ",pos[i]);
    //puts("");
    //VALUE(petrus1);
    //REP(i,SIZE(angka)) printf("%d %d\n",angka[i].fi,angka[i].se);
    REP(i,n) if (pos[0] == -1 || pos[0] == i)
    {
      LL petrus = 1;
      int L = i - 1;
      int R = i + 1;
      int last = 0;
      REP(j,SIZE(angka))
      {
        if (j == 1 && kecil2.fi > 0) break;
        if (L < angka[j].se && angka[j].se < R)
        {
          petrus = 0;
          break;
        }
        int ada = angka[j].fi - last;
        if (R <= angka[j].se)
        {
          int sisa = angka[j].se - R;
          if (ada < sisa)
          {
            petrus = 0;
            break;
          }
          petrus = (petrus * C(ada - 1, sisa)) % MOD;
          L -= (ada - sisa - 1);
          R = angka[j].se + 1;
        } else if (angka[j].se <= L)
        {
          int sisa = L - angka[j].se;
          if (ada < sisa)
          {
            petrus = 0;
            break;
          }
          petrus = (petrus * C(ada - 1, sisa)) % MOD;
          R += (ada - sisa - 1);
          L = angka[j].se - 1;
        }
        last = angka[j].fi;
      }
      //debug("%d %lld\n",i,petrus);
      if (kecil2.fi > 0)
      {
        if (i < kecil) petrus = (petrus * petrus1) % MOD;
        else petrus = (petrus * petrus2) % MOD;
      }
      //VALUE(kecil);
      //debug("%d %lld\n",i,petrus);
      risan += petrus;
      if (risan > MOD) risan -= MOD;
    }
    printf("%lld\n",risan);
  }
  return 0;
}