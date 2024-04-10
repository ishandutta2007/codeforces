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

struct isi
{
  int pos;
  int h;
  LL jum;
};

int n;
string S;
int kanan[500005];
stack<isi> s;

LL tambah(int x, int h, isi l)
{
  LL naik = (LL)(l.h - h - 1) * (l.h + h) / 2;
  LL sisa = (LL)h * ((l.pos - x + 1) - (l.h - h));
  return naik + sisa;
}

void printstack()
{
  stack<isi> q;
  while (!s.empty())
  {
    printf("%d %d %lld\n",s.top().pos,s.top().h,s.top().jum);
    q.push(s.top());
    s.pop();
  }
  while (!q.empty())
  {
    s.push(q.top());
    q.pop();
  }
}

int main()
{
  scanf("%d",&n);
  S = GetString();
  FORD(i,n-1,0)
  {
    kanan[i] = (i == n - 1 ? 0 : kanan[i + 1]);
    if (S[i] == '0') kanan[i] = 0;
    else ++kanan[i];
  }
  LL risan = 0;
  FORD(i,n-1,0)
  {
    while (SIZE(s) > 0)
    {
      if (s.top().h <= kanan[i]) s.pop();
      else break;
    }
    if (kanan[i] > 0)
    {
      int x = i + kanan[i] - 1;
      LL cost = 0;
      if (SIZE(s) > 0)
      {
        cost = tambah(x,kanan[i],s.top()) + s.top().jum;
      } else 
      {
        cost = (LL)(n - x) * kanan[i];
      }
      s.push({x,kanan[i],cost});
    }

    if (SIZE(s) > 0)
    {
      risan += tambah(i,S[i] - '0',s.top()) + s.top().jum;
    }
    // debug("%d %lld\n",i,SIZE(s) == 0 ? 0 : tambah(i,S[i] - '0',s.top()) + s.top().jum);
    // printstack();
  }
  printf("%lld\n",risan);
  return 0;
}