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

LL MOD = 1e9 + 7;
pll dp[1005][1005];
bool sudah[1005][1005];
int k,pa,pb;
unordered_map<LL,LL> invv;

LL modpow(LL a, LL b)
{
  if (b == 0) return 1;
  LL tmp = modpow(a,b/2);
  LL tmp2 = (tmp * tmp) % MOD;
  if (b % 2 == 0) return tmp2;
  return (tmp2 * a) % MOD;
}

LL inv(LL a)
{
  if (invv.count(a)) return invv[a];
  return invv[a] = modpow(a,MOD-2);
}

pll jahja(int dah,int rem)
{
  pll &ret = dp[dah][rem];
  if (sudah[dah][rem]) return ret;
  sudah[dah][rem] = 1;
  if (dah >= rem)
  {
    LL atas = (pa + (LL)pb * dah) % MOD;
    LL bawah = pb;
    ret = mp(atas,bawah);
    // debug("%d %d %lld %lld\n",dah,rem,ret.fi,ret.se);
    return ret;
  }
  pll satu = mp(0, 1);
  pll dua = mp(0,1);
  
  pll temp = jahja(dah + 1, rem);

  satu.fi = pa * temp.fi % MOD;
  satu.se = (pa + pb) * temp.se % MOD;

  if (dah > 0)
  {
    pll temp2 = jahja(dah, rem - dah);
    dua.fi = (temp2.fi + temp2.se * dah) % MOD;
    dua.fi = dua.fi * pb % MOD;
    dua.se = (pa + pb) * temp2.se % MOD;
    // dua = pb * (jahja(dah, rem - dah) + dah) % MOD;
    // dua = dua * inv(pa + pb) % MOD;
  } else 
  {
    dua.fi = pb * temp.fi % MOD;
    dua.se = (pa + pb) * temp.se % MOD;
  }
  ret.fi = (satu.fi * dua.se + dua.fi * satu.se) % MOD;
  ret.se = (satu.se * dua.se) % MOD;
  // debug("%d %d %lld %lld\n",dah,rem,ret.fi,ret.se);
  return ret;
  // debug("%d %d %lld\n",dah,rem,satu + dua);
  // return ret = (satu + dua) % MOD;
}

int main()
{
  scanf("%d %d %d",&k,&pa,&pb);
  // RESET(dp,-1);
  RESET(sudah,0);
  pll risan = jahja(0,k);
  printf("%lld\n",risan.fi * inv(risan.se) % MOD);
  return 0;
}