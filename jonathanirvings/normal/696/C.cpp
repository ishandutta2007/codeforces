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
typedef vector<vl> vll;

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
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.3 (BETA)

LL MOD = 1e9 + 7;

inline vll kali(const vll &a,const vll &b)
{
    int m = a.size();
    int n = b.size();
    int o = b[0].size();
    vll ans(m);
    REP(i,m) ans[i].resize(o);
    FOR(i,0,m) 
    {
        //vl tmp(o);
        FOR(j,0,o)
        {
            LL nilai = 0;
            FOR(k,0,n) nilai = (nilai + (a[i][k] * b[k][j]));
            ans[i][j] = nilai % MOD;
        }
        //ans[i] = tmp;
    }
    return ans;
}

inline vll pangkat(const vll &a,LL b)
{
    if (b == 1) return a;
    vll simpan = pangkat(a,b/2);
    if (b % 2 == 0) return (kali(simpan,simpan));
    return (kali(kali(simpan,simpan),a));
}

LL pangkat(LL a,LL b)
{
  if (b == 0) return 1;
  if (b == 1) return (a % MOD);
  LL tmp = pangkat(a,b/2);
  LL tmp2 = (tmp * tmp) % MOD;
  if (b % 2 == 0) return tmp2;
  return (tmp2 * a) % MOD;
}

int n;
LL x;
LL MODINV = 5e8 + 4;
LL MODINVTIGA = 333333336;

int main()
{
  //scanf("%d",&n);
  cin >> n;
  vll kiri = {{0,1}};
  vll mat = {{0,2},{1,1}};
  LL now = 2;
  int genap = 0;
  REP(i,n)
  {
    cin >> x;
    //scanf("%lld",&x);
    if (x % 2 == 0) ++genap;
    //VALUE(i);
    //mat = pangkat(mat,x);
    now = pangkat(now,x);
  }
  LL R = (now * MODINV) % MOD;
  LL atas = (R - (genap > 0 ? -1 : 1) + MOD) % MOD;
  LL L = (atas * MODINVTIGA) % MOD;
  cout << L << "/" << R << endl;
  return 0;
}