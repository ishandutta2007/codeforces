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

int prop[4000005];
int tree[4000005];
int n;
int p[300005];
int q[300005];
int pos[300005];
int risan;

void push(int ix,int L,int R)
{
  prop[ix*2+1] += prop[ix];
  prop[ix*2+2] += prop[ix];
  tree[ix*2+1] += prop[ix];
  tree[ix*2+2] += prop[ix];
  prop[ix] = 0;
}

void update(int ix,int L,int R,int x,int y,int v)
{
  if (x <= L && R <= y)
  {
    prop[ix] += v;
    tree[ix] += v;
    return;
  }
  if (R < x || y < L) return;
  push(ix,L,R);
  int M = (L + R) >> 1;
  update(ix*2+1,L,M,x,y,v);
  update(ix*2+2,M+1,R,x,y,v);
  tree[ix] = min(tree[ix*2+1],tree[ix*2+2]);
}

int query(int ix,int L,int R,int x,int y)
{
  if (x <= L && R <= y) return tree[ix];
  if (R < x || y < L) return INF;
  push(ix,L,R);
  int M = (L + R) >> 1;
  return min(query(ix*2+1,L,M,x,y),query(ix*2+2,M+1,R,x,y));
}

void update(int x,int v)
{
  update(0,0,n-1,0,x,v);
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
  risan = n - 1;
  update(pos[risan],-1);
  REP(i,n)
  {
    printf("%d ",risan+1);
    scanf("%d",&q[i]);
    --q[i];
    update(q[i],1);
    while (1)
    {
      if (query(0,0,n-1,0,n-1) >= 0)
      {
        --risan;
        update(pos[risan],-1);
      } else break;
    }
  }
  puts("");
  return 0;
}