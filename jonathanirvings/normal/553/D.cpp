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

int n,m,k;
vi adj[100005];
bool blok[100005];
int a,b,c;
vi risan;
bool ambil[100005];
int hitung[100005];
double haha[100005];

void bisa(double cek, vector<int> &v)
{
  priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
  REP(i,n) if(!blok[i]) ambil[i] = 1;
  REP(i,n) if(ambil[i])
  {
    hitung[i] = 0;
    REP(j,SIZE(adj[i])) if(ambil[adj[i][j]]) ++hitung[i];
    haha[i] = (double)hitung[i] / (double)SIZE(adj[i]);
    pq.push(mp(haha[i],i));
  }
  while (!pq.empty())
  {
    double cost = pq.top().fi;
    int now = pq.top().se;
    pq.pop();
    if (haha[now] != cost) continue;
    if (cost >= cek) break;
    ambil[now] = 0;
    REP(i,SIZE(adj[now])) if(ambil[adj[now][i]])
    {
      int x = adj[now][i];
      --hitung[x];
      haha[x] = (double)hitung[x] / (double)SIZE(adj[x]);
      pq.push(mp(haha[x],x));
    }
  }
  REP(i,n) if(ambil[i]) v.pb(i);
}

int main()
{
  scanf("%d %d %d",&n,&m,&k);
  REP(i,k)
  {
    scanf("%d",&a);
    blok[--a] = 1;
  }
  TC(m)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  double L = -1;
  double R = 1;
  FORN(i,1,60)
  {
    double M = (L + R) / 2;
    vi temp;
    bisa(M,temp);
    if (SIZE(temp) > 0)
    {
      L = M;
      risan = temp;
    } else R = M;
  }
  printf("%d\n",SIZE(risan));
  REP(i,SIZE(risan)) printf("%d ",risan[i]+1);
  puts("");
  return 0;
}