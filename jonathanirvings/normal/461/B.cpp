//Codeforces Round #263
//26 Aug 2014

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

int MOD = 1000000007;
int n,a,b,warna[100005];
int parent[100005];
vi adj[100005];
LL dp[100005][2];
bool leaf[100005];

void dfs(int now,int par)
{
	REP(i,SIZE(adj[now])) if(adj[now][i] != par)
	{
		leaf[now] = false;
		parent[adj[now][i]] = now;
		dfs(adj[now][i],now);
	}
}

inline LL bigmod(LL a, LL b)
{
	LL x=1,y=a; 
	while(b > 0)
	{
		if(b % 2 == 1)
			x = (x * y) % MOD;
		y = (y * y) % MOD;
		b /= 2;
	}
	return x;
}

inline LL inverse(LL n) {return bigmod(n,MOD-2);}

LL jahja(int now,int color)
{
	LL &ret = dp[now][color];
	if (ret >= 0) return ret;
	ret = 0;
	if (leaf[now] && color == warna[now]) return (ret = 1);
	if (warna[now] == 1)
	{
		LL temp = 1;
		REP(i,SIZE(adj[now])) if(adj[now][i] != parent[now])
			temp = (temp * jahja(adj[now][i],0)) % MOD;
		ret = (ret + temp) % MOD;
		return ret;
	}
	if (color == 0 && warna[now] == 0) 
		ret = (ret + jahja(now,1)) % MOD;
	if (color == 0)
	{
		LL temp = 1;
		REP(i,SIZE(adj[now])) if(adj[now][i] != parent[now])
			temp = (temp * jahja(adj[now][i],0)) % MOD;
		ret = (ret + temp) % MOD;
	} else
	{
		LL kali = 1;
		REP(i,SIZE(adj[now])) if(adj[now][i] != parent[now])
		{
			kali = (kali * jahja(adj[now][i],0)) % MOD;
		}
		REP(i,SIZE(adj[now])) if(adj[now][i] != parent[now])
		{
			LL temp = (kali * inverse(jahja(adj[now][i],0))) % MOD;
			temp = (temp * jahja(adj[now][i],1)) % MOD;
			ret = (ret + temp) % MOD;
		}
		/*REP(i,SIZE(adj[now])) if(adj[now][i] != parent[now])
		{
			LL temp = 1;
			REP(j,SIZE(adj[now])) if(adj[now][j] != parent[now])
			{
				if (i != j) temp = (temp * jahja(adj[now][j],0)) % MOD;
				else temp = (temp * jahja(adj[now][j],1)) % MOD;
			}
			ret = (ret + temp) % MOD;
		}*/
	}
	//printf("%d %d %lld\n",now,color,ret);
	return ret;
}

int main()
{
	scanf("%d",&n);
	REP(i,n-1)
	{
		scanf("%d",&a);
		adj[a].pb(i+1);
		adj[i+1].pb(a);
	}
	REP(i,n) scanf("%d",&warna[i]);
	RESET(dp,-1);
	RESET(leaf,1);
	RESET(parent,-1);
	dfs(0,-1);
	LL risan = jahja(0,1);
	cout << risan << endl;
	return 0;
}