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
int h[300005];
int kiri[300005];
int b[300005];

LL tree[4000005];
LL dp[300005];
stack<pii> s;

LL query(int ix,int L,int R,int x,int y)
{
  if (x <= L && R <= y) return tree[ix];
  if (R < x || y < L) return -INFF;
  int M = (L + R) >> 1;
  return max(query(ix*2+1,L,M,x,y),query(ix*2+2,M+1,R,x,y));
}

void update(int ix,int L,int R,int pos,LL val)
{
  if (L == R)
  {
    tree[ix] = val;
    return;
  }
  int M = (L + R) >> 1;
  if (pos <= M) update(ix*2+1,L,M,pos,val);
  else update(ix*2+2,M+1,R,pos,val);
  tree[ix] = max(tree[ix*2+1],tree[ix*2+2]);
}

int main()
{
  scanf("%d",&n);
  FORN(i,0,8*n) tree[i] = -INFF;

  REP(i,n)
  {
    scanf("%d",&h[i]);
    while (SIZE(s) > 0 && s.top().fi > h[i]) s.pop();
    if (SIZE(s) == 0) kiri[i] = -1;
    else kiri[i] = s.top().se;
    s.push(mp(h[i],i));
  }
  REP(i,n)
  {
    scanf("%d",&b[i]);
    dp[i] = -INFF;
    if (i > 0)
    {
      if (kiri[i] != -1)
      {
        MAX(dp[i], dp[kiri[i]]);
        MAX(dp[i],b[i] + query(0,0,n-1,kiri[i],i-1));
      } else
      {
        MAX(dp[i],b[i] + query(0,0,n-1,0,i-1));
        MAX(dp[i],(LL)b[i]);
      }
    } else dp[i] = b[i];
    update(0,0,n-1,i,dp[i]);
    // debug("%d: %d %lld\n",i,kiri[i],dp[i]);
  }
  printf("%lld\n",dp[n-1]);
}