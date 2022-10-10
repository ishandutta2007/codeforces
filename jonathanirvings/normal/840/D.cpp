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

int n,q,l,r,k;
int a[300005];
int ada[300005];
pair<pii,pii> query[300005];
int risan[300005];
int COBA = 80;
int LIM = 550;

bool f(pair<pii,pii> a, pair<pii,pii> b)
{
  if (a.fi.fi / LIM != b.fi.fi / LIM) return a.fi.fi / LIM < b.fi.fi / LIM;
  return a.fi.se > b.fi.se;
}

void update(int x,int y)
{
  ada[a[x]] += y;
}

int _rand() 
{
  return (rand() << 15) | rand();
}

int main()
{
  // REP(i,100) VALUE(_rand());
  // return 0;
  srand(747444747);
  // int err = 0;
  scanf("%d %d",&n,&q);
  REP(i,n)
  {
    scanf("%d",&a[i]);
  }
  REP(i,q) 
  {
    scanf("%d %d %d",&query[i].fi.fi,&query[i].fi.se,&query[i].se.fi);
    --query[i].fi.fi;
    --query[i].fi.se;
    query[i].se.se = i;
  }
  sort(ALLA(query,q),f);
  int L = 0;
  int R = 0;
  REP(i,q)
  {
    while (R <= query[i].fi.se)
    {
      update(R,1);
      ++R;
    }
    while (R > query[i].fi.se + 1)
    {
      --R;
      update(R,-1);
    }
    while (L < query[i].fi.fi)
    {
      update(L,-1);
      ++L;
    }
    while (L > query[i].fi.fi)
    {
      --L;
      update(L,1);
    }
    int ans = INF;
    int l = query[i].fi.fi;
    int r = query[i].fi.se;
    int k = query[i].se.fi;
    REP(i,COBA)
    {
      int x = a[_rand() % (r - l + 1) + l];
      int cnt = ada[x];
      if (cnt * k > (r - l + 1)) MIN(ans,x);
    }
    risan[query[i].se.se] = ans == INF ? -1 : ans;
    // if (ans == INF) ++err;
  }
  REP(i,q) printf("%d\n",risan[i]);
  // VALUE(err);
  return 0;
}