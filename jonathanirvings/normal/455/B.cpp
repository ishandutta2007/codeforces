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
#include <assert.h>
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

vi dp[100005][3];
string data[100005];
int n,k;

int jahja(int L,int len,int R,int turns)
{
	if (L > R) return jahja(0,0,n-1,turns-1);
	if (turns == 0) return 0;
	int &ret = dp[L][turns][len];
	if (ret >= 0) return ret;
	ret = 0;
	int LL = L;
	int bef = -1;
	FORC(i,'a','z')
	{
		int ambil = -1;
		int RR = R;
		while (LL <= RR)
		{
			int MM = (LL + RR) >> 1;
			if (data[MM][len] >= i)
			{
				ambil = MM;
				RR = MM - 1;
			} else LL = MM + 1;
		}
		//printf("%c %d\n",i,ambil);
		if (ambil == -1) break;
		//printf("%c %d\n",i,ambil);
		if (data[ambil][len] != i) continue;
		//printf("%c %d\n",i,ambil);
		if (bef == -1) 
		{
			bef = ambil;
			continue;
		}
		//printf("%c %d\n",i,ambil);
		ret |= (1 - jahja(bef,len+1,ambil-1,turns));
		bef = ambil;
	}
	if (bef >= 0) 
		ret |= (1 - jahja(bef,len+1,R,turns));
	else ret = jahja(0,0,n-1,turns-1);
	//printf("====%d %d %d %d %d\n",L,len,R,turns,ret);
	return ret;
}

int main()
{
	scanf("%d %d",&n,&k);
	k = (k % 2 == 0 ? 2 : 1);
	REP(i,n) 
	{
		data[i] = GetString();
		data[i] += '0';
	}
	SORTA(data,n);
	REP(i,n)
	{
		REP(j,SIZE(data[i])+1)
		{
			dp[i][1].pb(-1);
			dp[i][2].pb(-1);
		}
	}
	int risan = jahja(0,0,n-1,k);
	puts(risan ? "First" : "Second");
	return 0;
}