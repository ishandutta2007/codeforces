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

string data[505];
int kanan[505][505];
int bawah[505][505];
int r,c,q,xa,ya,xb,yb;

int R(void)
{
  return kanan[xb][yb-1]-kanan[xb][ya-1]-kanan[xa-1][yb-1]+kanan[xa-1][ya-1];
}

int D(void)
{
  return bawah[xb-1][yb]-bawah[xb-1][ya-1]-bawah[xa-1][yb]+bawah[xa-1][ya-1];
}

int main()
{
  scanf("%d %d",&r,&c);
  REPN(i,r) 
  {
    data[i] = GetString();
    data[i] = '.' + data[i];
  }
  REPN(i,r) REPN(j,c-1)
  {
    kanan[i][j] = (data[i][j] == '.' && data[i][j+1] == '.' ? 1 : 0);
  }
  REPN(i,r) REPN(j,c-1)
  {
    kanan[i][j] += ((i==0?0:kanan[i-1][j]) + (j==0?0:kanan[i][j-1]) - kanan[i-1][j-1]);
  }
  REPN(i,r-1) REPN(j,c)
  {
    bawah[i][j] = (data[i][j] == '.' && data[i+1][j] == '.' ? 1 : 0);
  }
  REPN(i,r-1) REPN(j,c)
  {
    bawah[i][j] += ((i==0?0:bawah[i-1][j]) + (j==0?0:bawah[i][j-1]) - bawah[i-1][j-1]);
  }
  /*REP(i,r) 
  {
    REP(j,c) printf("%d",bawah[i][j]);
    puts("");
  }*/
  scanf("%d",&q);
  TC(q)
  {
    scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
    //--xa; --ya; --xb; --yb;
    //VALUE(D());
    //VALUE(R());
    printf("%d\n",D() + R());
  }
  return 0;
}