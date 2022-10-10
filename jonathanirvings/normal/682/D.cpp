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
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.3 (BETA)

class SuffixArray {
public:
  int process[21][200005];
  int n,m,ada[200005];
  pair<pii,int> data[200005],data2[200005];
  int A[200005];
  
  void counting(void)
  {
    RESET(ada,0);
    int maks = 0;
    REP(i,n) 
    {
      ++ada[data[i].fi.fi+1];
      MAX(maks,data[i].fi.fi);
    }
    FORN(i,0,maks) ada[i+1] += ada[i];
    FORD(i,n-1,0)
    {
      data2[ada[data[i].fi.fi+1]-1] = data[i];
      --ada[data[i].fi.fi+1];
    }
    REP(i,n) data[i] = data2[i];
  }

  void build(string s)
  {
    n = SIZE(s);
    REP(i,n) process[0][i] = s[i] - 'a';
    m = 0;
    for (int i = 0; (1 << i) <= n; ++i, ++m);
    FORN(i,1,m)
    {
      RESET(ada,0);
      REP(j,n) 
      {
        int k = j + (1 << (i - 1));
        data[j] = mp(mp(k < n ? process[i-1][k] : -1,process[i-1][j]),j);
      }
      counting();
      REP(j,n) swap(data[j].fi.fi,data[j].fi.se);
      counting();
      int x = -1;
      REP(j,n) 
      {
        if (j == 0 || data[j].fi != data[j-1].fi) ++x;
        process[i][data[j].se] = x;
      }
    }
    REP(i,n) A[process[m][i]] = i;
  }

  int LCP(int a,int b)
  {
    int ret = 0;
    FORD(i,m,0)
    {
      if (process[i][a] == process[i][b])
      {
        ret += min(n,(1 << i));
        a += min(n,(1 << i));
        b += min(n,(1 << i));
      }
      if (b >= n) break;
    }
    return ret;
  }
};

string s,t;
string ss;
int n,m,k;
SuffixArray SA;
vi isi;
int dp[1005][1005][15];

int jahja(int x,int y,int rem)
{
  if (x >= m || y >= n || rem == 0) return 0;
  int &ret = dp[x][y][rem];
  if (ret >= 0) return ret;
  ret = max(jahja(x+1,y,rem),jahja(x,y+1,rem));
  int lcp = min(SA.LCP(x,y+m),m-x);
  MAX(ret,lcp + jahja(x+lcp,y+lcp,rem-1));
  return ret;
}

int main()
{
  scanf("%d %d %d",&m,&n,&k);
  s = GetString();
  t = GetString();
  ss = s + t;
  SA.build(ss);
  RESET(dp,-1);
  int risan = jahja(0,0,k);
  printf("%d\n",risan);
  return 0;
}