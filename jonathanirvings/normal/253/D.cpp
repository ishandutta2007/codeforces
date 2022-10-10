//Codeforces Round #154 (Div. 2)
//8 Dec 2012

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

int ada[405][405];
int peta[405][405];
vi sama[30];
int r,c,K;
LL risan = 0;
char x;

inline int jum(int a,int b,int c,int d)
{
	return (ada[c][d] - ada[c][b-1] - ada[a-1][d] + ada[a-1][b-1]);
}

int main()
{
	OPEN();
	scanf("%d %d %d",&r,&c,&K);
	REPN(i,r)
	{
		scanf("\n");
		REPN(j,c)
		{
			scanf("%c",&x);
			peta[i][j] = x - 'a';
			if (peta[i][j] == 0) ada[i][j] = 1;
			ada[i][j] += ada[i-1][j] + ada[i][j-1] - ada[i-1][j-1];
		}
	}
	REPN(i,r) FORN(k,i+1,r) 
	{
		REP(j,26) sama[j].clear();
		REPN(j,c) if(peta[i][j] == peta[k][j]) sama[peta[i][j]].pb(j);
		REP(j,26)
		{
			int sz = SIZE(sama[j]);
			int L = 0, R = 0;
			while (L < sz)
			{
				MAX(R,L+1);
				while (R < sz && jum(i,sama[j][L],k,sama[j][R]) <= K) ++R;
				--R;
				risan += (R - L);
				++L;
			}
			//debug("%d %d %c %lld\n",i,k,j + 'a',risan);
		}
	}
	cout << risan << endl;
	return 0;
}