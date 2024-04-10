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
#else
	#define DEBUG 
	#define VALUE(x)
	#define debug(...)
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

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v2.0.0 (BETA)

string type;
int n,m,a,b;
string s,t;
string kata;
vi adj[400];
int sudah[405];
int gagal[405];
vi implies[400];
vi harus;
int C,V;
int ada[405];

int neg(int x)
{
	return (x < n ? x + n : x - n);
}

void dfs(int st,int x)
{
	implies[st].pb(x);
	REP(i,SIZE(adj[x]))
	{
		if (sudah[adj[x][i]]) continue;
		sudah[adj[x][i]] = 1;
		if (sudah[neg(adj[x][i])]) gagal[st] = 1;
		dfs(st,adj[x][i]);
	}
}

pair<bool,string> bisa(int now,int udahbeda)
{
	//debug("%d %d\n",now,udahbeda);
	//REP(i,SIZE(harus)) printf("%2d",harus[i]);
	//puts("");
	if (now == n) return mp(1,"");
	int start = (udahbeda == 0 ? kata[now] - 'a' : 0);
	//debug("%d\n",start);
	FOR(i,start,SIZE(type))
	{
		if (harus[now] == 0 && type[i] == 'C') continue;
		if (harus[now] == 1 && type[i] == 'V') continue;
		int x = type[i] == 'C' ? now + n : now;
		//debug("%d\n",x);
		if (gagal[x]) continue;
		vi harustemp = harus;
		pair<bool,string> nxt; 
		REP(j,SIZE(implies[x]))
		{
			int y = implies[x][j];
			if (y < n)
			{
				if (harus[y] == 1) goto gabisa;
				harus[y] = 0;
			} else 
			{
				y -= n;
				if (harus[y] == 0) goto gabisa;
				harus[y] = 1;
			}
		}
		harus[now] = (type[i] == 'C' ? 1 : 0);
		REP(j,n)
		{
			if (harus[j] == 0 && gagal[j]) goto gabisa;
			if (harus[j] == 1 && gagal[neg(j)]) goto gabisa;
		}
		nxt = bisa(now+1,udahbeda==1?1:(i==start?0:1));
		if (nxt.first == 1) 
		{
			//debug("%d %d %d\n",now,udahbeda,i);
			return mp(1,(char)(i + 'a') + nxt.second);
		}
		gabisa:;
		harus = harustemp;
	}
	return mp(0,"");
}

int main()
{
	type = GetString();
	REP(i,SIZE(type))
	{
		if (type[i] == 'C') ++C;
		else ++V;
	}
	scanf("%d %d",&n,&m);
	TC(m)
	{
		scanf("%d",&a);
		s = GetString();
		scanf("%d",&b);
		t = GetString();
		--a; --b;
		if (s[0] == 'C') a += n;
		if (t[0] == 'C') b += n;
		adj[a].pb(b);
		adj[neg(b)].pb(neg(a));
	}
	kata = GetString();
	REP(i,2*n)
	{
		RESET(sudah,0);
		sudah[i] = 1;
		gagal[i] = 0;
		dfs(i,i);
		//REP(j,SIZE(implies[i])) printf("%d ",implies[i][j]);
		//puts("");
	}
	REP(i,n) 
	{
		if (gagal[i] && gagal[neg(i)]) {
			puts("-1");
			return 0;
		}
	}
	//debug("\n");
	REP(i,2*n) harus.pb(-1);
	if (C == 0)
	{
		REP(i,2*n) harus[i] = 0;
	}
	if (V == 0)
	{
		REP(i,2*n) harus[i] = 1;
	}
	REP(i,n)
	{
		RESET(ada,0);
		REP(j,SIZE(implies[i])) ada[implies[i][j]]++;
		REP(j,SIZE(implies[neg(i)])) ada[implies[neg(i)][j]]++;
		REP(j,2*n) if(ada[j] == 2)
		{
			if (j < n) 
			{
				if (harus[j] == 1)
				{
					puts("-1");
					return 0;
				}
				harus[j] = 0;
			}
			else {
				if (harus[j - n] == 0)
				{
					puts("-1");
					return 0;
				}
				harus[j - n] = 1;
			}
		}
	}
	pair<bool,string> risan = bisa(0,0);
	if (risan.fi == 0) puts("-1");
	else printf("%s\n",risan.se.c_str());
	return 0;
}