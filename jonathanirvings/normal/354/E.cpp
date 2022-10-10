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

//end of jonathanirvings' template v2.0.0 (BETA)

int t;
string s;
int dp[25][10];
string ans[10];

int jahja(int x,int simpan)
{
	if (x == -1) return (simpan == 0 ? 1 : 0);
	int &ret = dp[x][simpan];
	if (ret >= 0) return ret;
	ret = 0;
	FORN(j,0,6) FORN(k,0,6-j) 
	{
		if ((simpan + 4 * j + 7 * k) % 10 == (s[x] - '0'))
		{
			//printf("======%d %d ==== %d %d\n",x,simpan,j,k);
			ret = ret || (jahja(x - 1, (simpan + 4 * j + 7 * k) / 10));
		}
	}
	//printf("%d %d\n",x,simpan);
	//VALUE(ret);
	return ret;
}

void back(int x,int simpan)
{
	if (x == -1) return;
	int ret = dp[x][simpan];
	//printf("%d %d\n",x,simpan);
	//VALUE(ret);
	FORN(j,0,6) FORN(k,0,6-j) 
	{
		if ((simpan + 4 * j + 7 * k) % 10 == (s[x] - '0'))
		{
			if (jahja(x-1,(simpan + 4 * j + 7 * k) / 10) == ret)
			{
				//printf("===%d %d %d %d\n",x,simpan,j,k);
				int i = 6 - j - k;
				int tmp = 0;
				//printf("%d\n",simpan + 4 * j + 7 * k);
				back(x - 1, (simpan + 4 * j + 7 * k) / 10);	
				TC(i) ans[tmp++] += '0';
				TC(j) ans[tmp++] += '4';
				TC(k) ans[tmp++] += '7';
				return;
			}
		}
	}
}

int main()
{
	scanf("%d",&t);
	TC(t)
	{
		s = GetString();
		RESET(dp,-1);
		int risan = jahja(SIZE(s) - 1,0);
		if (risan == 0) puts("-1");
		else
		{
			REP(i,6) ans[i] = "";
			back(SIZE(s)-1,0);
			REP(i,6) printf("%lld ",StringToInt(ans[i].c_str()));
			puts("");
		}
	}	
	return 0;
}