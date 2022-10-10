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

int u,v,p;
vector<pair<vi,int>> satu, dua;
unordered_map<int,int> bisa[205];
vi risan;

LL bigmod(int a,int b,int m)
{
  if (b == 1) return a;
  LL tmp = bigmod(a,b/2,m);
  LL tmp2 = tmp * tmp % m;
  if (b % 2 == 0) return tmp2;
  return tmp2 * a % m;
}

void dfs(int now, int rem, vector<int> steps, int x)
{
  steps.pb(now);
  if (x == 0) satu.pb(mp(steps,rem));
  else dua.pb(mp(steps,rem));
  if (SIZE(steps) == 3) return;
  FORN(i,1,rem-1) for (int j : {-1, 1})
  {
    int nxt = (now + i * j) % p;
    if (nxt < 0) nxt += p;
    dfs(bigmod(nxt,p-2,p),rem-i-1,steps,x);
  }
}

int normalized(int x)
{
  return (x % p + p) % p;
}

int jarak(int a,int b)
{
  int dist = abs(b - a);
  return min(dist, p - dist);
}

void go(int now,int nxt)
{
  if ((nxt - now + p) % p < (now - nxt + p) % p)
  {
    while (now != nxt)
    {
      risan.pb(1);
      now = normalized(now + 1);
    }
  } else 
  {
    while (now != nxt)
    {
      risan.pb(2);
      now = normalized(now - 1);
    }
  }
  // risan.pb(3);
}

int main()
{
  scanf("%d %d %d",&u,&v,&p);
  // VALUE(bigmod(1000,p-2,p));
  dfs(u,100,{},0);
  // DEBUG;
  dfs(v,100,{},1);
  // DEBUG;
  VALUE(SIZE(satu));
  VALUE(SIZE(dua));
  REP(i,SIZE(dua))
  {
    int last = dua[i].fi[SIZE(dua[i].fi)-1];
    int rem = dua[i].se;
    FORN(j,-rem,rem)
    {
      bisa[0][normalized(last + j)] = i;
    }
    FORN(j,1,100)
    {
      bisa[j][normalized(last - rem - j)] = i;
      bisa[j][normalized(last + rem + j)] = i;
    }
  }
  // FORN(j,1,100)
  // {
  //   VALUE(SIZE(bisa[j]));
  //   for (pair<int,int> tmp : bisa[j])
  //   {
  //     FORN(k,j+1,j+1) bisa[k][tmp.fi] = tmp.se;
  //   }
  // }
  DEBUG;
  REP(i,SIZE(satu))
  {
    // VALUE(i);
    int last = satu[i].fi[SIZE(satu[i].fi)-1];
    int rem_ori = satu[i].se;
    // VALUE(i);
    FORN(rem,0,rem_ori) {
      if (bisa[rem].count(last))
      {
        VALUE(i);
        int ix = bisa[rem][last];

        REP(j,SIZE(satu[i].fi)-1)
        {
          int now = satu[i].fi[j];
          int nxt = bigmod(satu[i].fi[j+1],p-2,p);
          go(now,nxt);
          risan.pb(3);
        }

        int now = satu[i].fi[SIZE(satu[i].fi) - 1];
        int nxt = dua[ix].fi[SIZE(dua[ix].fi) - 1];
        go(now,nxt);

        FORD(j,SIZE(dua[ix].fi)-1,1)
        {
          risan.pb(3);
          int now = bigmod(dua[ix].fi[j],p-2,p);
          int nxt = dua[ix].fi[j-1];
          go(now,nxt);
        }


        // vi gabungan;
        // REP(j,SIZE(satu[i].fi)) gabungan.pb(satu[i].fi[j]);
        // #ifdef TESTING
        // gabungan.pb(-1);
        // #endif
        // FORD(j,SIZE(dua[ix].fi)-1,0) gabungan.pb(dua[ix].fi[j]);

        // REP(j,SIZE(gabungan)) debug("%d\n",gabungan[j]);

        // vi risan;
        // FOR(i,0,SIZE(gabungan)-1)
        // {
        //   int now = gabungan[i];
        //   int nxt = gabungan[i+1];
        //   int nxt_inv = bigmod(nxt,p-2,p);

        //   int majunxt = (nxt - now + p) % p;
        //   int mundurnxt = (now - nxt + p) % p;

        //   int majunxt_inv = (nxt_inv - now + p) % p + 1;
        //   int mundurnxt_inv = (now - nxt_inv + p) % p + 1;

        //   int dekat = min(min(majunxt,mundurnxt),min(majunxt_inv,mundurnxt_inv));

        //   VALUE(dekat);

        //   if (dekat == majunxt)
        //   {
        //     while (now != nxt)
        //     {
        //       risan.pb(1);
        //       now = normalized(now + 1);
        //     }
        //   } else if (dekat == mundurnxt)
        //   {
        //     while (now != nxt)
        //     {
        //       risan.pb(2);
        //       now = normalized(now - 1);
        //     }
        //   } else if (dekat == majunxt_inv)
        //   {
        //     while (now != nxt_inv)
        //     {
        //       risan.pb(1);
        //       now = normalized(now + 1);
        //     }
        //     risan.pb(3);
        //   } else 
        //   {
        //     while (now != nxt_inv)
        //     {
        //       risan.pb(2);
        //       now = normalized(now - 1);
        //     }
        //     risan.pb(3);
        //   }
        //   // risan.pb(-1);
        // }
        printf("%d\n",SIZE(risan));
        REP(i,SIZE(risan)) printf("%d ",risan[i]);
        // REP(j,SIZE(satu[i].fi)) debug("%d ",satu[i].fi[j]);
        // DEBUG;
        // REP(j,SIZE(dua[ix].fi)) debug("%d ",dua[ix].fi[j]);
        puts("");
        return 0;
      }
    }
  }
  return 0;
}