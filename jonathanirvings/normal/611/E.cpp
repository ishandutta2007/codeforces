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
LL kuat[3];
multiset<LL> data;
LL x;
int risan = 0;

void print()
{
  for (multiset<LL>::iterator it=data.begin();it!=data.end();++it)
  {
    printf("%lld ",*it);
  }
  puts("");
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin >> n;
  REP(i,3) cin >> kuat[i];
  REP(i,n)
  {
    cin >> x;
    data.insert(x);
  }
  SORTA(kuat,3);
  while (!data.empty())
  {
    //print();
    ++risan;
    multiset<LL>::iterator it = data.end();
    --it;
    if (*it > kuat[0] + kuat[1] + kuat[2])
    {
      puts("-1");
      return 0;
    }

    if (kuat[2] >= *it)
    {
      data.erase(it);
      if (SIZE(data) == 0) continue;
      multiset<LL>::iterator it2 = data.upper_bound(kuat[1]);
      if (it2 == data.begin())
      {
        it2 = data.upper_bound(kuat[0] + kuat[1]);
        if (it2 == data.begin()) continue;
        --it2;
        data.erase(it2);
      } else 
      {
        --it2;
        multiset<LL>::iterator it3 = data.upper_bound(kuat[0]);
        if (it3 == data.begin())
        {
          it2 = data.upper_bound(kuat[0] + kuat[1]);
          if (it2 == data.begin()) continue;
          --it2;
          data.erase(it2);
          continue;
        }
        --it3;
        if (it3 == it2)
        {
          if (it3 == data.begin())
          {
            it2 = data.upper_bound(kuat[0] + kuat[1]);
            if (it2 == data.begin()) continue;
            --it2;
            data.erase(it2);
          } else 
          {
            --it3;
            data.erase(it2);
            data.erase(it3);
          }
        } else 
        {
          data.erase(it2);
          data.erase(it3);
        }
      }
    } else if (kuat[0] + kuat[1] >= *it)
    {
      data.erase(it);
      if (SIZE(data) == 0) continue;
      multiset<LL>::iterator it2 = data.upper_bound(kuat[2]);
      if (it2 == data.begin()) continue;
      --it2;
      data.erase(it2);
    } else if (kuat[0] + kuat[2] >= *it)
    {
      data.erase(it);
      if (SIZE(data) == 0) continue;
      multiset<LL>::iterator it2 = data.upper_bound(kuat[1]);
      if (it2 == data.begin()) continue;
      --it2;
      data.erase(it2);
    } else if (kuat[1] + kuat[2] >= *it)
    {
      data.erase(it);
      if (SIZE(data) == 0) continue;
      multiset<LL>::iterator it2 = data.upper_bound(kuat[0]);
      if (it2 == data.begin()) continue;
      --it2;
      data.erase(it2);
    } else 
    {
      data.erase(it);
    }
  }
  cout << risan << endl;
  return 0;
}