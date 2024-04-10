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

#define MAXN 10000000

bool pr[MAXN+5];
int prima[MAXN+5];
int primake[MAXN+5];
int ada[MAXN + 5];
int data1[MAXN + 5];
int data2[MAXN + 5];
int primes = 0;
int n,m,a;
vi risan1,risan2;
int ans1,ans2;

inline void GeneratePrime(int a) {
    int tengah = (int)sqrt(a);
    RESET(pr,1);
    pr[0] = pr[1] = 0;
    FORN(i,2,a) if(pr[i]) {
        primake[i] = primake[i-1] + 1;
        if (i <= tengah) prima[++primes] = i;
        if (i > tengah) continue;
        //if (i >= 10000) continue;
        int ix = i * i;
        while (ix <= a) {
            pr[ix] = 0;
            ix += i;
        }
    } else primake[i] = primake[i-1];
}

int main()
{
	GeneratePrime(MAXN);
	VALUE(primake[4597]);
	//REPN(i,primes) VALUE(prima[i]);
	scanf("%d %d",&n,&m);
	REP(i,n)
	{
		scanf("%d",&a);
		data1[i] = a;
		FORN(i,1,primes)
		{
			if (pr[a])
			{
				++ada[primake[a]];
				break;
			}
			while (a % prima[i] == 0)
			{
				++ada[i];
				a /= prima[i];
			}
			if (a == 1) break;
		}
	}
	REP(i,m)
	{
		scanf("%d",&a);
		data2[i] = a;
		FORN(i,1,primes)
		{
			if (pr[a])
			{
				--ada[primake[a]];
				break;
			}
			while (a % prima[i] == 0)
			{
				--ada[i];
				a /= prima[i];
			}
			if (a == 1) break;
		}
	}
	//REPN(i,10) debug("%d %d\n",prima[i],ada[i]);
	ans1 = ans2 = 1;
	REP(i,n)
	{
		int a = data1[i];
		int res = 1;
		FORN(i,1,primes)
		{
			if (pr[a])
			{
				if (ada[primake[a]] > 0)
				{
					res *= a;
					--ada[primake[a]];
				}
				break;
			}
			while (a % prima[i] == 0)
			{
				if (ada[i] <= 0)
				{
					while (a % prima[i] == 0) a /= prima[i];
					break;
				}
				--ada[i];
				a /= prima[i];
				res *= prima[i];
			}
			if (a == 1) break;
		}
		risan1.pb(res);
	}
	REP(i,m)
	{
		int a = data2[i];
		int res = 1;
		FORN(i,1,primes)
		{
			if (pr[a])
			{
				if (ada[primake[a]] < 0)
				{
					res *= a;
					++ada[primake[a]];
				}
				break;
			}
			while (a % prima[i] == 0)
			{
				if (ada[i] >= 0)
				{
					while (a % prima[i] == 0) a /= prima[i];
					break;
				}
				++ada[i];
				a /= prima[i];
				res *= prima[i];
			}
			if (a == 1) break;
		}
		risan2.pb(res);
	}
	if (ans1 > 1 || SIZE(risan1) == 0) risan1.pb(1);
	if (ans2 > 1 || SIZE(risan2) == 0) risan2.pb(1);
	int A = SIZE(risan1), B = SIZE(risan2);
	printf("%d %d\n",A,B);
	REP(i,A) printf("%d ",risan1[i]);
	puts("");
	REP(i,B) printf("%d ",risan2[i]);
	puts("");
	return 0;
}