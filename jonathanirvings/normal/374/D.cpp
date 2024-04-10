//Codeforces Round #220 (Div. 2)
//18 Dec 2013

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

int n,m,x,sz = 0;
int batas[1000005];
vi data;

struct BIT
{
	vi arr;
	void sz(int x) 
	{
		arr.resize(x+1);
		REP(i,x+1) arr[i] = 0;
	}
	void update(int x,int y)
	{
		int m = SIZE(arr);
		while (x < m)
		{
			arr[x] += y;
			x += (x & -x);
		}
	}
	int query(int x)
	{
		int ret = 0;
		while (x > 0)
		{
			ret += arr[x];
			x -= (x & -x);
		}
		return ret;
	}
};

BIT bit;

int main()
{
	scanf("%d %d",&n,&m);
	bit.sz(n+5);
	REP(i,m) scanf("%d",&batas[i]);
	REPN(turns,n)
	{
		scanf("%d",&x);
		if (x < 0)
		{
			REP(i,m)
			{
				if (batas[i] - i > sz) break;
				int L = 1;
				int R = turns;
				int x = batas[i] - i;
				int ret = -1;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (bit.query(M) >= x)
					{
						ret = M;
						R = M - 1;
					} else L = M + 1;
				}
				bit.update(ret,-1);
				--sz;
			}
		} else 
		{
			++sz;
			data.pb(x);
			bit.update(SIZE(data),1);
		}
		/*printf("%d:",turns);
		REP(i,SIZE(data)) if(bit.query(i+1)-bit.query(i) == 1) printf(" %d",data[i]);
		puts("");*/
	}
	if (sz == 0) printf("Poor stack!");
	REP(i,SIZE(data)) if(bit.query(i+1)-bit.query(i) == 1)
		printf("%d",data[i]);
	//for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	//	printf("%d",*it);
	puts("");
	return 0;
}