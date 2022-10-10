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

pair<pii,int> data[100005];
int n,m,budget;
pii bugs[100005];
priority_queue<pii> pq;
int sisa = 0;
int student = 0;
int risan = -1;
int answer[100005];

bool bisa(int x)
{
	sisa = 0;
	while (!pq.empty()) pq.pop();
	int L = 0;
	LL butuh = 0;
	REP(i,m)
	{
		while (L < n && data[L].fi.fi >= bugs[i].fi)
		{
			pq.push(mp(-data[L].fi.se,data[L].se));
			++L;
		}
		if (sisa == 0)
		{
			if (pq.empty()) return false;
			butuh += -pq.top().fi;
			student = pq.top().se;
			pq.pop();
			sisa = x-1;
			answer[bugs[i].se] = student;
		} else 
		{
			answer[bugs[i].se] = student;
			--sisa;
		}
	}
	return (butuh <= budget);
}

int main()
{
	scanf("%d %d %d",&n,&m,&budget);
	REP(i,m) 
	{
		scanf("%d",&bugs[i].fi);
		bugs[i].se = i;
	}
	SORTA(bugs,m);
	REVERSEA(bugs,m);
	REP(i,n)
	{
		data[i].se = i;
		scanf("%d",&data[i].fi.fi);
	}
	REP(i,n) scanf("%d",&data[i].fi.se);
	SORTA(data,n);
	REVERSEA(data,n);
	int L = 1;
	int R = m;
	while (L <= R)
	{
		int M = (L + R) >> 1;
		if (bisa(M))
		{
			risan = M;
			R = M - 1;
		} else L = M + 1;
	}
	bisa(risan);
	if (risan == -1) puts("NO");
	else
	{
		puts("YES");
		REP(i,m) printf("%d ",answer[i]+1);
		puts("");
	}
	return 0;
}