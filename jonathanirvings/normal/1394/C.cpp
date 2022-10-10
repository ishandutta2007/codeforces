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
string s;
pii dat[500005];
pii X,Y;

int cost(int x,int y)
{
  int res = 0;
  REP(i,n) 
  {
    if (dat[i].fi <= x && dat[i].se <= y) MAX(res,max(abs(x - dat[i].fi),abs(y - dat[i].se)));
    else if (dat[i].fi >= x && dat[i].se >= y) MAX(res,max(abs(x - dat[i].fi),abs(y - dat[i].se)));
    else MAX(res,abs(x - dat[i].fi) + abs(y - dat[i].se));
  }
  return res;
}

pii findy(int x,int sum)
{
  pii r = mp(Y.fi,Y.se);
  REP(i,n)
  {
    if (dat[i].fi > x) break;
    if (x - dat[i].fi > sum) return mp(-INF,-INF);
    pii rnow = mp(dat[i].se - (sum - (x - dat[i].fi)), (dat[i].se + sum));
    MAX(r.fi,rnow.fi);
    MIN(r.se,rnow.se);
  }
  // debug("findy = %d %d %d %d\n",x,sum,r.fi,r.se);
  return r.fi <= r.se ? r : mp(-INF,-INF);
}

pii find(int sum)
{
  int L = X.fi;
  int R = X.se;
  int x = -INF;
  pii r = mp(-INF,-INF);
  while (L <= R)
  {
    int M = (L + R) >> 1;
    pii tmp = findy(M,sum);
    if (tmp != mp(-INF,-INF))
    {
      x = M;
      r = tmp;
      L = M + 1;
    } else R = M - 1;
  }
  REP(i,n)
  {
    if (dat[i].fi <= x) continue;
    if (dat[i].fi - x > sum) return mp(-INF,-INF);
    pii rnow = mp(dat[i].se - sum, dat[i].se + (sum - (dat[i].fi - x)));
    MAX(r.fi,rnow.fi);
    MIN(r.se,rnow.se);
  }
  return r.fi <= r.se ? mp(x,r.fi) : mp(-INF,-INF);
  // debug("find = %d %d %d %d\n",sum,res.fi,res.se,cost(res.fi,res.se));
  // return cost(res.fi,res.se) <= sum ? res : mp(-INF,-INF);
}

int main()
{
  scanf("%d",&n);
  X = mp(INF,-INF);
  Y = mp(INF,-INF);
  REP(i,n)
  {
    s = GetString();
    REP(j,SIZE(s)) if (s[j] == 'B') ++dat[i].fi;
    else ++dat[i].se;
    MIN(X.fi,dat[i].fi);
    MAX(X.se,dat[i].fi);
    MIN(Y.fi,dat[i].se);
    MAX(Y.se,dat[i].se);
  }
  SORTA(dat,n);
  // REP(i,n) debug("%d %d\n",dat[i].fi,dat[i].se);
  // pii tmp = find(12); debug("%d %d\n",tmp.fi,tmp.se); return 0;

  int risan;
  pii res;
  int L = 0;
  int R = 1000000;
  while (L <= R)
  {
    int M = (L + R) >> 1;
    pii tmp = find(M);
    if (tmp != mp(-INF,-INF))
    {
      risan = M;
      res = tmp;
      R = M - 1;
    } else 
    {
      L = M + 1;
    }
  }
  printf("%d\n",risan);
  string ana = string(res.fi,'B') + string(res.se,'N');
  printf("%s\n",ana.c_str());
  // pair<int,pair<int,int>> risan = find();
  // printf("%d\n",risan.se.se);
  // string res(risan.fi,'B');
  // res += string(risan.se.fi,'N');
  // printf("%s\n",res.c_str());
  return 0;
}