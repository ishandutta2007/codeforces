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

class SuffixArray {
public:
  vector<vector<int> > process;
  int n,m;
  vector<int> ada;
  vector<pair<pii,int> > data, data2;
  vector<int> A;
  
  void counting(void)
  {
    REP(i,SIZE(ada)) ada[i] = 0;
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

  void init()
  {
    ada.resize(max(256, n) + 5);
    data.resize(n + 5);
    data2.resize(n + 5);
    A.resize(n + 5);
    process.clear();
  }

  void build(string s)
  {
    n = SIZE(s);
    init();
    process.pb(A);
    REP(i,n) process[0][i] = s[i];
    m = 0;
    for (int i = 0; (1 << i) <= n; ++i, ++m);
    FORN(i,1,m)
    {
      process.pb(A);
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
      if (x == n - 1)
      {
        m = i;
        break;
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

int T;
string s;
string ss;
SuffixArray SA;
int risan;
int l,r;

int LCP(int x,int y)
{
  return SA.LCP(x,SIZE(ss)-1-y);
}

int ansl()
{
  int ans = 0;
  FORN(i,1,SIZE(s))
  {
    if (i + l == r) break;
    if (LCP(l+1,l+i) >= i) MAX(ans,i);
  }
  return ans;
}

int ansr()
{
  int ans = 0;
  FORN(i,1,SIZE(s))
  {
    if (r - i == l) break;
    if (LCP(r-i,r-1) >= i) MAX(ans,i);
  }
  return ans;
}

int main()
{
  scanf("%d",&T);
  TC(T)
  {
    s = GetString();
    ss = s; REVERSE(ss); ss = s + ss;
    SA.build(ss);
    risan = 0;
    while (risan < SIZE(s) - risan - 1 && s[risan] == s[SIZE(s) - risan - 1])
      ++risan;
    --risan;
    l = risan;
    r = SIZE(s) - risan - 1;
    int al = ansl();
    int ar = ansr();
    if (al >= ar)
    {
      FORN(i,0,l+al) printf("%c",s[i]);
      FOR(i,r,SIZE(s)) printf("%c",s[i]);
      puts("");
    } else 
    {
      FORN(i,0,l) printf("%c",s[i]);
      FOR(i,r-ar,SIZE(s)) printf("%c",s[i]);
      puts("");
    }
  }
  return 0;
}