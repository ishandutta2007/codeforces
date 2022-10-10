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
//int INF = 1000000005;
int INF = 1000001;
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

struct Node {
  int merge;
  int val[5][5];
};

Node tree[800005];
string s;
int n,q;
int a,b;

Node merge(Node a, Node b)
{
  Node c;
  if (!a.merge) return b;
  if (!b.merge) return a;
  c.merge = 1;
  FORN(i,0,4)
  {
    c.val[i][i] = a.val[i][i] + b.val[i][i];
    FORN(j,i+1,4)
    {
      c.val[i][j] = INF;
      FORN(k,i,j) MIN(c.val[i][j],a.val[i][k] + b.val[k][j]);
    }
  }
  return c;
}

Node nul()
{
  Node ret;
  ret.merge = 0;
  return ret;
}

Node init(int x)
{
  Node ret;
  ret.merge = 1;
  FORN(i,0,4) FORN(j,i+2,4) ret.val[i][j] = INF;
  ret.val[0][0] = (s[x] != '2' ? 0 : 1);
  ret.val[0][1] = (s[x] == '2' ? 0 : INF);
  ret.val[1][1] = (s[x] != '0' ? 0 : 1);
  ret.val[1][2] = (s[x] == '0' ? 0 : INF);
  ret.val[2][2] = (s[x] != '1' ? 0 : 1);
  ret.val[2][3] = (s[x] == '1' ? 0 : INF);
  ret.val[3][3] = (s[x] != '7' && s[x] != '6' ? 0 : 1);
  ret.val[3][4] = (s[x] == '7' ? 0 : INF);
  ret.val[4][4] = (s[x] != '6' ? 0 : 1);
  return ret;
}

void build(int ix,int L,int R)
{
  if (L == R)
  {
    tree[ix] = init(L);
    return;
  }
  int M = (L + R) >> 1;
  build(ix*2+1,L,M);
  build(ix*2+2,M+1,R);
  tree[ix] = merge(tree[ix*2+1],tree[ix*2+2]);
}

Node query(int ix,int L,int R,int x,int y)
{
  if (x <= L && R <= y) return tree[ix];
  if (R < x || y < L) return nul();
  int M = (L + R) >> 1;
  return merge(query(ix*2+1,L,M,x,y),query(ix*2+2,M+1,R,x,y));
}

int main()
{
  scanf("%d %d",&n,&q);
  s = GetString();
  build(0,0,n-1);
  TC(q)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    Node risan = query(0,0,n-1,a,b);
    if (risan.val[0][4] >= INF) puts("-1");
    else printf("%d\n",risan.val[0][4]);
  }
  return 0;
}