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

int n,k;
int data[4][55];
int data2[4][55];
vector<pair<int,pii>> risan;

void masuk()
{
  REP(j,n) if(data[1][j] > 0 && data[1][j] == data[0][j])
  {
    risan.pb(mp(data[1][j],mp(0,j)));
    data[1][j] = 0;
  }
  REP(j,n) if(data[2][j] > 0 && data[2][j] == data[3][j])
  {
    risan.pb(mp(data[2][j],mp(3,j)));
    data[2][j] = 0;
  }
}

vii urutan;

int main()
{
  scanf("%d %d",&n,&k);

  REP(i,n) urutan.pb(mp(1,i));
  FORD(i,n-1,0) urutan.pb(mp(2,i));
  REP(i,n) urutan.pb(mp(1,i));
  FORD(i,n-1,0) urutan.pb(mp(2,i));

  bool ok = 0;
  REP(i,4) REP(j,n)
  {
    scanf("%d",&data[i][j]);
  }
  masuk();
  if (k == n * 2 && SIZE(risan) == 0)
  {
    puts("-1");
    return 0;
  }
  FORN(tries,1,100)
  {
    // DEBUG;
    // REP(j,n) debug("%d ",data[1][j]); debug("\n");
    // REP(j,n) debug("%d ",data[2][j]); debug("\n");
    // DEBUG;
    masuk();
    FORN(i,1,2) REP(j,n) if(data[i][j] == 0)
    {
      int ix = 0;
      REP(l,SIZE(urutan)/2) if(urutan[l] == mp(i,j)) ix = l;
      REP(l,SIZE(urutan)/2)
      {
        masuk();
        int x = urutan[ix+l].fi;
        int y = urutan[ix+l].se;
        int xx = urutan[ix+l+1].fi;
        int yy = urutan[ix+l+1].se;
        if (data[xx][yy] > 0)
        {
          risan.pb(mp(data[xx][yy],mp(x,y)));
          data[x][y] = data[xx][yy];
          data[xx][yy] = 0;
        }
      }
      break;
    }
  }
  printf("%d\n",SIZE(risan));
  REP(i,SIZE(risan))
    printf("%d %d %d\n",risan[i].fi,risan[i].se.fi+1,risan[i].se.se+1);
  return 0;
}