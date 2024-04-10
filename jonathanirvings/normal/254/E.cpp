//Codeforces Round #155 (Div. 2)
//9 Dec 2012

//start of jonathanirvings' template v2.0.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
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
jonathan ganteng banget;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
	#define DEBUG fprintf(stderr,"====TESTING====\n")
	#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
	#define debug(...) fprintf(stderr, __VA_ARGS__)
inline void OPEN () {}
#else
	#define DEBUG 
	#define VALUE(x)
	#define debug(...)
inline void OPEN () 
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
}
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
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
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
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

//end of jonathanirvings' template v2.0.0 (BETA)

int n,m,v,a,b,c;
int data[405];
vector<pii> teman[405];
int dp[405][405];
int risan;

int hitung(int bef,int now,int used)
{
	if (bef + now < used) return -1;
	if (used >= bef) return (bef + now - used);
	return now;
}

int jahja(int now,int rem)
{
	if (rem < 0) return -INF;
	if (now == n) return 0;
	int &ret = dp[now][rem];
	if (ret > -1) return ret;
	int used = v;
	int sz = SIZE(teman[now]);
	ret = jahja(now + 1,hitung(rem,data[now],used));
	REP(i,sz)
	{
		used += teman[now][i].fi;
		MAX(ret,jahja(now + 1,hitung(rem,data[now],used)) + i + 1);
	}
	return ret;
}

void back(int now,int rem)
{
	//debug("%d %d\n",now,rem);
	if (rem < 0) return;
	if (now == n) return;
	int ret = dp[now][rem];
	int used = v;
	int sz = SIZE(teman[now]);
	if (ret == jahja(now + 1,hitung(rem,data[now],used)))
	{
		puts("0");
		back(now + 1,hitung(rem,data[now],used));
		return;
	} 
	REP(i,sz)
	{
		used += teman[now][i].fi;
		if (ret == jahja(now + 1,hitung(rem,data[now],used)) + i + 1)
		{
			printf("%d",i+1);
			FORN(j,0,i) printf(" %d",teman[now][j].se);
			puts("");
			back(now + 1,hitung(rem,data[now],used));
			return;
		}
	}
	return;
}

int main()
{
	OPEN();
	scanf("%d %d",&n,&v);
	REP(i,n) scanf("%d",&data[i]);
	scanf("%d",&m);
	REP(i,m)
	{
		scanf("%d %d %d",&a,&b,&c); --a; --b;
		FORN(j,a,b) teman[j].pb(mp(c,i+1));
	}
	REP(i,n) SORT(teman[i]);
	RESET(dp,-1);
	risan = jahja(0,0);
	printf("%d\n",risan);
	back(0,0);
	return 0;
}