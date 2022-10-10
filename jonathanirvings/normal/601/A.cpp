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

//end of jonathanirvings' template v3.0.0 (BETA)

int n,m;
int a,b,x,y;
queue<pair<pii,pii> > q;
bool sudah[405][405][2];
int bisa[405][405];

int main()
{
  scanf("%d %d",&n,&m);
  REPN(i,n) bisa[i][i] = -1;
  TC(m)
  {
    scanf("%d %d",&x,&y);
    bisa[x][y] = 1;
    bisa[y][x] = 1;
  }
  q.push(mp(mp(1,1),mp(0,0)));
  sudah[1][1][0] = 1;
  while (!q.empty())
  {
    pii now = q.front().fi;
    int state = q.front().se.fi;
    int steps = q.front().se.se;
    q.pop();
    //printf("%d %d %d %d\n",now.fi,now.se,state,steps);
    if (state == 0 && now == mp(n,n))
    {
      printf("%d\n",steps);
      return 0;
    }
    if (state == 0)
    {
      if (now.fi == now.se && now.fi != 1) continue;
      REPN(i,n) if(bisa[now.fi][i] == 1 || (i == n && now.fi == n))
      {
        if (sudah[i][now.se][1]) continue;
        sudah[i][now.se][1] = 1;
        q.push(mp(mp(i,now.se),mp(1,steps))); 
      }
    } else if (state == 1)
    {
      REPN(i,n) if(bisa[now.se][i] == 0 || (i == n && now.se == n))
      {
        if (sudah[now.fi][i][0]) continue;
        sudah[now.fi][i][0] = 1;
        q.push(mp(mp(now.fi,i),mp(0,steps+1)));
      }
    }
  }
  puts("-1");
  return 0;
}