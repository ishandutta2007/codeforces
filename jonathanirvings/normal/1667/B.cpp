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

int Tcases;
int a[500005];
pii tree[10000005];
LL pre[500005];
int dp[500005];
int n;
map<LL,int> urutan;
vector<LL> beda;

pii gabung(pii a,pii b)
{
  return mp(max(a.fi,b.fi),max(a.se,b.se));
}

void update(int ix,int L,int R,int pos,pii val)
{
  if (L == R)
  {
    tree[ix] = gabung(tree[ix],val);
    return;
  }
  int M = (L + R) >> 1;
  if (pos <= M) update(ix*2+1,L,M,pos,val);
  else update(ix*2+2,M+1,R,pos,val);
  tree[ix] = gabung(tree[ix*2+1],tree[ix*2+2]);
  // debug("update %d %d %d %d %d\n",ix,L,R,tree[ix].fi,tree[ix].se);
}

pii query(int ix,int L,int R,int x,int y)
{
  if (x <= L && R <= y) return tree[ix];
  if (y < L || R < x) return mp(-INF,-INF);
  int M = (L + R) >> 1;
  return gabung(query(ix*2+1,L,M,x,y),query(ix*2+2,M+1,R,x,y));
}

void update(int pos,pii val)
{
  // debug("update DS[%d] = (%d,%d)\n",pos,val.fi,val.se);
  update(0,0,SIZE(beda)-1,pos,val);
}

pii query(int x,int y)
{
  if (x > y) return mp(-INF,-INF);
  return query(0,0,SIZE(beda)-1,x,y);
}

int main()
{
  scanf("%d",&Tcases);
  TC(Tcases)
  {
    scanf("%d",&n);
    
    FORN(i,0,6*(n+5)) tree[i] = mp(-INF,-INF);
    FORN(i,0,n) dp[i] = -INF;
    urutan.clear();
    beda.clear();
    
    REP(i,n) scanf("%d",&a[i]);
    pre[0] = 0;
    REP(i,n) pre[i+1] = pre[i] + a[i];

    FORN(i,0,n) beda.pb(pre[i]);
    SORT(beda);
    beda.erase(unique(ALL(beda)),beda.end());
    REP(i,SIZE(beda)) urutan[beda[i]] = i;

    // REP(i,SIZE(beda)) debug("%lld\n",beda[i]);
    // FORN(i,0,n) VALUE(pre[i]);

    dp[n] = 0;
    update(urutan[pre[n]],mp(dp[n] + n, dp[n]));
    FORD(i,n-1,0)
    {
      int &ret = dp[i];
      // VALUE(urutan[pre[i]]);
      // debug("%d %d %d\n",i,urutan[pre[i]],query(urutan[pre[i]]+1,SIZE(beda)-1).fi);
      MAX(ret,query(urutan[pre[i]]+1,SIZE(beda)-1).fi - i);
      MAX(ret,query(urutan[pre[i]],urutan[pre[i]]).se);
      MAX(ret,dp[i + 1] - 1);

      update(urutan[pre[i]],mp(ret + i, ret));

      // debug("%d %d\n",tree[0].fi,tree[0].se);
    }
    // FORN(i,0,n) debug("%d ",dp[i]); debug("\n");

    int risan = dp[0];
    printf("%d\n",risan);
  }
  return 0;
}