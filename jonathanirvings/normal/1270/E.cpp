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
pii data[1005];
LL dist[1005][1005];
int warna[1005];
pair<LL,int> d[1005];

LL dist2(int x,int y)
{
  return (SQR(data[x].fi - data[y].fi) + SQR(data[x].se - data[y].se));
}

void bf()
{
  FOR(mask,1,1<<n) if (__builtin_popcount(mask) != n)
  {
    set<LL> sama, beda;
    vector<int> bit;
    REP(i,n) bit.pb((mask & (1 << i)) ? 1 : 0);
    REP(i,n) REP(j,n)
    {
      if (bit[i] ^ bit[j]) sama.insert(dist[i][j]);
      else beda.insert(dist[i][j]);
    }
    for (LL s : sama) if (beda.count(s)) goto gabisa;
    REP(i,n) printf("%d",bit[i]); puts("");
    gabisa:;
  }
}

void cek()
{
  set<LL> sama, beda;
  REP(i,n) REP(j,n)
  {
    if (warna[i] == warna[j]) sama.insert(dist[i][j]);
    else beda.insert(dist[i][j]);
  }
  assert(SIZE(beda) > 0);
  // for (LL s : sama) if (beda.count(s)) VALUE(s);
  for (LL s : sama) assert(beda.count(s) == 0);
}

LL GCD(LL a,LL b)
{
  if (b == 0) return a;
  return GCD(b,a%b);
}

int main()
{
  scanf("%d",&n);
  REP(i,n) scanf("%d %d",&data[i].fi,&data[i].se);
  REP(i,n) REP(j,n) dist[i][j] = dist2(i,j);
  
  LL g = dist[0][1];
  REP(i,n) REP(j,n) if (i != j) g = GCD(g,dist[i][j]);
  
  RESET(warna,-1);
  REP(i,n)
  {
     warna[i] = (dist[0][i] / g) % 2;
  }
  
  // REP(i,n) d[i] = mp(INFF,-1);
  

  // int now = 0; warna[0] = 0; d[0] = mp(0,-1);
  // REP(i,n)
  // {
  //   REP(j,n) MIN(d[j],mp(dist[now][j],now));
  //   int nxt = -1;
  //   REP(j,n) if (warna[j] == -1)
  //   {
  //     if (nxt == -1 || d[j] < d[nxt]) nxt = j;
  //   }
  //   warna[nxt] = 1 - warna[d[nxt].se];
  //   now = nxt;
  //   // VALUE(i);
  // }
  int risan = 0;
  REP(i,n) if (warna[i]) ++risan;
  printf("%d\n",risan);
  REP(i,n) if (warna[i]) printf("%d ",i+1); puts("");

  // cek();
  // bf();
  // vi perm(n); iota(ALL(perm),0); random_shuffle(ALL(perm));
  // for (int a : perm)
  // {
  //   vi perm2(n); iota(ALL(perm2),0); random_shuffle(ALL(perm2));
  //   for (int b : perm2) if (a != b)
  //   {
  //     REP(i,n) warna[i] = 0;
  //     vi A(n); iota(ALL(A),0);
  //     vi B;


  //     queue<int> ganti;
  //     ganti.push(b);
  //     REP(i,n)
  //     {
  //       if (ganti.empty())
  //       {
  //         int risan = 0;
  //         REP(i,n) if (warna[i] == 0) ++risan;
  //         printf("%d\n",risan);
  //         REP(i,n) if (warna[i] == 0) printf("%d ",i+1);
  //         puts("");
  //         exit(0);
  //       }

  //     }
  //   }
  // }
  return 0;
}