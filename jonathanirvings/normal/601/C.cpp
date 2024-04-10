//start of jonathanirvings' template v3.0.0 (BETA)

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
  sprintf(x,"%d",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%d",&res);
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

//end of jonathanirvings' template v3.0.0 (BETA)

double dp[105][100005];
double dp2[105][100005];
bool sudah[105][100005];
bool sudah2[105][100005];
int tot;
int data[105];
int n,m;

double jahja(int now, int jum);

double jahja2(int now,int jum)
{
  if (sudah2[now][jum]) return dp2[now][jum];
  sudah2[now][jum] = 1;
  if (jum == 0) return dp2[now][jum] = jahja(now, jum);
  return dp2[now][jum] = jahja(now, jum) + jahja2(now, jum - 1);
}

double jumlah(int now, int jum1, int jum2)
{
  return jahja2(now,jum2) - jahja2(now,jum1-1);
}

double jahja(int now,int jum)
{
  //if (jum + m * (n - now) < tot) return (m - 1);
  //if (jum + (n - now) >= tot) return 0;
  if (now == n)
  {
    if (jum < tot) return (m - 1);
    return 0;
  }
  if (sudah[now][jum]) return dp[now][jum];
  sudah[now][jum] = 1;
  double &ret = dp[now][jum];
  ret = jumlah(now+1,jum+1,jum+m);
  ret -= jahja(now+1,jum+data[now]);
  //printf("%d %d %lf\n",now,jum,ret);
  return ret = ret /(double)(m - 1);
}

int main()
{
  scanf("%d %d",&n,&m);
  if (m == 1) 
  {
    puts("1.000");
    return 0;
  }
  REP(i,n)
  {
    scanf("%d",&data[i]);
    tot += data[i];
  }
  double risan = jahja(0,0);
  //risan = risan;
  printf("%.10lf\n",risan + 1);
  return 0;
}