//start of jonathanirvings' template v3.0.3 (BETA)

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
#include <assert.h>
#include <time.h>
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

vi pos[10];
int nxt[10][1005][1005];
int n;
int data[1005];
int dp[1<<8][1005];
int bawah;

int jahja(int mask, int now)
{
  if (mask == ((1 << 8) - 1)) return 0;
  int &ret = dp[mask][now];
  if (ret >= 0) return ret;
  ret = -INF;
  REP(num,8) if (!(mask & (1 << num)))
  {
    if (nxt[num][now][bawah] < INF) 
      MAX(ret,jahja(mask | (1 << num), nxt[num][now][bawah]) + bawah);
    if (nxt[num][now][bawah + 1] < INF) 
      MAX(ret,jahja(mask | (1 << num), nxt[num][now][bawah + 1]) + bawah + 1);
  }
  return ret;
}

int main()
{
  scanf("%d",&n);
  REP(i,n)
  {
    scanf("%d",&data[i]);
    --data[i];
    pos[data[i]].pb(i);
  }
  REP(num,8)
  {
    REP(i,n) 
    {
      nxt[num][i][0] = i;
      REPN(j,n + 5)
      {
        int ix = lower_bound(ALL(pos[num]),i) - pos[num].begin();
        if (ix + j - 1 >= SIZE(pos[num])) nxt[num][i][j] = INF;
        else nxt[num][i][j] = pos[num][ix + j - 1];
      }
      //printf("%d %d %d %d\n",num,i,j,nxt[num][i][j]);
    }
  }
  int irvan = 0;
  FORN(i,0,n/8 + 5)
  {
    bawah = i;
    RESET(dp,-1);
    int risan = jahja(0,0);
    MAX(irvan, risan);
    // VALUE(i);
    // VALUE(risan);
  }
  printf("%d\n",irvan);
  return 0;
}