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
vi adj[300005];
int parent[300005];
int a,b;
int kecil[300005];
int nim[300005];
vi pos[300005];

void dfs(int u)
{
  for (int v : adj[u])
  {
    if (v == parent[u]) continue;
    parent[v] = u;
    dfs(v);
  }
}

int main()
{
  scanf("%d",&n);
  REP(i,n-1)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  parent[0] = -1;
  dfs(0);
  RESET(kecil,-1);
  kecil[0] = 0;
  FOR(i,1,n)
  {
    int u = i;
    while (kecil[u] == -1)
    {
      kecil[u] = i;
      pos[i].pb(u);
      u = parent[u];
    }
  }
  string risan = "";
  int now = 0;
  int sisa = n - 1;
  FORD(i,n-1,0)
  {
    if ((now ^ (sisa % 2)) > 0) risan += '1';
    else risan += '2';
    if (i > 0)
    {
      for (int u : pos[i])
      {
        --sisa;
        now ^= nim[u];
        int pt = parent[u];
        now ^= nim[pt];
        nim[pt] = 0;
        for (int v : adj[pt]) if (v != parent[pt] && kecil[v] >= i)
        {
          nim[pt] ^= (nim[v] + 1);
        }
        now ^= nim[pt];
      }
    }
    // REP(i,n) debug("%d %d\n",i,nim[i]);
    // VALUE(now);
    // VALUE(sisa);
  }
  REVERSE(risan);
  printf("%s\n",risan.c_str());

  return 0;
}