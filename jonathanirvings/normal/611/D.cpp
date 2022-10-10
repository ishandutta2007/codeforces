//start of jonathanirvings' template v3.0.1 (BETA)

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
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
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

//end of jonathanirvings' template v3.0.1 (BETA)

int n;
string s;
int MOD = 1e9 + 7;
LL HASH = 99999999999999997LL;
int dp[5005][5005];
int jum[5005][5005];
LL hashed[5005][5005];

int main()
{
  scanf("%d",&n);
  s = GetString();
  REP(i,n)
  {
    hashed[i][i] = (s[i] - '0');
    FOR(j,i+1,n)
    {
      hashed[i][j] = (hashed[i][j-1] * 10 + (s[j] - '0')) % HASH;
    }
  }
  FORD(i,n-1,0)
  {
    dp[i][n-1] = 1;
    FOR(j,i,n-1)
    {
      int st = j + 1;
      int k = st + (j - i + 1);
      if (k - 1 >= n || s[st] == '0') dp[i][j] = 0;
      else
      {
        dp[i][j] += jum[st][k];
        if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        int ret = -1;
        int L = i;
        int R = j;
        //if ( i== 3 && j == 3) VALUE(dp[i][j]);
        while (L <= R)
        {
          int M = (L + R) >> 1;
          if (hashed[i][M] != hashed[st][st+M-i])
          {
            ret = M;
            R = M - 1;
          } else L = M + 1;
        }
        if (ret != -1 && s[ret] < s[st+ret-i]) dp[i][j] += dp[st][k - 1];
        if (dp[i][j] >= MOD) dp[i][j] -= MOD;
      }
      //debug("%d %d %d\n",i,j,dp[i][j]);
    }
    jum[i][n] = 0;
    FORD(j,n-1,0)
    {
      jum[i][j] = jum[i][j+1] + dp[i][j];
      if (jum[i][j] >= MOD) jum[i][j] -= MOD;
    }
    //jum[i][n] = jum[i][n-1] + dp[i][n];
    //if (jum[i][n] >= MOD) jum[i][n] -= MOD;
  }
  int risan = 0;
  REP(i,n)
  {
    risan += dp[0][i];
    if (risan >= MOD) risan -= MOD;
  }
  printf("%d\n",risan);
  return 0;
}