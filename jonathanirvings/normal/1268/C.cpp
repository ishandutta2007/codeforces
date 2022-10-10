//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef tree<
    int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

struct BIT
{
  vector<LL> arr;
  void sz(int x) 
  {
    arr.resize(x+1);
    REP(i,x+1) arr[i] = 0;
  }
  void update(int x,LL y)
  {
    ++x;
    int m = SIZE(arr);
    while (x < m)
    {
      arr[x] += y;
      x += (x & -x);
    }
  }
  LL query(int x)
  {
    ++x;
    LL ret = 0;
    while (x > 0)
    {
      ret += arr[x];
      x -= (x & -x);
    }
    return ret;
  }
  LL query(int a,int b)
  {
    if (a > b) return 0;
    return query(b) - query(a-1);
  }
};

int n;
int p[200005];
int pos[200005];
ordered_set S;

LL inv[200005];
LL kumpul[200005];
BIT cnt, jum;

LL sebar(int x)
{
  if (x % 2 == 0) return x / 2 + sebar(x - 1);
  int y = x / 2;
  return (LL)y * (y + 1);
}

int main()
{
  scanf("%d",&n);
  REP(i,n)
  {
    scanf("%d",&p[i]);
    --p[i];
    pos[p[i]] = i;
  }
  cnt.sz(n);
  jum.sz(n);
  REP(i,n)
  {
    S.insert(pos[i]);
    inv[i] = (i == 0 ? 0 : inv[i-1]);
    inv[i] += i - S.order_of_key(pos[i]);

    cnt.update(pos[i],1);
    jum.update(pos[i],pos[i]);
    int median = (*S.find_by_order(i / 2));

    kumpul[i] = jum.query(median+1,n-1)-cnt.query(median+1,n-1)*median;
    kumpul[i] += cnt.query(0,median)*median-jum.query(0,median);
    kumpul[i] -= sebar(i + 1);
  }
  REP(i,n) printf("%lld ",inv[i] + kumpul[i]);
  puts("");
  return 0;
}