//Codeforces Round #149 (Div. 2)
//11 Nov 2012

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

LL jum[1000005];
int bit[1000005][35];
int prop[1000005];
int data[100005];
int n,q,a,b,c,d;

void build(int ix,int x,int y)
{
	if (x == y)
	{
		jum[ix] = data[x];
		REP(i,30) bit[ix][i] = ((data[x] & (1 << i)) ? 1 : 0);
		return;
	}
	int m = (x + y) >> 1;
	build(ix*2+1,x,m);
	build(ix*2+2,m+1,y);
	jum[ix] = jum[ix*2+1] + jum[ix*2+2];
	REP(i,30) bit[ix][i] = bit[ix*2+1][i] + bit[ix*2+2][i];
	return;
}

void update(int ix,int x,int y,int L,int R,int k)
{
	//printf("BEF %d %d %d %lld\n",ix,x,y,jum[ix]);
	//if (x == 1 && y == 2) printf("%d\n",ix);
	if (x >= L && y <= R)
	{
		prop[ix] ^= k;
	}
	int len = y - x + 1;
	REP(i,30)
	{
		if (prop[ix] & (1 << i))
		{
			jum[ix] -= ((LL)bit[ix][i] * (LL)(1 << i));
			jum[ix] += ((LL)(len - bit[ix][i]) * (LL)(1 << i));
			bit[ix][i] = len - bit[ix][i];
		}
	}
	int m = (x + y) >> 1;
	prop[ix*2+1] ^= prop[ix];
	prop[ix*2+2] ^= prop[ix];
	prop[ix] = 0;
	if (y < L || x > R) return;
	if (x >= L && y <= R)
		return;
	update(ix*2+1,x,m,L,R,k);
	update(ix*2+2,m+1,y,L,R,k);
	jum[ix] = jum[ix*2+1] + jum[ix*2+2];
	REP(i,30) bit[ix][i] = bit[ix*2+1][i] + bit[ix*2+2][i];
	//printf("%d %d %d %lld\n",ix,x,y,jum[ix]);
}

LL query(int ix,int x,int y,int L, int R)
{
	int len = y - x + 1;
	REP(i,30)
	{
		if (prop[ix] & (1 << i))
		{
			jum[ix] -= ((LL)bit[ix][i] * (LL)(1 << i));
			jum[ix] += ((LL)(len - bit[ix][i]) * (LL)(1 << i));
			bit[ix][i] = len - bit[ix][i];
		}
	}
	//printf("%d %d %d %lld\n",x,y,prop[ix],jum[ix]);
	prop[ix*2+1] ^= prop[ix];
	prop[ix*2+2] ^= prop[ix];
	prop[ix] = 0;
	if (y < L || x > R) return 0;
	if (x >= L && y <= R) return jum[ix];
	int m = (x + y) >> 1;
	LL res = query(ix*2+1,x,m,L,R) + query(ix*2+2,m+1,y,L,R);
	jum[ix] = jum[ix*2+1] + jum[ix*2+2];
	REP(i,30) bit[ix][i] = bit[ix*2+1][i] + bit[ix*2+2][i];
	prop[ix] = 0;
	return res;
}

int main()
{
	scanf("%d",&n);
	REP(i,n) scanf("%d",&data[i]);
	scanf("%d",&q);
	build(0,0,n-1);
	TC(q)
	{
		scanf("%d",&a);
		if (a == 1)
		{
			scanf("%d %d",&b,&c);
			LL risan = query(0,0,n-1,b-1,c-1);
			printf("%I64d\n",risan);
		} else
		{
			scanf("%d %d %d",&b,&c,&d);
			update(0,0,n-1,b-1,c-1,d);
		}
	}
	return 0;
}