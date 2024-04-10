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

LL MOD = 998244353;

int T;
int k;
int A,h;
int risan[100];

LL bigpow(LL a,LL b)
{
  if (b == 0) return 1;
  LL tmp = bigpow(a,b/2);
  LL tmp2 = tmp * tmp % MOD;
  if (b % 2 == 0) return tmp2;
  return tmp2 * a % MOD;
}

pair<LL,LL> hitung(int turns, vi angka,int mask)
{
  assert((1 << turns) == SIZE(angka));
  LL res = 0;
  REP(i,turns)
  {
    int kalah_disini = (1 << (turns - i)) + 1;
    vi new_angka;
    for (int j = 0; j < SIZE(angka); j += 2)
    {
      if (mask % 2 == 0)
      {
        new_angka.pb(angka[j]);
        risan[angka[j+1]] = kalah_disini;
        res += (LL)(angka[j+1]) * bigpow(A,kalah_disini) % MOD;
      } else 
      {
        new_angka.pb(angka[j+1]);
        risan[angka[j]] = kalah_disini;
        res += (LL)(angka[j]) * bigpow(A,kalah_disini) % MOD;
      }
      mask /= 2;
    }
    angka = new_angka;
    res %= MOD;
  }
  assert(SIZE(angka) == 1);
  risan[angka[0]] = -1;
  LL res1 = (res + angka[0] * bigpow(A,1)) % MOD;
  LL res2 = (res + angka[0] * bigpow(A,2)) % MOD;
  return mp(res1,res2);
}

map<LL,int> hasil1, hasil2;

LL cari(LL x)
{
  LL res = h - x;
  if (res < 0) res += MOD;
  return res;
}

int main()
{
  // int x = 3;
  // LL y = 4;
  // LL res = x - y;
  // printf("%lld\n",res); return 0;
  T = 1;
  TC(T)
  {
    scanf("%d %d %d",&k,&A,&h);
    int n = 1<<k;
    vi satu,dua;
    REPN(i,n)
    {
      if (i <= n / 2) satu.pb(i);
      else dua.pb(i);
    }
    int matches_half = SIZE(dua) - 1;
    REP(i,1 << matches_half)
    {
      pair<LL,LL> hasil = hitung(k-1,dua,i);
      hasil1[hasil.fi] = i;
      hasil2[hasil.se] = i;
    }
    REP(i,1<<matches_half)
    {
      pair<LL,LL> hasil = hitung(k-1,satu,i);
      if (hasil1.count(cari(hasil.se)))
      {
        hitung(k-1,dua,hasil1[cari(hasil.se)]);
        REPN(i,n) if (risan[i] == -1)
        {
          if (i <= n / 2) risan[i] = 2;
          else risan[i] = 1;
        }
        goto ok;
      }
      if (hasil2.count(cari(hasil.fi)))
      {
        hitung(k-1,dua,hasil2[cari(hasil.fi)]);
        REPN(i,n) if (risan[i] == -1)
        {
          if (i <= n / 2) risan[i] = 1;
          else risan[i] = 2;
        }
        goto ok;
      }
    }
    puts("-1");
    continue;
    ok:;
    REPN(i,n) printf("%d ",risan[i]);
    puts("");
  }
  return 0;
}