//Codeforces Good Bye 2013
//30 Dec 2013

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

int K,X,N,M;
LL dp[55];
LL satu[55],dua[55];
LL satudua[55],duasatu[55],duadua[55];
string s = "ACF";
bool sudah[2][2][105][2][2][65][65];
string A,B;

void dfs(int done1,int done2)
{
	int first1 = (A[0] == 'C' ? 1 : 0);
	//int first1 = s.find(A[0]);
	int first2 = (B[0] == 'C' ? 1 : 0);
	//int first2 = s.find(B[0]);
	int now = max(SIZE(A),SIZE(B));
	int last1 = (A[SIZE(A)-1] == 'A' ? 0 : 1);
	//int last1 = s.find(A[SIZE(A)-1]);
	int last2 = (B[SIZE(B)-1] == 'A' ? 0 : 1);
	//int last2 = s.find(B[SIZE(B)-1]);
	if (sudah[first1][first2][now][last1][last2][done1][done2]) return;
	sudah[first1][first2][now][last1][last2][done1][done2] = 1;
	if (SIZE(A) == N && SIZE(B) == M)
	{
		LL res = satu[K] * done1 + dua[K] * done2;
		//VALUE(done1);
		//VALUE(done2);
		if (last2 == 0 && first2 == 1) res += duadua[K];
		if (last2 == 0 && first1 == 1) res += duasatu[K];
		if (last1 == 0 && first2 == 1) res += satudua[K];
		if (res == X)
		{
			printf("%s\n",A.c_str());
			printf("%s\n",B.c_str());
			exit(0);
		}
		return;
	}
	FORN(i,0,2) FORN(j,0,2)
	{
		int nxdone1 = done1;
		int nxdone2 = done2;
		bool changed1 = 0;
		bool changed2 = 0;
		if (SIZE(A) < N)
		{
			if (last1 == 0 && i == 1) ++nxdone1;
			A.pb(s[i]);
			changed1 = 1;
		}
		if (SIZE(B) < M)
		{
			if (last2 == 0 && j == 1) ++nxdone2;
			B.pb(s[j]);
			changed2 = 1;
		}
		dfs(nxdone1,nxdone2);
		if (changed1) A.erase(A.begin()+SIZE(A)-1);
		if (changed2) B.erase(B.begin()+SIZE(B)-1);
	}
}

int main()
{
	scanf("%d %d %d %d",&K,&X,&N,&M);
	satu[1] = 1;
	dua[2] = 1;
	FORN(i,3,K)
	{
		satu[i] = satu[i-2] + satu[i-1];
		dua[i] = dua[i-2] + dua[i-1];
	}
	satudua[3] = 1;
	FORN(i,4,K)
	{
		satudua[i] = satudua[i-1] + satudua[i-2];
		duadua[i] = duadua[i-1] + duadua[i-2];
		duasatu[i] = duasatu[i-1] + duasatu[i-2];
		if (i % 2 == 1)
		{
			++duadua[i];
		} else ++duasatu[i];
	}
	FORN(i,0,2) FORN(j,0,2) 
	{
		A = s[i];
		B = s[j];
		dfs(0,0);
	}
	puts("Happy new year!");
	return 0;
}