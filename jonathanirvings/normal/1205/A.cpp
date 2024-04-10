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

void cek(int n)
{
  if (n % 2 == 0) return;
  vi p;
  p.pb(1);
  p.pb(4);
  p.pb(2);
  p.pb(3);
  FORN(i,5,2*n) p.pb(i);
  do
  {
    if (p[1] > p[SIZE(p)-1]) continue;
    vector<int> v;
    REP(i,2*n)
    {
      int tot = 0;
      REP(j,n) tot += p[(i + j) % (2 * n)];
      v.pb(tot);
    }
    SORT(v);
    if (v[SIZE(v)-1] - v[0] <= 1)
    {
      REP(i,2*n) printf("%d ",p[i]); puts("");
      return;
    }
  } while (PERMUTE(p.begin()+1,p.end()));
}

void print(int n)
{
  if (n % 2 == 0)
  {
    puts("NO");
    return;
  }
  vector<int> risan(2*n);
  int a = 0;
  int b = n;
  REP(i,n)
  {
    if (i % 2 == 0)
    {
      risan[a++] = i * 2;
      risan[b++] = i * 2 + 1;
    } else 
    {
      risan[b++] = i * 2;
      risan[a++] = i * 2 + 1;
    }
  }
  puts("YES");
  REP(i,2*n) printf("%d ",risan[i]+1);
  puts("");

}

int main()
{
  // scanf("%d",&n);
  // cek(3);
  // FORN(i,1,7)
  // {
  //   VALUE(i);
  //   cek(i);
  // }
  int n;
  scanf("%d",&n);
  print(n);
  return 0;
}